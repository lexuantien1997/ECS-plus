#include "MapComponent.h"

MapComponent::MapComponent(string name) : Component(name)
{
	
}

void MapComponent::InitMapComponent()
{
	this->map = static_cast<TileMap*>(SpriteManager::getInstance()->find("untitled.tmx"));
	quadtreeDivision.createQuadtreeFromFile("../resources/map/untitledQuadtree.xml", map);
}

MapComponent::~MapComponent()
{
	if (!this->map) delete map;
}