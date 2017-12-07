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

		// Kiểm tra nếu nhân vật đang di chuyển
		if (velocity->getVelocity().x!=0)
		{
			bound->vel_x = 1;
		}
		// Kiểm tra nếu nhân vật không di chuyển
		else if (velocity->getVelocity().x == 0)
		{
			bound->vel_x = 0;
		}

		if (transform->getPosition().y >200)
		{
			transform->setPosition(transform->getPosition().x, 200);
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
