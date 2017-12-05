#ifndef SPRITECOMPONENT_H_
#define SPRITECOMPONENT_H_

#include "../DirectX/_DIRECTX_Header.h"
#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/Rect.h"

class Sprite;
struct Rect;

class SpriteComponent :public ECS::Component
{
private:
	Sprite* sprite;
	Rect rect;
public:

	SpriteComponent(string name);

	Sprite* getSprite() { return sprite; }

	void setSprite(Sprite* s);

	void initSpriteComponent(Sprite* s, Rect rect);

	~SpriteComponent();

	Rect getRect() { return rect; }
};


#endif // !SPRITECOMPONENT_H_




