#include "StateComponent.h"



StateComponent::StateComponent()
{
	
}

void StateComponent::addState(State * state)
{
	states.emplace(state->getName(), state);
}

void StateComponent::removeState(State * state)
{
	states.erase(state->getName());
}

State * StateComponent::findState(string name)
{
	auto it = states.find(name);
	if (it != states.end()) 
		return it->second;
	return NULL;
}

void StateComponent::changeState(State * state)
{
	if (state!=NULL)
	{
		if (currentState->exit != NULL)
		{
			currentState->exit();
		}

		previousState = currentState;
		currentState = state;

		if (currentState->enter != NULL) 
		{
			currentState->enter();
		}
	}
}


void StateComponent::initStateComponent(string _stateName)
{
	this->stateName = _stateName;
}


StateComponent::~StateComponent()
{
}
