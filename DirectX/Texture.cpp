#include "Texture.h"



Texture::Texture()
{
	
}

HRESULT Texture::loadFromFile(const char* source, D3DXCOLOR transparentcolor)
{
	HRESULT			result;
		result = D3DXGetImageInfoFromFileA(source, &this->info);
	if (result != D3D_OK)
		return result;
	LPDIRECT3DDEVICE9 device = DeviceManager::getInstance()->getDevice();
//	SpriteManager::getInstance()->getSpriteHandler()->GetDevice(&device);

	result = D3DXCreateTextureFromFileExA(
		device,
		source,
		this->info.Width,
		this->info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentcolor,
		&this->info,
		nullptr,
		&this->texture);

	transparentColor = transparentcolor;

	return result;

}

void Texture::release()
{
	texture->Release();
}

Texture::~Texture()
{
}
