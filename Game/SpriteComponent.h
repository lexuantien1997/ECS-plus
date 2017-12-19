#ifndef SPRITECOMPONENT_H_
#define SPRITECOMPONENT_H_

#include "../DirectX/_DIRECTX_Header.h"
#include "../High perfomance ECS/ECS_Header.h"

#include "../DirectX/Rect.h"

class Sprite;
class Rect;

class SpriteComponent :public ECS::Component
{
private:
	Sprite* sprite;
	Rect rect;
public:

	SpriteComponent();

	Sprite* getSprite() { return sprite; }

	void setSprite(Sprite* s);

	void initSpriteComponent(Sprite* s, Rect rect);

	~SpriteComponent();

	void setRect(Rect r) { rect = r; }

	Rect getRect() { return rect; }
};


#endif // !SPRITECOMPONENT_H_




