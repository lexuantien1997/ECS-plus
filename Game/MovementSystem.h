#ifndef MOVEMENTSYSTEM_H_
#define MOVEMENTSYSTEM_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

#include "Velocity.h"
#include "CollisionComponent.h"
#include <sstream> 
class MovementSystem:public ECS::TSystem
{
public:

	MovementSystem();

	~MovementSystem();

	void update(float dt);

	void render();

	void init();

	void loadResource();
};


#endif // !MOVEMENTSYSTEM_H_


