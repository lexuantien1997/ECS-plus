#ifndef GRAVITYSYSTEM_H_
#define GRAVITYSYSTEM_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

#include "Velocity.h"
#include "Gravity.h"
#include "Bound.h"

class GravitySystem:public ECS::TSystem
{
private:
	bool antiGravity = false;
public:

	GravitySystem();

	~GravitySystem();

	void update(float dt);

	void render();

	void init();

	void loadResource();
};

#endif
