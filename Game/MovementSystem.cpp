#include "MovementSystem.h"
#include "Bound.h"


MovementSystem::MovementSystem()
{
	Requires<Require<Velocity, Transform,Bound>>();
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
		auto bound= entity->getComponent<Bound>("bound");
		auto velocity = entity->getComponent<Velocity>("velocity");
	
		velocity->translating(0, bound->GRAVITY);

		transform->moving(velocity->getVelocity()*0.01f);

		if (transform->getPosition().y < -80)
		{
			transform->setPosition(transform->getPosition().x, -80);
			velocity->setVelocity(velocity->getVelocity().x,0);
			bound->onGround = true;
		}
		velocity->setVelocity(Vector2f(0, velocity->getVelocity().y));

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
