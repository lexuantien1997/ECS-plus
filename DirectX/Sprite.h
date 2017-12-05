#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "../directx data/Include/d3d9.h"
#include "Resource.h"
#include "SpriteManager.h"
#include "Vector2.h"

class Sprite:public Resource
{
private:

	string source; // the path of sprite

	LPDIRECT3DTEXTURE9 texture; // place save image of directx

	D3DXCOLOR transparentColor; // the transparent color

	Vector2f size; // the size [ width & height ] of sprite

public:
	~Sprite();

	// Inherit from `Resource`
	void loadResource(); 
	
	HRESULT loadFromFile();

	D3DXCOLOR getColor() { return transparentColor; }

	void setSize(Vector2f s);

	Vector2f getSize() { return size; }

	Sprite(string name, string source, D3DXCOLOR transparentColor = D3DCOLOR_RGBA(255, 255, 255,255));

	LPDIRECT3DTEXTURE9 getTexture() {return texture; }

	void setsource(string path) { source = path; }
};

#endif // !SPRITE_H_



