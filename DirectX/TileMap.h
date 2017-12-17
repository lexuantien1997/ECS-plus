#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include "../directx data/Include/d3d9.h"
#include "Resource.h"
#include "Vector2.h"
#include <vector>
#include "Rect.h"
#include "../rapid xml/rapidxml.hpp"
#include "../rapid xml/rapidxml_iterators.hpp"
#include "../rapid xml/rapidxml_print.hpp"
#include "../rapid xml/rapidxml_utils.hpp"
#include "../ECS Plus/Entity.h"
#include "Transform.h"
#include "../Game/SpriteComponent.h"
#include "list"

using namespace std;
using namespace rapidxml;
#define TILESIZE 16
class TileMap : public Resource
{
	string source; // the path of map file
	int _column, _row;
	Vector2f _size;
	vector<Rect*> _ground;
public:
	int **value;
	map<int, Entity*> mapTile;
	list<Entity*> entityInQuadtree;

	TileMap(string name, string sourcePath);
	int getColumn() { return _column; }
	int getRow() { return _row; }
	Vector2f getSize() { return _size; }
	void loadResource();
	~TileMap();
};

#endif // !_TILEMAP_H_



