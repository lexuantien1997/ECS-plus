#include "AnimationComponent.h"

AnimationComponent::AnimationComponent() 
{
	
}

void AnimationComponent::initAnimationComponent(string startAction, string sourceName)
{
	animation = static_cast<Animation*>(SpriteManager::getInstance()->find(sourceName));

	currentAction = animation->findAction(startAction);
	previousAction = currentAction;
	// change image:
}

AnimationComponent::~AnimationComponent()
{

}
