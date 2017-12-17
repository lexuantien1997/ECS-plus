#include "QNode.h"
TileMap *tm ;
QNode::QNode()
{
}

QNode::QNode(int NodeID, Rect r)
{
	this->NodeID = NodeID;
	this->bound.left_top.x = r.left_top.x;
	this->bound.left_top.y = r.left_top.y;
	this->bound.size.x = r.size.x;
	this->bound.size.y = r.size.y;
}



bool QNode::isContain(Entity *obj)
{
	Rect r = obj->getComponent<SpriteComponent>("sprite component")->getRect();
	Vector2f p = obj->getComponent<Transform>("transform component")->getPosition();
	return !(this->bound.left_top.x >= p.x + r.size.x ||
		this->bound.left_top.x + this->bound.size.x <= p.x ||
		this->bound.left_top.y <= p.y - r.size.y ||
		this->bound.left_top.y - this->bound.size.y >= p.y);
}

void QNode::Split()
{
	Node = new QNode*[4];
	int i = 1;
	Node[0] = new QNode(NodeID * 10 + i++, Rect(Vector2f(bound.left_top.x, -bound.left_top.y), Vector2f(bound.size.x / 2, bound.size.y / 2)));
	Node[1] = new QNode(NodeID * 10 + i++, Rect(Vector2f(bound.left_top.x + bound.size.x / 2, -bound.left_top.y), Vector2f(bound.size.x / 2, bound.size.y / 2)));
	Node[2] = new QNode(NodeID * 10 + i++, Rect(Vector2f(bound.left_top.x, -bound.left_top.y - bound.size.y / 2), Vector2f(bound.size.x / 2, bound.size.y / 2)));
	Node[3] = new QNode(NodeID * 10 + i++, Rect(Vector2f(bound.left_top.x + bound.size.x / 2, -bound.left_top.y - bound.size.y / 2), Vector2f(bound.size.x / 2, bound.size.y / 2)));
}

void QNode::Insert(Entity *obj)
{
	if (this->NodeID == 11 && obj->getId() == 193)
	{
		int m = 0;
	}
	if (Node)
	{
		if (Node[0]->isContain(obj))
			Node[0]->Insert(obj);
		if (Node[1]->isContain(obj))
			Node[1]->Insert(obj);
		if (Node[2]->isContain(obj))
			Node[2]->Insert(obj);
		if (Node[3]->isContain(obj))
			Node[3]->Insert(obj);

		return;
	}
	this->objects.emplace_back(obj);

	if (/*objects.size() > 20 && *//*left + */bound.size.x > 160)
	{
		Split();
		while (objects.size() != 0)
		{
			if (Node[0]->isContain(objects.front()))
				Node[0]->Insert(objects.front());
			if (Node[1]->isContain(objects.front()))
				Node[1]->Insert(objects.front());
			if (Node[2]->isContain(objects.front()))
				Node[2]->Insert(objects.front());
			if (Node[3]->isContain(objects.front()))
				Node[3]->Insert(objects.front());

			objects.pop_front();
		}
	}
}


QNode::~QNode()
{
	if (Node) delete Node;
}

