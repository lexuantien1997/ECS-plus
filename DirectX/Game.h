#ifndef GAME_H
#define GAME_H

#include "../directx data/Include/d3d9.h"
#include "../directx data//Include/dinput.h"

#include "DeviceManager.h"
#include "InputManager.h"
#include "WindowManager.h"

#include "../ECS Plus/SceneManager.h"

class Game
{
protected:

	DWORD deltatime;

	int fps;


public:
	WindowManager* window;
	
	virtual void init();

	void initQuadtree();

	virtual void loadResource();

	void loadResourceData();

	void runGame();

	void release();

	void render();

	void update(float);

	Game(HINSTANCE, LPWSTR, int, int, int);

	~Game();
};


#endif // !GAME_H


