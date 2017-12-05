#include "Game.h"
#include "SpriteManager.h"

using namespace ECS;

void Game::init()
{
	window->InitWindow();

	DeviceManager::getInstance()->InitDirectX(window);

	InputManager::getInstance()->init(window->GetHwnd(),window->GetHInstance());

	// load resource form resource manager
	loadResource();

	loadResourceData();
}

void Game::loadResource()
{
}

void Game::loadResourceData()
{
	for (auto rs : SpriteManager::getInstance()->getResourceInitialize())
	{
		rs.second->loadResource();
	}
}

void Game::runGame()
{
	MSG msg; // throw the message
	DWORD frame_start = GetTickCount(); // get time start game
	bool endGame = false;
	DWORD count_per_frame = 1000 / fps;

	// initialize data like resource:
	init();

	while (!endGame)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) 
				endGame = true;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			DWORD now = GetTickCount();
			deltatime = now - frame_start;
			if (deltatime >= count_per_frame)
			{
				frame_start = now;

				// start update
				update(deltatime);

				// start render
				render();
			}
			else
				Sleep(count_per_frame - deltatime);
		}
		
	}
}

void Game::release()
{
	// release Device manager
	DeviceManager::getInstance()->release();
	// release input manager
	InputManager::getInstance()->release();
	// release audio manager

	// release window manager
	window->release();
	// release resource manager

	// release scene:
	// + release each entity - > release component
	// + release system
	SceneManager::getInstance()->release();

}

void Game::render()
{
	if (DeviceManager::getInstance()->getDevice()->BeginScene())
	{
		DeviceManager::getInstance()->clearScreen();

		// Render scene
		SceneManager::getInstance()->render();

		DeviceManager::getInstance()->getDevice()->EndScene();
	}
	DeviceManager::getInstance()->draw();

}

void Game::update(float dt)
{
	// update input
	InputManager::getInstance()->update(window->GetHwnd());
	// update scene
	SceneManager::getInstance()->update(dt);
}


Game::Game(HINSTANCE hInstance, LPWSTR name, int mode, int isFulllScreen, int fps)
{
	this->fps = fps;
	window = new WindowManager(hInstance, name, mode, isFulllScreen);
	
}

Game::~Game()
{
	release();
}
