#ifndef _START_GAMEOVER_SCENE_H_
#define _START_GAMEOVER_SCENE_H_

#include "../ECS Plus/Scene.h"
#include "RenderingSystem.h"
#include "InputSystem.h"
#include "SpriteComponent.h"

class Start_GameOver_Scene : public Scene
{
	RenderingSystem renderSystem;
	InputSystem inputSystem;
public:
	Start_GameOver_Scene(string name);
	~Start_GameOver_Scene();

	void update(float dt);

	void init();

	void render();

	void release();
};

#endif