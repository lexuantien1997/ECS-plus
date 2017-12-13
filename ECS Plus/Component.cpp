#include "Component.h"



ECS::Component::Component(string _name):name(_name)
{

}




void ECS::Component::release()
{
		// step: Entity removes component
		entity = NULL;
		// delete class
		delete this;
}

ECS::Component::~Component()
{
	
}
