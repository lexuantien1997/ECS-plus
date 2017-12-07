#ifndef SPRITEMANAGER_H_
#define SPRITEMANAGER_H_
#include "../directx data/Include/d3dx9.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "../ECS Plus/Singleton.h"
#include "../rapid xml/rapidxml.hpp"
#include "../rapid xml/rapidxml_iterators.hpp"
#include "../rapid xml/rapidxml_print.hpp"
#include "../rapid xml/rapidxml_utils.hpp"
#include "Vector2.h"
#include "Transform.h"
#include "../Game/SpriteComponent.h"
#include <map>
#include "DeviceManager.h"

using namespace std;

class Resource;
class SpriteComponent;

class SpriteManager:public ECS::Singleton<SpriteManager>
{
private:
	LPD3DXSPRITE spriteHandler;

	map<string, Resource*> resourceInitialize;

public:

	void attachResource(Resource* resource);

	map<string, Resource*> getResourceInitialize() { return resourceInitialize; }


	Resource* find(string name);

	LPD3DXSPRITE getSpriteHandler();

	SpriteManager();

	~SpriteManager();

	void draw(SpriteComponent* spritecomp, Transform* transform);

	void begin();
	void end();
};


#endif // !SPRITEMANAGER_H_



