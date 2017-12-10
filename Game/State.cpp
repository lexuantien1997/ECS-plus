#include "State.h"



void State::addTransition(Transition * transition)
{
	transitions.push_back(transition);
}


State::State(string _name, function<void()> _enter, function<void(float dt)> _update, function<void()> _exit)
{
	this->name = _name;
	this->update = _update;
	this->enter = _enter;
	this->exit = _exit;
}

State::~State()
{
}
