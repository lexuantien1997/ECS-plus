#ifndef _MAPSYSTEM_H_
#define _MAPSYSTEM_H_

#include "Mess.h"
#include "SpriteComponent.h"
#include "MapComponent.h"

class MapSystem : public ECS::TSystem
{
public:
	MapSystem();
	void update(float dt);

	void render();

	void init();

	void loadResource();
	~MapSystem();
};
#endif // !_MAPSYSTEM_H_


