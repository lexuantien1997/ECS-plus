#ifndef _MAPCOMPONENT_H_
#define _MAPCOMPONENT_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include <vector>
#include "../DirectX/TileMap.h"

using namespace ECS;

class MapComponent : public ECS::Component
{
public:
	TileMap *map;
	MapComponent(string name);
	void InitMapComponent();
	~MapComponent();
};

#endif // !_MAPCOMPONENT_H_

