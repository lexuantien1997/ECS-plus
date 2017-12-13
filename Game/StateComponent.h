#ifndef STATECOMPONENT_H_
#define STATECOMPONENT_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "State.h"


class StateComponent:public ECS::Component
{
private:
	string stateName;
	State* currentState;
	State* previousState;
	map<string, State*> states;
public:

	StateComponent(string name);

	void addState(State* state);

	void removeState(State* state);

	State* findState(string name);

	void changeState(State* state);

	State* getCurrentState() { return currentState; }

	State* getPreviousState() { return previousState; }

	void initStateComponent(string _stateName);

	void serCurrentState(State* state) { currentState = state; }

	void serPreviousState(State* state) { previousState = state; }

	~StateComponent();
};

#endif