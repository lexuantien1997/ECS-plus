#include "MovementSystem.h"



MovementSystem::MovementSystem()
{
	Requires<Require<Velocity, Transform>>();
	Excludes<Exclude<>>();
}


MovementSystem::~MovementSystem()
{
}

void MovementSystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		auto transform= entity->getComponent<Transform>("transform component");

		auto velocity = entity->getComponent<Velocity>("velocity");

		transform->moving(velocity->getVelocity(VelocityType::normal)*0.01f);

		transform->moving(velocity->getVelocity(VelocityType::plus)*0.01f);
	}
}

void MovementSystem::render()
{

}

void MovementSystem::init()
{

}

void MovementSystem::loadResource()
{

}
