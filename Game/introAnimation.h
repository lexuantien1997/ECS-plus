#ifndef _INTROANIMATION_H_
#define _INTROANIMATION_H_

#include "../DirectX/Resource.h"
#include "../DirectX/Rect.h"
#include <list>

#include "../rapid xml/rapidxml.hpp"
#include "../rapid xml/rapidxml_iterators.hpp"
#include "../rapid xml/rapidxml_print.hpp"
#include "../rapid xml/rapidxml_utils.hpp"
using namespace rapidxml;

class introAnimation : public Resource
{
	string sourcePath;
public:
	int rectIndex;
	vector<Rect> rect;
	introAnimation(string name, string sourcePath);
	~introAnimation();

	// Inherit from `Resource`
	void loadResource();
};

#endif