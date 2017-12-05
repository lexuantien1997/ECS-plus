#ifndef VELOCITY_H_
#define VELOCITY_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

enum VelocityType
{
	normal = 0,
	plus = 1
};

class Velocity:public ECS::Component
{
private:
	Vector2f vNormal;
	Vector2f vPlus;
public:

	Velocity(string name);

	// ============ get - set velocity ==================
	void setVelocity(Vector2f &v, VelocityType t);
	void setVelocity(float offx, float offy, VelocityType t);

	void translating(Vector2f &v, VelocityType t);
	void translating(float vx, float vy, VelocityType t);

	Vector2f& getVelocity(VelocityType t);

	~Velocity();

	void initVelocity(Vector2f vNormal, Vector2f	vPlus);
};


#endif // !VELOCITY_H_


