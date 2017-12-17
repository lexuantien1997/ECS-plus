#ifndef _INTROSCENE_H_
#define _INTROSCENE_H_

#include "../ECS Plus/Scene.h"
#include "RenderingSystem.h"
#include "InputSystem.h"
#include "AnimationSystem.h"

#include "SpriteComponent.h"
#include "AnimationComponent.h"

using namespace ECS;

class IntroScene : public Scene
{
	RenderingSystem renderSystem;
	InputSystem inputSystem;
	AnimationSystem animationSystem = AnimationSystem(&inputSystem);
public:
	IntroScene(string name);
	~IntroScene();

	void update(float dt);

	void init();

	void render();

	void release();
};

#endif