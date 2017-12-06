#include "AnimationSystem.h"
#include "../DirectX/Rect.h"


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

}

void AnimationSystem::onUpdate(Entity * entity)
{

	auto animationComp = entity->getComponent<AnimationComponent>("animation component");
	auto currentAction = animationComp->getCurrentAction();

	// stateTime += dt;
	stateTime += 0.01f;
	if (stateTime >= currentAction->getFrameDuration())
	{
		currentAction->increasing();
		stateTime = 0;
	}

	if (currentAction->getCurrentRect() >= currentAction->getAction_Size())
		currentAction->setCurrentRect(0);

	auto spriteComp = entity->getComponent<SpriteComponent>("sprite component");

	spriteComp->setRect(currentAction->getActionRect().at(currentAction->getCurrentRect()));
	

}

void AnimationSystem::onActionChanged(Entity * entity, string name)
{
	auto animationComp = entity->getComponent<AnimationComponent>("animation component");
	
	animationComp->setCurrentAction(animationComp->getAniamtion()->findAction(name));
	
	auto samus_sprite = static_cast<Sprite*>(SpriteManager::getInstance()->find("samus_aran.png"));

	auto spriteComp = entity->getComponent<SpriteComponent>("sprite component");

	spriteComp->setSprite(samus_sprite);

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

	onUpdate(e->e1);
}
