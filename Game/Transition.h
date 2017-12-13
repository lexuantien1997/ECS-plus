#ifndef TRANSITION_H_
#define TRANSITION_H_

using namespace std;

#include <functional>
#include <iostream>
#include <vector>

class Transition
{
private:

	string from,to;

public:
	
	Transition(string from,string to, function<bool()> _condition);
	
	function<bool()> condition;
	
	string getName() { return to; }

	~Transition();
};


#endif // !TRANSITION_H_


