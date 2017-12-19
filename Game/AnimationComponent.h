#ifndef ANIMATIONCOMPONENT_H_
#define ANIMATIONCOMPONENT_H_

#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

#include "Action.h"
#include "Animation.h"

class AnimationComponent:public ECS::Component
{
private:

	Animation* animation;

	Action* currentAction;
	Action* previousAction;

public:

	AnimationComponent();
	
	void initAnimationComponent(string startAction,string sourceName);

	Animation* getAniamtion() { return animation; }

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

