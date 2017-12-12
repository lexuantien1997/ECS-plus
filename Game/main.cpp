#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "MetroidGame.h"
#include <Windows.h>
using namespace std;

#include  <list>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpStrCmdLine,
	int nShowCmd)
{

	MetroidGame *metroid = new MetroidGame(hInstance, L"Metroid", GAME_SCREEN_RESOLUTION_640_480_24, 0, 60);

	metroid->runGame();

	return 0;
}

