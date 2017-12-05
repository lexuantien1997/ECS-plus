#ifndef INPUTSYSTEM_H_
#define INPUTSYSTEM_H_

#include "AnimationComponent.h"
#include "PlayerControllable.h"

class InputSystem:public ECS::TSystem
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



