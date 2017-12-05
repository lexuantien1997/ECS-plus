#include "SpriteComponent.h"



SpriteComponent::SpriteComponent(string name):Component(name)
{
	sprite = NULL;
}

void SpriteComponent::setSprite(Sprite * s)
{
	sprite = s;
}

void SpriteComponent::initSpriteComponent(Sprite * s, Rect rect)
{
	sprite = s;
	this->rect = rect;
}

SpriteComponent::~SpriteComponent()
{

}
