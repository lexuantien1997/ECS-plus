#include "Transition.h"



Transition::Transition(string from,string to, function<bool()> _condition)
{
	this->from = from;
	this->to = to;
	this->condition = _condition;
}

Transition::~Transition()
{
}
