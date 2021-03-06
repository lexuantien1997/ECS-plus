#ifndef METROIDGAME_H_
#define METROIDGAME_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "PlayingScene.h"
#include "IntroScene.h"
#include "Start_GameOver_Scene.h"
#include "introAnimation.h"
#include "Animation.h"
#include "EnemiesAnimation.h"

using namespace ECS;
class MetroidGame:public Game
{
public:

	MetroidGame(HINSTANCE hInstance, LPWSTR name, int mode, int isFulllScreen, int fps);

	~MetroidGame();

	void init();

	void loadResource();
};


#endif // !METROIDGAME_H_


