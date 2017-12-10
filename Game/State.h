#ifndef STATE_H_
#define STATE_H_


#include "Transition.h"


class State
{
private:
	
	string name;

	vector<Transition*> transitions;

public:

	function<void()> enter;

	function<void(float dt)> update;

	function<void()> exit;

	void addTransition(Transition* transition);

	vector<Transition*> getTransitions() { return transitions; }

	string getName() { return name; }

	State(string _name, function<void()> _enter, function<void(float dt)> _update, function<void()> _exit);
	
	~State();
};


#endif
