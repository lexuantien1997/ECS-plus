#ifndef _QNODE_H_
#define _QNODE_H_

#include <list>
#include "../ECS Plus/Entity.h"
#include "../Game/SpriteComponent.h"
#include "../rapid xml/rapidxml.hpp"
#include "../rapid xml/rapidxml_iterators.hpp"
#include "../rapid xml/rapidxml_print.hpp"
#include "../rapid xml/rapidxml_utils.hpp"
#include "Rect.h"
#include "Vector2.h"
#include "TileMap.h"
using namespace ECS;
using namespace std;
using namespace rapidxml;

class QuadtreeDivision;

class QNode
{
public:
	QNode **Node;
	int NodeID;
	Rect bound;
	list<Entity*> objects;
	QNode();
	bool isContain(Entity *obj);
	void Split();
	void Insert(Entity *obj);
	QNode(int NodeID, Rect r);
	~QNode();
};


class QuadtreeDivision
{
public:
	xml_document<> doc;
	xml_node<>*xml_rootNode;
	QNode *rootQuadtree;
	string fileOutput;

	map<int, QNode*> mapNode;
	map<int, Entity*> mapEntityTile;
	
	list<Entity*> background;
	list<Entity*> objects; // chưa code

	void preExport(string tmxFile);
	void BuildTree(QNode *node);
	void Export(QNode*, xml_node<>*);
	void endExport(string fileOutput);
	void release(QNode*);
	QuadtreeDivision() { rootQuadtree = new QNode(0, Rect(Vector2f(0, 0), Vector2f(80 * 16, 80 * 16)));}

	void createQuadtreeFromFile(string sourcePath, TileMap* map);
	void readNodeFromFile(xml_node<>*, TileMap *);
	void linkNodes();
};

#endif 