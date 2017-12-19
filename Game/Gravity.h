#ifndef GRAVITY_H_
#define GRAVITY_H_

#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

class Gravity :public ECS::Component
{
private:
	float ancel;
public:

	Gravity();
	
	~Gravity();
	float getAncel() { return ancel; }
	void flipAncel() { ancel *= -1; }
	void initGravity(float ancel);
};

#endif