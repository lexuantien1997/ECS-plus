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
	
	asset->attachResource(new Sprite("samus_aran.png", "resources/charactor/samus_aran.png"));// state samus

	asset->attachResource(new Animation("samus_states.xml", "../resources/charactor/samus_states.xml")); // state samus_xml

}
