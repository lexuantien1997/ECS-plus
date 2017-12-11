#include "MetroidGame.h"



MetroidGame::MetroidGame(HINSTANCE hInstance, LPWSTR name, int mode, int isFulllScreen, int fps): 
	Game(hInstance,  name,  mode,  isFulllScreen,  fps)
{

}


MetroidGame::~MetroidGame()
{
}

void MetroidGame::init()
{
	Game::init();
	SceneManager::getInstance()->addScene(new PlayingScene("Playing scene"));
}

void MetroidGame::loadResource()
{
	auto asset = SpriteManager::getInstance();
	
	asset->attachResource(new Sprite("samus_aran.png", "resources/charactor/samus_aran.png"));

	asset->attachResource(new Animation("samus_states.xml", "../resources/charactor/samus_states.xml"));

	asset->attachResource(new Sprite("tiles.png", "../resources/map/tiles.png"));

	asset->attachResource(new TileMap("untitled.tmx", "../resources/map/untitled.tmx"));
}
