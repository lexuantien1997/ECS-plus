#include "Bound.h"




Bound::Bound(string name):Component(name)
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
	 GRAVITY = -50.0f;
	 JUMP_1 = 700.0F;
	 vel_x = 0;
	 dem = 0;
}

Bound::~Bound()
{
}
