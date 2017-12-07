#include "GravitySystem.h"



GravitySystem::GravitySystem()
{
	Requires<Require<Velocity,Gravity,Bound>>();
	Excludes<Exclude<>>();
}


GravitySystem::~GravitySystem()
{

}

void GravitySystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		auto gravity = entity->getComponent<Gravity>("gravity");
		auto bound = entity->getComponent<Bound>("bound");
		auto velocity = entity->getComponent<Velocity>("velocity");
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

void GravitySystem::loadResource()
{
}
