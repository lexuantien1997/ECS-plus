#ifndef PLAYERCONTROLLABLE_H_
#define PLAYERCONTROLLABLE_H_
#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

class PlayerControllable:public ECS::Component
{
public:

	struct Controls
	{
		// default Key controls
		Controls() :UP(DIK_UP), DOWN(DIK_DOWN), LEFT(DIK_LEFT), RIGHT(DIK_RIGHT),JUMP(DIK_Z),SHOOT(DIK_X) { }

		// change key controls
		Controls(int u, int d, int l, int r,int j,int s) :UP(u), DOWN(d), LEFT(l), RIGHT(r), JUMP(j), SHOOT(s) { }

		// all directions:
		int UP, DOWN, LEFT, RIGHT,JUMP,SHOOT;

	} controls;

	PlayerControllable(string name);

	~PlayerControllable();


};


#endif // !PLAYERCONTROLLABLE_H_

