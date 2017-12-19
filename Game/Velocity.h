#ifndef VELOCITY_H_
#define VELOCITY_H_

#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"


class Velocity:public ECS::Component
{
private:
	Vector2f vNormal;
public:

	Velocity();

	// ============ get - set velocity ==================
	void setVelocity(Vector2f &v);
	void setVelocity(float offx, float offy);

	void translating(Vector2f &v);
	void translating(float vx, float vy);

	Vector2f& getVelocity();

	~Velocity();

	void initVelocity(Vector2f vNormal);
};


#endif // !VELOCITY_H_


