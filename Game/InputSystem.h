#ifndef INPUTSYSTEM_H_
#define INPUTSYSTEM_H_

#include "AnimationComponent.h"
#include "PlayerControllable.h"

class InputSystem:public ECS::System
{
public:

	InputSystem();

	~InputSystem();

	void update(float dt);

	void render();

	void init();

};

#endif // !INPUTSYSTEM_H_



