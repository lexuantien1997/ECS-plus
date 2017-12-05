#include "AnimationSystem.h"




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
	for (auto entity : getEntities())
	{
		auto animation = entity->getComponent<AnimationComponent>("animation component");
		auto currentAction = animation->getCurrentAction();

		stateTime += dt;

		if (stateTime >= currentAction.getFrameDuration())
		{
			currentAction.increasing();
			stateTime = 0;
		}

		if (currentAction.getCurrentRect() >= currentAction.getAction_Size())
			currentAction.setCurrentRect(0.f);

	}
		
}

void AnimationSystem::onActionChanged(Entity * e, string name)
{

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


}