void QuadtreeDivision::preExport(string tmxFile)
{
	file<> xmlFile(tmxFile.c_str());
	xml_document<> xml;
	xml.parse<0>(xmlFile.data());
	xml_node<> *node = xml.first_node("map");
	int _column = atoi(node->first_attribute("width")->value());
	int _row = atoi(node->first_attribute("height")->value());
	int _size_x = atoi(node->first_attribute("tilewidth")->value());
	int _size_y = atoi(node->first_attribute("tileheight")->value());
	node = node->first_node("layer")->first_node("data");
	char* _data = node->value();

	int **value = (int**)malloc((_column * _row * sizeof(int)));

	char * split = ", \t\n\r";
	char * context = NULL;
	char * item = strtok_s(_data, split, &context);

	int id = 1;
	
	for (int i = 0; i < _row; i++)
	{
		value[i] = new int[_column];

		for (int j = 0; j < _column; j++)
		{
			value[i][j] = atoi(item);
			if (value[i][j] != 0)
			{
				//	//Tile temp(_tileWidth * j, _tileHeight * i, _tileWidth, _tileHeight);
				//	Tile temp(((data[i][j] - 1) % 11) * 16, ((data[i][j] - 1) / 11) * 16, _tileWidth, _tileHeight);
				//	_tileMap[i][j] = temp;
				//Entity *o = new Entity("tile", id++, value[i][j], j * 16, i * 16, 16, 16);
				//string name = "tile" + to_string(id);
				Entity *e = new Entity("tile" + to_string(id), id);
				Transform *t = e->addComponent<Transform>("transform component");
				SpriteComponent *s = e->addComponent<SpriteComponent>("sprite component");
				s->initSpriteComponent(NULL, Rect(Vector2f(((value[i][j] - 1) % 11) * 16, ((value[i][j] - 1) / 11) * 16), Vector2f(16, 16)));
				t->initTransform(Vector2f(j * 16, -i * 16), Vector2f(0, 0), Vector2f(0, 0), NULL);
				background.emplace_back(e);
				id++;
			}
			item = strtok_s(NULL, split, &context);
		}
	}
	id = 1;
	node = node->parent()->parent(); // this one is return to the root node which is the map node
	node = node->first_node("objectgroup");
	int numberObject = atoi(node->last_node("object")->first_attribute("id")->value()); // point to last node to get the total number of object
	node = node->first_node(); // point back to first node
							   //obj = new Object[numberObject];
	while(node)
	{
		//Rect *obj;
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

		Entity *e = new Entity("ground" + to_string(id), id);
		Transform *t = e->addComponent<Transform>("transform component");
		SpriteComponent *s = e->addComponent<SpriteComponent>("sprite component");
		s->initSpriteComponent(NULL, Rect(Vector2f(x, -y), Vector2f(width, height)));
		t->initTransform(Vector2f(x, -y), Vector2f(0, 0), Vector2f(0, 0), NULL);

		//obj = new Rect(position, dimension);
		objects.push_back(e);
		id++;
		//Collision::listObject.push_back(obj);

		node = node->next_sibling();
	}

	xml_node<> *declaration = doc.allocate_node(node_declaration);
	declaration->append_attribute(doc.allocate_attribute("version", "1.0"));
	declaration->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
	doc.append_node(declaration);

	xml_rootNode = doc.allocate_node(node_element, "Quadtree");
	doc.append_node(xml_rootNode);
}

void QuadtreeDivision::BuildTree(QNode *quadtree)
{
	for (auto i = background.begin(); i != background.end(); ++i)
	{
		quadtree->Insert(*i);
	}
	for (auto i = objects.begin(); i != objects.end(); ++i)
	{
		quadtree->Insert(*i);
	}
}

void QuadtreeDivision::Export(QNode* node, xml_node<>* xmlnode)
{
	xml_node<>* child;
	child = doc.allocate_node(node_element, "QNode");
	char * NodeIDStr = doc.allocate_string(std::to_string(node->NodeID).c_str());
	child->append_attribute(doc.allocate_attribute("id", NodeIDStr));
	char * leftStr = doc.allocate_string(std::to_string(node->bound.left_top.x).c_str());
	child->append_attribute(doc.allocate_attribute("x", leftStr));
	char * topStr = doc.allocate_string(std::to_string(node->bound.left_top.y).c_str());
	child->append_attribute(doc.allocate_attribute("y", topStr));
	char * widthStr = doc.allocate_string(std::to_string(node->bound.size.x).c_str());
	child->append_attribute(doc.allocate_attribute("width", widthStr));
	char * heightStr = doc.allocate_string(std::to_string(node->bound.size.y).c_str());
	child->append_attribute(doc.allocate_attribute("height", heightStr));
	xmlnode->append_node(child);

	/*if (Node[0])
	Node[0]->Export(doc, node);*/
	if (node->Node)
	{
		Export(node->Node[0], child);
		Export(node->Node[1], child);
		Export(node->Node[2], child);
		Export(node->Node[3], child);

		return;
	}
	//cout << NodeID << ": \n";
	for (auto i = node->objects.begin(); i != node->objects.end(); ++i)
	{
		char * IDStr = doc.allocate_string(std::to_string((*i)->getId()).c_str());
		if((*i)->getName().find("tile") != string::npos)
			child->append_attribute(doc.allocate_attribute("tileid", IDStr));
		else
			child->append_attribute(doc.allocate_attribute("groundid", IDStr));
	}
}

void QuadtreeDivision::endExport(string fileOutput)
{
	string xml_as_string;
	rapidxml::print(std::back_inserter(xml_as_string), doc);

	// Save to file
	ofstream file_stored(fileOutput);
	file_stored << doc;
	file_stored.close();
	doc.clear();
}

void QuadtreeDivision::release(QNode *node)
{
	if (!node->Node) return;
	release(node->Node[0]);
	release(node->Node[1]);
	release(node->Node[2]);
	release(node->Node[3]);

	for (int i = 0; i < 4; i++)
	{
		delete node->Node[i];
		node->Node[i] = nullptr;
	}
}

