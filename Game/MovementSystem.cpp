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
	for (Entity* entity : getEntities())
	{
		Transform* transform= entity->getComponent<Transform>("transform component");
		Bound* bound= entity->getComponent<Bound>("bound");
		Velocity* velocity = entity->getComponent<Velocity>("velocity");
	
		velocity->translating(0, bound->GRAVITY);

		transform->moving(velocity->getVelocity()*0.01f);

		// Kiểm tra nếu nhân vật đang di chuyển
		/*if (velocity->getVelocity().x!=0)
		{
			bound->vel_x = 1;
		}*/
		// Kiểm tra nếu nhân vật không di chuyển
		//else if (velocity->getVelocity().x == 0)
		//{
		//	bound->vel_x = 0;
		//	if (bound->onGround==true)
		//	{
		//		bound->turning = false;
		//	}

		//}

		if (transform->getPosition().y < -110)
		{
			transform->setPosition(transform->getPosition().x, -110);
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
