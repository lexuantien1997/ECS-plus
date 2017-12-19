#ifndef PLAYINGSCENE_H_
#define PLAYINGSCENE_H_

// data
#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

// Components
#include "Velocity.h"
#include "SpriteComponent.h"
#include "AnimationComponent.h"
#include "PlayerControllable.h"
#include "Bound.h"
#include "Gravity.h"
#include "StateComponent.h"
#include "MapComponent.h"

// Systems
#include "RenderingSystem.h"
#include "InputSystem.h"
#include "MovementSystem.h"
#include "AnimationSystem.h"
#include "StateSystem.h"
#include "MapSystem.h"
using namespace ECS;

class PlayingScene:public ECS::Scene
{
private:
	RenderingSystem renderSystem;
	InputSystem inputSystem;
	MovementSystem movementSystem;
	StateSystem stateSystem;
	MapSystem mapSystem;
	AnimationSystem animationSystem;
public:

	PlayingScene(string name);
	
	~PlayingScene();

	void update(float dt);

	void init();

	void render();

	void release();

	void initSystem();

	void initEntity();
};

#endif // !PLAYINGSCENE_H_



