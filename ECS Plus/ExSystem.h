#ifndef EXAMPLE_SYSTEM_H_
#define EXAMPLE_SYSTEM_H_

#include "_ECS_Header.h"
#include "ExComponent.h"
using namespace ECS;


class TMovementSystem :public TSystem
{
public:
	TMovementSystem()
	{
		// Mốn di chuyển thì chỉ cần tới vận tốc và vị trí lúc trước
		this->Requires<Require<TTransform, TVelocity>>();

		this->Excludes<ECS::Exclude<>>();

	}

	void update(float dt)
	{
		for (auto entity : getEntities())
		{
			// Lấy các component ra dùng
			auto transform = entity->getComponent<TTransform>("transform");
			auto velocity = entity->getComponent<TVelocity>("velocity");

			// dùng công thức v=s*t để di chuyển
			velocity->set(IVector2f(velocity->getVelocityX()*dt, velocity->getVelocityY()*dt));

			// s = s+v
			transform->move(velocity->getVelocityX(), velocity->getVelocityY());
		}
	}

	void render()
	{

	}

	void init()
	{

	}

	void loadResource()
	{

	}

};

class TRenderingSystem :public TSystem
{
public:
	TRenderingSystem()
	{
		// Render chỉ cần hình, và vị trí để vẽ 
		this->Requires<Require<TSprite, TTransform>>();

		this->Excludes<ECS::Exclude<>>();
	}

	void update(float dt)
	{

	}

	void render()
	{
		for (auto entity : getEntities())
		{
			// Lấy các component ra dùng
			auto transform = entity->getComponent<TTransform>("transform");
			auto sprite = entity->getComponent<TSprite>("sprite");

			// vẽ hình
			sprite->draw(transform->getPosition());
		}
	}

	void init()
	{

	}

	void loadResource()
	{

	}

};

#endif // !EXAMPLE_SYSTEM_H_

