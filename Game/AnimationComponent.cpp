#include "AnimationComponent.h"






AnimationComponent::AnimationComponent(string name) :Component(name)
{
	
}

void AnimationComponent::initAnimationComponent(string startAction, string sourceName)
{
	animation = static_cast<Animation*>(SpriteManager::getInstance()->find(sourceName));

	currentAction = animation->findAction(startAction);

	// change image:
}

AnimationComponent::~AnimationComponent()
{

}
