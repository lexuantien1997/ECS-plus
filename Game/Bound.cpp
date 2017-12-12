#include "Bound.h"




Bound::Bound(string name,bool hasGravity):Component(name)
{
	 this->onGround = true;
	 this->runningRight = true;
	 this->no_state = true;
	 this->shoot_up = false;
	 this->shoot_straight = false;
	 this->rolling = false;
	 this->turning = false;
	 SPEED = 500.f;
	 HEIGHT = 700;
	 if(hasGravity)
		 GRAVITY = -50.0f;
	 else 
		 GRAVITY = 0.f;
	 JUMP_1 = 700.0F;
	 vel_x = 0;
	 dem = 0;
}

Bound::~Bound()
{
}
