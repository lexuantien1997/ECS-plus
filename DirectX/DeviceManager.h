#ifndef DEVICEMANAGER_H_
#define DEVICEMANAGER_H_

//#include "Singleton.h"
#include "..\ECS Plus\Singleton.h"
#include "WindowManager.h"
#include "../directx data/Include/d3dx9.h"

class DeviceManager:public ECS::Singleton<DeviceManager>
{
private:

	LPDIRECT3D9 direct3d;
	
	LPDIRECT3DDEVICE9 direct3ddv;
	
	LPDIRECT3DSURFACE9 backBuffer;

public:

	~DeviceManager();
	DeviceManager();
	void clearScreen(); // clear screen
	void draw(); // Show informations on screen

	void InitDirectX(WindowManager* window);

	// getter - setter
	LPDIRECT3DDEVICE9 getDevice();
	LPDIRECT3DSURFACE9 getBackBuffer();

	void release();
};

#endif // !DEVICEMANAGER_H_



