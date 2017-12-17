#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(string name) :Component(name)
{
	
}

void AnimationComponent::initAnimationComponent(string startAction, string sourceName)
{
	if (sourceName.find("intro") != string::npos)
	{
		this->introAnima = static_cast<introAnimation*>(SpriteManager::getInstance()->find(sourceName));
	}
	else
	{
	animation = static_cast<Animation*>(SpriteManager::getInstance()->find(sourceName));
	currentAction = animation->findAction(startAction);
	previousAction = currentAction;
	}
	// change image:
}

AnimationComponent::~AnimationComponent()
{

}
