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
	else if (sourceName.find("samus") != string::npos)
	{
		animation = static_cast<Animation*>(SpriteManager::getInstance()->find(sourceName));
		currentAction = animation->findAction(startAction);
		previousAction = currentAction;
	}
	else if (sourceName.find("enemies") != string::npos)
	{
		this->enemiesAnimation = static_cast<EnemiesAnimation*>(SpriteManager::getInstance()->find(sourceName));
	}
	// change image:
}

AnimationComponent::~AnimationComponent()
{

}
