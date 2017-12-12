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
	std::ostringstream ss;
	for (auto entity : getEntities())
	{
		auto transform= entity->getComponent<Transform>("transform component");
		auto bound= entity->getComponent<Bound>("bound");
		auto velocity = entity->getComponent<Velocity>("velocity");
		auto collision = entity->getComponent<CollisionComponent>("collision component");
		//velocity->translating(0, bound->GRAVITY);

		//transform->moving(velocity->getVelocity()*0.01f);
		//setPosition(position.x + offset.x, position.y + offset.y);
		// Kiểm tra nếu nhân vật đang di chuyển
		if (velocity->getVelocity().x!=0)
		{
			if ((collision->dirCantMove[LEFT] || collision->dirCantMove[RIGHT]))
				velocity->setVelocity(0, velocity->getVelocity().y);
			transform->setPosition(transform->getPosition().x + velocity->getVelocity().x*collision->timeToCollision, transform->getPosition().y);
			//this->_position.setX(this->_position.getX() + this->_velocity.getX()*delta);
			if ((collision->dirCantMove[UP] || collision->dirCantMove[DOWN])) {
				if (collision->dirCantMove[UP]) {
					velocity->setVelocity(velocity->getVelocity().x, 0);
					transform->setPosition(transform->getPosition().x, transform->getPosition().y + (velocity->getVelocity().y + bound->GRAVITY)*collision->timeToCollision);
				//	this->_position.setY(this->_position.getY() + (this->_velocity.getY() + gravity)*delta);
				}
			}
			else {
				transform->setPosition(transform->getPosition().x, transform->getPosition().y + (velocity->getVelocity().y + bound->GRAVITY)*collision->timeToCollision);
			}
		}
		ss << transform->getPosition().x << " " << transform->getPosition().y << " " << velocity->getVelocity().x << " " << velocity->getVelocity().y << endl;
		OutputDebugStringA(ss.str().c_str());
		collision->dirCantMove.clear();
		collision->dirCantMove.insert(std::pair<Direction, bool>(DOWN, false));
		collision->dirCantMove.insert(std::pair<Direction, bool>(UP, false));
		collision->dirCantMove.insert(std::pair<Direction, bool>(LEFT, false));
		collision->dirCantMove.insert(std::pair<Direction, bool>(RIGHT, false));
		 //Kiểm tra nếu nhân vật không di chuyển
		/*else if (velocity->getVelocity().x == 0)
		{
			bound->vel_x = 0;
			if (bound->onGround==true)
			{
				bound->turning = false;
			}

		}*/

		/*if (transform->getPosition().y < -80)
		{
			transform->setPosition(transform->getPosition().x, -80);
			velocity->setVelocity(velocity->getVelocity().x,0);
			bound->onGround = true;
		}*/
		
		//velocity->setVelocity(Vector2f(0, velocity->getVelocity().y));

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
