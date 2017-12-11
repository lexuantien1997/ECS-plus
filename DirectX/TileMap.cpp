#include "TileMap.h"



TileMap::TileMap(std::string name, string source):Resource(name)
{
	this->source = source;
}



void TileMap::loadResource()
{
	file<> xmlFile(source.c_str());
	xml_document<> doc;

	doc.parse<0>(xmlFile.data());

	//
	// point to first node and read data
	//
	xml_node<> *node = doc.first_node("map");
	_column = atoi(node->first_attribute("width")->value());
	_row = atoi(node->first_attribute("height")->value());
	_size.x = atoi(node->first_attribute("tilewidth")->value());
	_size.y = atoi(node->first_attribute("tileheight")->value());
	node = node->first_node("layer")->first_node("data");
	char* _data = node->value();

	value = (int**)malloc((_column * _row * sizeof(int)));

	char * split = ", \t\n\r";
	char * context = NULL;
	char * item = strtok_s(_data, split, &context);

	for (int i = 0; i < _row; i++)
	{
		value[i] = new int[_column];
		
		for (int j = 0; j < _column; j++)
		{
			value[i][j] = atoi(item);
			//if (value[i][j] != 0)
			//{
			//	//Tile temp(_tileWidth * j, _tileHeight * i, _tileWidth, _tileHeight);
			//	Tile temp(((data[i][j] - 1) % 11) * 16, ((data[i][j] - 1) / 11) * 16, _tileWidth, _tileHeight);
			//	_tileMap[i][j] = temp;
			//}
			item = strtok_s(NULL, split, &context);
		}
	}

	//
	// get object of map
	// this object use to set collision
	//

	node = node->parent()->parent(); // this one is return to the root node which is the map node
	node = node->first_node("objectgroup");
	int numberObject = atoi(node->last_node("object")->first_attribute("id")->value()); // point to last node to get the total number of object
	node = node->first_node(); // point back to first node
							   //obj = new Object[numberObject];
	for (int i = 0; i < numberObject; i++)
	{
		Rect *obj;
		int x = atoi(node->first_attribute("x")->value());
		int y = atoi(node->first_attribute("y")->value());
		float width = atoi(node->first_attribute("width")->value());
		float height = atoi(node->first_attribute("height")->value());
		Vector2f position;
		position.x = x;
		position.y = -y;
		Vector2f dimension;
		dimension.x = width;
		dimension.y = height;

		obj = new Rect(position, dimension);
		_ground.push_back(obj);
		//Collision::listObject.push_back(obj);

		node = node->next_sibling();
	}
}

TileMap::~TileMap()
{
	for (int i = 0; i < _row; i++)
		delete value[i];
	delete value;
}
