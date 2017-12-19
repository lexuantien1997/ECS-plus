#include "AnimationSystem.h"
#include "../DirectX/Rect.h"
#include "Bound.h"

AnimationSystem::AnimationSystem(Server* p_server):Client(p_server)
{
	Requires<Require<SpriteComponent, AnimationComponent>>();
	Excludes<Exclude<>>();
}


AnimationSystem::~AnimationSystem()
{
}

void AnimationSystem::update(float dt)
{
	for (Entity* entity :getEntities())
	{
		if (entity->getName() == "intro")
		{
			stateTime = stateTime + 0.01;
			if (stateTime >= 0.04)
			{
				stateTime = 0.0;
				
				introAnimation* introAni = entity->getComponent<AnimationComponent>("animation component")->getIntroAnimation();
				 
				SpriteComponent* spriteComp = entity->getComponent<SpriteComponent>("sprite component");
				vector<Rect> rects = introAni->rect;
				Rect r = rects.at(++(introAni->rectIndex)%rects.size());
				spriteComp->setRect(r);
			}
		}
		else if (entity->getName() == "Skree")
		{// dùng duration là sai, duration cố định
				EnemiesAnimation* enemyAni = entity->getComponent<AnimationComponent>("animation component")->getEnemiesAnimation();
				enemyAni->setDuration(enemyAni->getDuration() + 0.01);
			if (enemyAni->getDuration() >= 0.04)
			{
				enemyAni->setDuration(0.0);


				SpriteComponent* spriteComp = entity->getComponent<SpriteComponent>("sprite component");
				Transform* transform = entity->getComponent<Transform>("transform component");
				map<string, vector<Rect>>::iterator it = enemyAni->mapEnemiesAnimation.find(entity->getName());

				if (enemyAni->rectIndex % it->second.size() == 0)
				{
					Vector2f v = transform->getPosition();
					transform->setPosition(v.x + 4, v.y);
				}
				else if (enemyAni->rectIndex % it->second.size() == 2)
				{
					Vector2f v = transform->getPosition();
					transform->setPosition(v.x - 4, v.y);
				}
				
				if (it != enemyAni->mapEnemiesAnimation.end())
				{
					Rect r = it->second.at(++(enemyAni->rectIndex) % it->second.size());
					spriteComp->setRect(r);
				}
			}
		}
		else if (entity->getName() == "samus")
		{
			AnimationComponent* animationComp = entity->getComponent<AnimationComponent>("animation component");
			Bound* bound = entity->getComponent<Bound>("bound");

			//// Đang nhảy
			//if (bound->onGround==false)
			//{
			//	// nhảy + đưa súng lên trên
			//	if (bound->shoot_up==true)
			//	{
			//		onActionChanged(entity, "jump_shoot_up");
			//	}
			//	// nhảy bắn súng ngang
			//	else if (bound->shoot_straight == true)
			//	{
			//		onActionChanged(entity, "jump_shoot");
			//	}
			//	else if (bound->turning == true)
			//	{
			//		onActionChanged(entity, "turning");
			//	}
			//	// chỉ nhảy
			//	else if(bound->shoot_up == false && bound->shoot_straight == false)
			//	{

			//		onActionChanged(entity, "jump");
			//		
			//	}
			//	onUpdate(entity); 
			//	return;
			//}

			//// [ Đang ở dưới đất ]
			//else if (bound->onGround == true)
			//{

			//	// Không di chuyển => Đứng
			//	if (bound->vel_x == 0)
			//	{
			//		// Đứng mà đưa súng lên trời
			//		if (bound->shoot_up == true)
			//		{
			//			onActionChanged(entity, "stand_shoot_up");
			//		}
			//		else if (bound->rolling==1)
			//		{
			//			onActionChanged(entity, "rolling");
			//		}
			//		else
			//		{
			//			onActionChanged(entity, "stand");
			//		}

			//	}

			//	// Đang di chuyển
			//	else if (bound->vel_x != 0)
			//	{

			//		// Di chuyển mà đưa súng lên trời => chạy
			//		if (bound->shoot_up == true)
			//		{
			//			onActionChanged(entity, "run_shoot_up");
			//		}
			//		else if (bound->rolling)
			//		{
			//			onActionChanged(entity, "rolling");
			//		}
			//		else
			//		{				
			//			onActionChanged(entity, "run");
			//		}
			//	}
			//	onUpdate(entity);
			//	return;
			//}	
			onUpdate(entity);
		}
	}
	
}

void AnimationSystem::onUpdate(Entity * entity)
{
	AnimationComponent* animationComp = entity->getComponent<AnimationComponent>("animation component");
	Action* currentAction = animationComp->getCurrentAction();

	// stateTime += dt;
	stateTime += 0.01f;
	if (stateTime >= currentAction->getFrameDuration())
	{
		currentAction->increasing();
		stateTime = 0;
	}

	if (currentAction->getCurrentRect() >= currentAction->getAction_Size())
		currentAction->setCurrentRect(0);

	SpriteComponent* spriteComp = entity->getComponent<SpriteComponent>("sprite component");
	
	spriteComp->setRect(currentAction->getActionRect().at(currentAction->getCurrentRect()));
}

void AnimationSystem::onActionChanged(Entity * entity, string name)
{
	AnimationComponent* animationComp = entity->getComponent<AnimationComponent>("animation component");

	if (animationComp->getCurrentAction()->getName() == name)
		return;

	animationComp->setPreviousAction(animationComp->getCurrentAction());
	animationComp->setCurrentAction(animationComp->getAniamtion()->findAction(name));
	
	/*auto samus_sprite = static_cast<Sprite*>(SpriteManager::getInstance()->find("samus_aran.png"));
	auto bound = entity->getComponent<Bound>("bound");
	auto spriteComp = entity->getComponent<SpriteComponent>("sprite component");

	spriteComp->setSprite(samus_sprite);*/
	
}

void AnimationSystem::render()
{
}

void AnimationSystem::init()
{

}

void AnimationSystem::loadResource()
{

}

void AnimationSystem::MessageSentHandler(const Server * p_sender, void * p_parameter)
{
	eMess* e = (eMess*)p_parameter;

	// change action:
	if (e->from!=e->to)
	{
		onActionChanged(e->e1, e->to);
	}
	
}
