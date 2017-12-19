#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "../High perfomance ECS/ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include <map>

#include "Action.h"
#include "../rapid xml/rapidxml.hpp"
#include "../rapid xml/rapidxml_iterators.hpp"
#include "../rapid xml/rapidxml_print.hpp"
#include "../rapid xml/rapidxml_utils.hpp"
using namespace rapidxml;
using namespace std;
class Resource;
class Action;

class Animation:public Resource
{

private:
	
	string sourcePath;
	// animation có nhiều trạng thái
	map<string, Action*> actions;

public:
	
	Animation(string name,string sourcePath);

	~Animation();

	Action* findAction(string name);

	// Inherit from `Resource`
	void loadResource();
	
};

#endif // !ANIMATION_H_



