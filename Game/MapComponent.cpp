#include "MapComponent.h"

MapComponent::MapComponent()
{
	
}

void MapComponent::InitMapComponent()
{
	this->map = static_cast<TileMap*>(SpriteManager::getInstance()->find("untitled.tmx"));
}

MapComponent::~MapComponent()
{
	if (!this->map) delete map;
}