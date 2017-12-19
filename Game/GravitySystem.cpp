#include "GravitySystem.h"



GravitySystem::GravitySystem()
{
	requireComponent<Velocity>();
	requireComponent<Gravity>();
	requireComponent<Bound>();
}


GravitySystem::~GravitySystem()
{

}

void GravitySystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		auto gravity = entity->getComponent<Gravity>();
		auto bound = entity->getComponent<Bound>();
		auto velocity = entity->getComponent<Velocity>();
		auto ancel = gravity->getAncel() * dt;
		if (antiGravity)
		{
			ancel = -ancel;
		}
		velocity->translating(0, ancel);
		if (velocity->getVelocity().y <= 0)
		{
			antiGravity = true;
			velocity->setVelocity(0, 0);
		}
	}
}

void GravitySystem::render()
{
}

void GravitySystem::init()
{
}

