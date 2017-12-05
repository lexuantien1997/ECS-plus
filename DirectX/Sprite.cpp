#include "Sprite.h"




Sprite::~Sprite()
{
}

void Sprite::loadResource()
{
	loadFromFile();
}

HRESULT Sprite::loadFromFile()
{
	HRESULT	result;

	// information of image
	D3DXIMAGE_INFO info;

	result = D3DXGetImageInfoFromFileA(source.c_str(), &info);

	if (result != D3D_OK)
		return result;

	LPDIRECT3DDEVICE9 device = DeviceManager::getInstance()->getDevice();
	
	result = D3DXCreateTextureFromFileExA(
		device,
		source.c_str(),
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		nullptr,
		&this->texture);

	// Set size of image
	setSize(Vector2f(info.Width, info.Height));

	return result;
}

void Sprite::setSize(Vector2f s)
{
	size.x = s.x;
	size.y = s.y;
}

Sprite::Sprite(string name, string source, D3DXCOLOR transparentColor) :Resource(name)
{
	this->source = source;
	this->transparentColor = transparentColor;
	size = Vector2f(0, 0);
}

