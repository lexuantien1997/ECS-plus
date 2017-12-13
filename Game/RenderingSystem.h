#ifndef RENDERINGSYSTEM_H_
#define RENDERINGSYSTEM_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "SpriteComponent.h"

class RenderingSystem:public ECS::TSystem
{

public:

	RenderingSystem();

	~RenderingSystem();

	void update(float dt);

	void render();

	void init();

	void loadResource();

};

#endif // !RENDERINGSYSTEM_H_



