#include "Velocity.h"



Velocity::Velocity()
{
}


Velocity::~Velocity()
{
}


// =============================================================

void Velocity::setVelocity(Vector2f & vel)
{
	setVelocity(vel.x, vel.y);
}

void Velocity::setVelocity(float offx, float offy)
{

	vNormal.x = offx;
	vNormal.y = offy;

}

void Velocity::translating(Vector2f & vel)
{

	setVelocity(vNormal.x + vel.x, vNormal.y + vel.y);

}

void Velocity::translating(float vx, float vy)
{

	setVelocity(vNormal.x + vx, vNormal.y + vy);

}

Vector2f& Velocity::getVelocity()
{
	return vNormal;
}

void Velocity::initVelocity(Vector2f vNormal)
{
	this->vNormal = vNormal;

}
