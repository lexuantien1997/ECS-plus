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
		auto spriteComp = entity->getComponent<SpriteComponent>("sprite component");
		string name = entity->getName();
		if (name == "samus")
		{
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
				velocity->setVelocity(velocity->getVelocity().x, 0);
				bound->onGround = true;
			}
			velocity->setVelocity(Vector2f(0, velocity->getVelocity().y));
		}
		else if (name == "Skree")
		{
			vector<Entity*> entities = getEntities();
			Entity* samus=NULL;
			for (vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
				if ((*it)->getName() == "samus")
				{
					samus = *it;
					break;
				}
			Vector2f samusPos = samus->getComponent<Transform>("transform component")->getPosition();
			Vector2f samusSize = samus->getComponent<SpriteComponent>("sprite component")->getRect().size;
			Vector2f skreePos = transform->getPosition();
			int a = (samusPos.x - (skreePos.x + spriteComp->getRect().size.x));
			int b = (skreePos.x - (samusPos.x + samusSize.x));
			if (abs(a) < 20 || abs(b) < 20)
			{
				bound->follow = true;
			}
			if (bound->follow)
			{
				if (a > 0)
				{
					velocity->setVelocity(abs(velocity->getVelocity().x), velocity->getVelocity().y);
				}
				else
				{
					velocity->setVelocity(-abs(velocity->getVelocity().x), velocity->getVelocity().y);
				}
				skreePos.x += velocity->getVelocity().x * dt;
				skreePos.y -= velocity->getVelocity().y * dt;
				transform->setPosition(skreePos.x, skreePos.y);
				if (transform->getPosition().y < -110)
				{
					transform->setPosition(transform->getPosition().x, -110);
					velocity->setVelocity(0, 0);
					bound->onGround = true;
				}
			}
		}
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
