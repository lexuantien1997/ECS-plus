#ifndef ANIMATIONCOMPONENT_H_
#define ANIMATIONCOMPONENT_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

#include "Action.h"
#include "Animation.h"

class AnimationComponent:public ECS::Component
{
private:

	Animation* animation;

	Action currentAction;

public:

	AnimationComponent(string name);
	
	void initAnimationComponent(string startAction,string sourceName);

	~AnimationComponent();

};


#endif // !ANIMATIONCOMPONENT_H_

