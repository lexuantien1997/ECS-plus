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

using namespace std;
using namespace rapidxml;

class TileMap : public Resource
{
	string source; // the path of map file
	int _column, _row;
	Vector2f _size;
	vector<Rect*> _ground;
public:
	int **value;
	TileMap(string name, string sourcePath);
	int getColumn() { return _column; }
	int getRow() { return _row; }
	Vector2f getSize() { return _size; }
	void loadResource();
	~TileMap();
};

#endif // !_TILEMAP_H_



