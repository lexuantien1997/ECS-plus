#ifndef RENDERINGSYSTEM_H_
#define RENDERINGSYSTEM_H_

#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "SpriteComponent.h"

class RenderingSystem:public ECS::System
{

public:

	RenderingSystem();

	~RenderingSystem();

	void update(float dt);

	void render();

	void init();

};

#endif // !RENDERINGSYSTEM_H_



