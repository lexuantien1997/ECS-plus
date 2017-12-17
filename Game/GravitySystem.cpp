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
	for (Entity* entity : getEntities())
	{
		Gravity* gravity = entity->getComponent<Gravity>("gravity");
		Bound* bound = entity->getComponent<Bound>("bound");
		Velocity* velocity = entity->getComponent<Velocity>("velocity");
		float ancel = gravity->getAncel() * dt;
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
