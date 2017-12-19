#ifndef _MAPSYSTEM_H_
#define _MAPSYSTEM_H_

#include "Mess.h"
#include "SpriteComponent.h"
#include "MapComponent.h"

class MapSystem : public ECS::System
{
public:
	MapSystem();
	void update(float dt);

	void render();

	void init();

	~MapSystem();
};
#endif // !_MAPSYSTEM_H_


