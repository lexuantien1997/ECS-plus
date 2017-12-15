#include "Entity.h"

#include "GameWorld.h"




ECS::Entity::Entity(string _name,GameWorld* s)
{
	name = _name;
	gameWorld = s;
	id = s->getId();
	s->increaseid();
	alive = true;
	//systems.resize(maxComponents);
}

ECS::Entity::Entity(string name, int id)
{
	this->name = name;
	this->id = id;
}

ECS::Entity::~Entity()
{
}
