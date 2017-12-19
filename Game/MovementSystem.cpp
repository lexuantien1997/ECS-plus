#include "MovementSystem.h"
#include "Bound.h"


MovementSystem::MovementSystem()
{

	requireComponent<Velocity>();
	requireComponent<Transform>();
	requireComponent<Bound>();
}


MovementSystem::~MovementSystem()
{
}

void MovementSystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		auto transform= entity->getComponent<Transform>();
		auto bound= entity->getComponent<Bound>();
		auto velocity = entity->getComponent<Velocity>();
	
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

