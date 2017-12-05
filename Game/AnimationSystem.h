#ifndef ANIMATIONSYSTEM_H_
#define ANIMATIONSYSTEM_H_

#include "AnimationComponent.h"
#include "SpriteComponent.h"

class AnimationSystem:public ECS::TSystem
{
public:

	AnimationSystem();

	~AnimationSystem();

	void update(float dt);

	void render();

	void init();

	void loadResource();
};

#endif // !ANIMATIONSYSTEM_H_


