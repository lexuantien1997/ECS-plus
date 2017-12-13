#ifndef BOUND_H_
#define BOUND_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

class Bound :public ECS::Component
{
public:

	float SPEED ;
	float HEIGHT;
	float GRAVITY ;
	float JUMP_1 ;
	int dem;

	float prevPosY;

	bool onGround;
	bool runningRight;
	bool shoot_up;
	bool shoot_straight;
	bool no_state;
	bool rolling;
	bool turning;
	int vel_x;

	Bound(string name);
	
	~Bound();
};

#endif // !BOUND_H_