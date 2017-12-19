#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "../High perfomance ECS/ECS_Header.h"

class Resource
{
private:
	string name;
public:

	string getName() { return name; }

	virtual void loadResource()=0;

	Resource(string _name);

	~Resource();
};


#endif // !RESOURCE_H_


