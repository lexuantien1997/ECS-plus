#ifndef _ENEMIES_ANIMATION_H_
#define _ENEMIES_ANIMATION_H_

#include "../DirectX/Resource.h"
#include "../DirectX/Rect.h"

#include "../rapid xml/rapidxml.hpp"
#include "../rapid xml/rapidxml_iterators.hpp"
#include "../rapid xml/rapidxml_print.hpp"
#include "../rapid xml/rapidxml_utils.hpp"


using namespace rapidxml;

class EnemiesAnimation : public Resource
{
	string sourcePath;
	float duration;
public:
	int rectIndex;
	map<string, vector<Rect>> mapEnemiesAnimation;
	EnemiesAnimation(string fileName, string sourcePath);
	~EnemiesAnimation();
	float getDuration() { return duration; }
	void setDuration(float d) { duration = d; }
	void loadResource();
};

#endif