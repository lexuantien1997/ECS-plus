#include "Bound.h"




Bound::Bound()
{
	 this->onGround = true;
	 this->runningRight = true;
	 this->no_state = true;
	 this->shoot_up = false;
	 this->shoot_straight = false;
	 this->rolling = false;
	 this->turning = false;

	 SPEED = 150.f;
	 HEIGHT = 400.0f;
	 GRAVITY = -9.8f;
	 JUMP_1 = 350.0f;
	 vel_x = 0;
	 dem = 0;
}

Bound::~Bound()
{
}
