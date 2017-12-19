#include "AnimationSystem.h"
#include "../DirectX/Rect.h"
#include "Bound.h"

AnimationSystem::AnimationSystem()
{
	requireComponent<SpriteComponent>();
	requireComponent<AnimationComponent>();
}


AnimationSystem::~AnimationSystem()
{
}

void AnimationSystem::update(float dt)
{
	for (auto entity :getEntities())
	{
		auto animationComp = entity->getComponent<AnimationComponent>();
		auto currentAction = animationComp->getCurrentAction();

		stateTime += dt;
		if (stateTime >= currentAction->getFrameDuration())
		{
			currentAction->increasing();
			stateTime = 0;
		}

		if (currentAction->getCurrentRect() >= currentAction->getAction_Size())
			currentAction->setCurrentRect(0);

		auto spriteComp = entity->getComponent<SpriteComponent>();

		spriteComp->setRect(currentAction->getActionRect().at(currentAction->getCurrentRect()));
		
	}
	
}

void AnimationSystem::onUpdate(Entity * entity,float dt)
{
	auto animationComp = entity->getComponent<AnimationComponent>();
	auto currentAction = animationComp->getCurrentAction();

	// stateTime += dt;
	stateTime += dt;
	if (stateTime >= currentAction->getFrameDuration())
	{
		currentAction->increasing();
		stateTime = 0;
	}

	if (currentAction->getCurrentRect() >= currentAction->getAction_Size())
		currentAction->setCurrentRect(0);

	auto spriteComp = entity->getComponent<SpriteComponent>();
	
	spriteComp->setRect(currentAction->getActionRect().at(currentAction->getCurrentRect()));
}

void AnimationSystem::onActionChanged(Entity * entity, string name)
{
	auto animationComp = entity->getComponent<AnimationComponent>();

	if (animationComp->getCurrentAction()->getName() == name)
		return;

	animationComp->setPreviousAction(animationComp->getCurrentAction());
	animationComp->setCurrentAction(animationComp->getAniamtion()->findAction(name));
	
	auto samus_sprite = static_cast<Sprite*>(SpriteManager::getInstance()->find("samus_aran.png"));
	auto bound = entity->getComponent<Bound>();
	auto spriteComp = entity->getComponent<SpriteComponent>();

	spriteComp->setSprite(samus_sprite);
	
}

void AnimationSystem::render()
{
}

void AnimationSystem::init()
{

}


