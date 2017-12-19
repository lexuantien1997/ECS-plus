#ifndef STATESYSTEM_H_
#define STATESYSTEM_H_

#include "StateComponent.h"

class StateSystem:public ECS::System
{
public:

	void update(float dt);

	void render();

	void init();

	void init(string stateName);
	
	StateSystem();

	~StateSystem();
};

#endif