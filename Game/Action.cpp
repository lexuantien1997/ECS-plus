#include "Action.h"





Action::Action(string name, string path, vector<Rect> rects,float duration)
{
	this->name = name;
	this->spritePath = path;
	this->action_rect = rects;
	this->action_size = action_rect.size();
	this->current_rect = 0;
	this->duration = duration;
}

string Action::getName()
{
	return name;
}

string Action::getSpritePath()
{
	return spritePath;
}

vector<Rect> Action::getActionRect()
{
	return action_rect;
}

Action::~Action()
{

}
