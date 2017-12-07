#include "Gravity.h"



Gravity::Gravity(string name):Component(name)
{

}


Gravity::~Gravity()
{
}

void Gravity::initGravity(float ancel)
{
	this->ancel = ancel;
}
