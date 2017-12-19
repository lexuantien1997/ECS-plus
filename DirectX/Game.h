#ifndef GAME_H
#define GAME_H

#include "../directx data/Include/d3d9.h"
#include "../directx data//Include/dinput.h"

#include "DeviceManager.h"
#include "InputManager.h"
#include "WindowManager.h"

#include "../High perfomance ECS/SceneManager.h"

class Game
{
protected:

	DWORD deltatime;

	int fps;

	WindowManager* window;

public:

	virtual void init();

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


