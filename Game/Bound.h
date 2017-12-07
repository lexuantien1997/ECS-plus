#ifndef BOUND_H_
#define BOUND_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

class Bound :public ECS::Component
{
public:

	const float SPEED = 500.f;
	const float HEIGHT = 1200;
	const float GRAVITY = 50.0f;
	const float JUMP_1 = 700.0F;


	float prevPosY;

	bool onGround;
	bool runningRight;
	bool shoot_up;
	bool shoot_straight;
	bool no_state;
	bool rolling;
	int vel_x;

	Bound(string name);
	
	~Bound();
};

#endif // !BOUND_H_