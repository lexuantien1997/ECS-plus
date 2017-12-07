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
	 vel_x = 0;
}

Bound::~Bound()
{
}
