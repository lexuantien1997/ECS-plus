#ifndef BOUND_H_
#define BOUND_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

class Bound :public ECS::Component
{
public:

	const float SPEED = 1000;

	Bound(string name);
	
	~Bound();
};

#endif // !BOUND_H_