void QuadtreeDivision::createQuadtreeFromFile(string sourcePath, TileMap *map)
{
	file<> xmlfile(sourcePath.c_str());
	xml_document<> xml;
	xml.parse<0>(xmlfile.data());

	xml_node<>* xmlrootNode = xml.first_node("Quadtree");
	xml_node<>* xmlfirstQNode = xmlrootNode->first_node("QNode");
	xml_node<>* id1 = xmlfirstQNode->first_node("QNode");
	xml_node<>* id2 = id1->next_sibling();
	int i = atoi(id2->first_attribute("id")->value());
	readNodeFromFile(xmlfirstQNode, map);
	int x = 1;
	linkNodes();
}

void QuadtreeDivision::readNodeFromFile(xml_node<>*xmlNode, TileMap* map)
{
	if (xmlNode->first_node("QNode"))
	{
	xml_node<>*firstNode = xmlNode->first_node("QNode");
	xml_node<>* secondNode = firstNode->next_sibling();
	xml_node<>* thirdNode = secondNode->next_sibling();
	xml_node<>* fourthNode = thirdNode->next_sibling();
	readNodeFromFile(firstNode, map);
	readNodeFromFile(secondNode, map);
	readNodeFromFile(thirdNode, map);
	readNodeFromFile(fourthNode, map);
	}

	xml_attribute<> *at = xmlNode->first_attribute("id");
	int id = atoi(at->value());

	Rect r;
	r.left_top.x = atoi(at->next_attribute("x")->value());
	r.left_top.y = atoi(at->next_attribute("y")->value());
	r.size.x = atoi(at->next_attribute("width")->value());
	r.size.y = atoi(at->next_attribute("height")->value());

	QNode* node = new QNode(id, r);

	at = at->next_attribute("tileid");
	while (at)
	{
		int _id = atoi(at->value());
		Entity* e = map->mapTile.find(_id)->second;
		
		
		node->objects.emplace_back(e);
		mapEntityTile.emplace(_id, e);
		at = at->next_attribute("tileid");
	}
	at = xmlNode->first_attribute("groundid");
	while (at)
	{
		int _id = atoi(at->value());
		Entity* e = map->mapGround.find(_id)->second;


		node->objects.emplace_back(e);
		mapEntityTile.emplace(_id, e);
		at = at->next_attribute("groundid");
	}
	mapNode.emplace(id, node);
}

void QuadtreeDivision::linkNodes()
{
	rootQuadtree = nullptr;
	for (map<int, QNode*>::iterator it = mapNode.begin(); it != mapNode.end(); ++it)
	{
		if (it->first == 0)
			rootQuadtree = it->second;
		else
		{
			int parentID = it->first / 10;
			QNode* parentNode = mapNode[parentID];
			if (!parentNode->Node)
				parentNode->Node = new QNode*[4];
			int childID = it->first % 10;
			switch (childID)
			{
			case 1:
				parentNode->Node[0] = it->second;
				break;
			case 2:
				parentNode->Node[1] = it->second;
				break;
			case 3:
				parentNode->Node[2] = it->second;
				break;
			case 4:
				parentNode->Node[3] = it->second;
				break;
			default:
				break;
			}

		}
	}
}

list<Entity*> QuadtreeDivision::listObjectInViewport(Rect viewport, QNode *node)
{
	if (node == this->rootQuadtree)
		this->objects.clear();
	if (!node->Node)
	{
		bool b = viewport.intersect(node->bound);
		if (b)
		{
			if (node->objects.size() > 0)
			{
				for (list<Entity*>::iterator it = node->objects.begin(); it != node->objects.end(); ++it)
				{
					if ((*it)->getName().find("tile") != string::npos)
					{
						list<Entity*>::iterator i = std::find(this->background.begin(), this->background.end(), (*it));
						if (i != background.end())
							continue;
						else
						{
							this->background.emplace_back((*it));
						}
					}
					else
					{
						list<Entity*>::iterator i = std::find(this->objects.begin(), this->objects.end(), (*it));
						if (i != objects.end())
							continue;
						else
						{
							this->objects.emplace_back((*it));
						}
					}		
				}
			}
		}
	}
	else
	{
		if (viewport.intersect(node->Node[0]->bound))
			listObjectInViewport(viewport, node->Node[0]);
		if (viewport.intersect(node->Node[1]->bound))
			listObjectInViewport(viewport, node->Node[1]);
		if (viewport.intersect(node->Node[2]->bound))
			listObjectInViewport(viewport, node->Node[2]);
		if (viewport.intersect(node->Node[3]->bound))
			listObjectInViewport(viewport, node->Node[3]);
	}
	return background;
}
