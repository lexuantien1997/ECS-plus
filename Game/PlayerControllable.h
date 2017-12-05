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
		Controls() :up(DIK_UP), down(DIK_DOWN), left(DIK_LEFT), right(DIK_RIGHT),jump(DIK_Z),shoot(DIK_X) { }

		// change key controls
		Controls(int u, int d, int l, int r,int j,int s) :up(u), down(d), left(l), right(r),jump(j),shoot(s) { }

		// all directions:
		int up, down, left, right,jump,shoot;

	} controls;

	PlayerControllable(string name);

	~PlayerControllable();


};


#endif // !PLAYERCONTROLLABLE_H_

