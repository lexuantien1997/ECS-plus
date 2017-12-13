#ifndef INPUTSYSTEM_H_
#define INPUTSYSTEM_H_

#include "AnimationComponent.h"
#include "PlayerControllable.h"
#include "Mess.h"
#include "Server.h"

class InputSystem:public ECS::TSystem,public Server
{
public:


	InputSystem();

	~InputSystem();

	void update(float dt);

	void render();

	void init();

	void loadResource();
};

#endif // !INPUTSYSTEM_H_



