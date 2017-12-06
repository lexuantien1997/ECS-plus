#include "Animation.h"



Animation::Animation(string name, string sourcePath):Resource(name)
{
	this->sourcePath = sourcePath;
}


Animation::~Animation()
{

}

Action* Animation::findAction(string name)
{
	map<string, Action*>::iterator it = actions.find(name);
	if (it != actions.end())
	{
		return actions[name];
	}

}

void Animation::loadResource()
{
	file<> xmlFile(sourcePath.c_str());
	xml_document<> doc;
	
	doc.parse<0>(xmlFile.data());
	
	xml_node<> *node=doc.first_node()->first_node();
	
	while (node != NULL)
	{
		string name = node->first_attribute("name")->value();
		string spritePath = node->first_attribute("s")->value();
		float duration = stof(node->first_attribute("duration")->value());

		xml_node<> *child = node->first_node();
	
		vector<Rect> rects;

		while (child != NULL)
		{
			float left= stof(child->first_attribute("x")->value());
	
			float top = stof(child->first_attribute("y")->value());

			float width = stof(child->first_attribute("w")->value());

			float height = stof(child->first_attribute("h")->value());

			rects.push_back(Rect(left, top, width, height));

			child = child->next_sibling();
		}
	
		Action* action =new Action(name, spritePath, rects,duration);

		actions.insert(pair < string, Action*>(name, action));

		node = node->next_sibling();

	}

}

