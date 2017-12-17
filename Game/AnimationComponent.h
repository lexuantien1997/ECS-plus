#ifndef ANIMATIONCOMPONENT_H_
#define ANIMATIONCOMPONENT_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

#include "Action.h"
#include "Animation.h"
#include "introAnimation.h"

class AnimationComponent:public ECS::Component
{
private:

	Animation* animation;
	introAnimation *introAnima;
	Action* currentAction;
	Action* previousAction;

public:

	AnimationComponent(string name);
	
	void initAnimationComponent(string startAction,string sourceName);

	Animation* getAniamtion() { return animation; }
	introAnimation* getIntroAnimation() { return introAnima; }

	Action* getCurrentAction() {
		return currentAction;
	}

	Action* getPreviousAction() {
		return previousAction;
	}


	void setCurrentAction(Action* action) { currentAction = action; }

	void setPreviousAction(Action* action) { previousAction = action; }
	~AnimationComponent();

};


#endif // !ANIMATIONCOMPONENT_H_

