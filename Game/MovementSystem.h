#ifndef MOVEMENTSYSTEM_H_
#define MOVEMENTSYSTEM_H_

#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

#include "Velocity.h"

class MovementSystem:public ECS::System
{
public:

	MovementSystem();

	~MovementSystem();

	void update(float dt);

	void render();

	void init();
};


#endif // !MOVEMENTSYSTEM_H_


