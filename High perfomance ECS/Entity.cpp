#include "Entity.h"
#include "GameWorld.h"

void ECS::Entity::replace(ComponentId index, Component * comp)
{
	components[index] = comp;
}

void ECS::Entity::addComponent(ComponentId index, Component * comp)
{
	// add
	components[index] = comp;
	// set pos
	compBits[index] = true;
}

void ECS::Entity::removeEntity()
{
	world->removeEntity(this);
}

void ECS::Entity::active()
{
	this->isActive = true;
}

void ECS::Entity::refresh()
{
	world->refreshEntity(this);
}

void ECS::Entity::deactive()
{
	this->isActive = false;
}

bool ECS::Entity::checkActive()
{
	return this->isActive;
}

void ECS::Entity::setUniqueId(long int uniqueId)
{
	this->uniqueId = uniqueId;
}

void ECS::Entity::addSystemBits(bitset<BITSIZE> sysBits)
{
	this->sysBits |= sysBits;
}

void ECS::Entity::removeSystemBits(bitset<BITSIZE> sysBits)
{
	this->sysBits &= ~sysBits;
}

bitset<BITSIZE> ECS::Entity::getSystemsBits()
{
	return sysBits;
}

bitset<BITSIZE> ECS::Entity::getCompBits()
{
	return compBits;
}

long int ECS::Entity::getUniqueId()
{
	return uniqueId;
}

void ECS::Entity::removeAllComponent()
{
	components.clear();
	compBits.set(0);
}

ECS::EntityName ECS::Entity::getEntityName()
{
	return name;
}

ECS::Entity::Entity(EntityName _counter, GameWorld* world)
{
	name = _counter;
	this->world = world;
}

ECS::Entity::Entity(GameWorld * world, EntityName _counter)
{
	name = _counter;
	this->world = world;
}

ECS::Entity::~Entity()
{
	world = NULL;
	removeAllComponent();
}
