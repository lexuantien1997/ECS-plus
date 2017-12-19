#ifndef _MAPCOMPONENT_H_
#define _MAPCOMPONENT_H_

#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include <vector>

using namespace ECS;

class MapComponent : public ECS::Component
{
public:
	TileMap *map;
	MapComponent();
	void InitMapComponent();
	~MapComponent();
};

#endif // !_MAPCOMPONENT_H_

