#ifndef PLAYINGSCENE_H_
#define PLAYINGSCENE_H_

#include "../ECS Plus/Scene.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "../ECS Plus/_ECS_Header.h"
#include "Velocity.h"
#include "SpriteComponent.h"
#include "RenderingSystem.h"
#include "InputSystem.h"
#include "AnimationComponent.h"
#include "PlayerControllable.h"
#include "MovementSystem.h"
#include "Bound.h"
#include "AnimationSystem.h"
#include "Gravity.h"
using namespace ECS;

class PlayingScene:public ECS::Scene
{
private:
	RenderingSystem renderSystem;
	InputSystem inputSystem;
	MovementSystem movementSystem;
	AnimationSystem animationSystem=AnimationSystem(&inputSystem);
public:

	PlayingScene(string name);
	
	~PlayingScene();

	void update(float dt);

	void init();

	void render();

	void release();
};

#endif // !PLAYINGSCENE_H_



