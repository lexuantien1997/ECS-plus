#include "EnemiesAnimation.h"



EnemiesAnimation::EnemiesAnimation(string name, string source):Resource(name)
{
	sourcePath = source;
	rectIndex = 0;
}

void EnemiesAnimation::loadResource()
{
	file<> xmlFile(sourcePath.c_str());
	xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node()->first_node();
	string name = node->first_attribute("name")->value();
	vector<Rect> listRect;
	node = node->first_node("Sprite");
	while (node)
	{
		Rect r;
		r.left_top.x = atoi(node->first_attribute("x")->value());
		r.left_top.y = atoi(node->first_attribute("y")->value());
		r.size.x = atoi(node->first_attribute("w")->value());
		r.size.y = atoi(node->first_attribute("h")->value());
		listRect.push_back(r);
		node = node->next_sibling();
	}
	mapEnemiesAnimation.emplace(name, listRect);
}


EnemiesAnimation::~EnemiesAnimation()
{
}
