#ifndef GRAVITYSYSTEM_H_
#define GRAVITYSYSTEM_H_

#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

#include "Velocity.h"
#include "Gravity.h"
#include "Bound.h"

class GravitySystem:public ECS::System
{
private:
	bool antiGravity = false;
public:

	GravitySystem();

	~GravitySystem();

	void update(float dt);

	void render();

	void init();

};

#endif
