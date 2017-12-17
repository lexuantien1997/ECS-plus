#include "MapComponent.h"

MapComponent::MapComponent(string name) : Component(name)
{
	
}

void MapComponent::InitMapComponent()
{
	this->map = static_cast<TileMap*>(SpriteManager::getInstance()->find("untitled.tmx"));
	quadtreeDivision.createQuadtreeFromFile("../resources/map/untitledQuadtree.xml", map);
	// move this elsewhere
	map->entityInQuadtree = quadtreeDivision.listObjectInViewport(Rect(0, 0, 320, 240), quadtreeDivision.rootQuadtree);
	for (auto it = quadtreeDivision.objects.begin(); it != quadtreeDivision.objects.end(); ++it)
	{
		int id = (*it)->getId();
		Entity* e = map->mapGround.find(id)->second;
		Rect *r = new Rect(e->getComponent<SpriteComponent>("sprite component")->getRect());
		map->_ground.push_back(r);
	}
}

MapComponent::~MapComponent()
{
	if (!this->map) delete map;
}