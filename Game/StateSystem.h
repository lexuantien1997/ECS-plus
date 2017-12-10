#ifndef STATESYSTEM_H_
#define STATESYSTEM_H_

#include "StateComponent.h"

class StateSystem:public ECS::TSystem
{
public:

	void update(float dt);

	void render();

	void init();

	void init(string stateName);

	void loadResource();
	
	StateSystem();

	~StateSystem();
};

#endif