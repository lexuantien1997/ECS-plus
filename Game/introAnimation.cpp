#include "introAnimation.h"



introAnimation::introAnimation(string name, string sourcePath): Resource(name)
{
	this->sourcePath = sourcePath;
	rectIndex = 0;
}


introAnimation::~introAnimation()
{
}

void introAnimation::loadResource()
{
	file<> xmlFile(sourcePath.c_str());
	xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node()->first_node();

	while (node)
	{
		Rect r;
		r.left_top.x = atoi(node->first_attribute("left")->value());
		r.left_top.y = atoi(node->first_attribute("top")->value());
		r.size.x = atoi(node->first_attribute("width")->value());
		r.size.y = atoi(node->first_attribute("height")->value());
		this->rect.push_back(r);
		node = node->next_sibling();
	}

}
