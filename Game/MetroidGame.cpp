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
	SceneManager::getInstance()->addScene(new Start_GameOver_Scene("Start scene")); // there's a bug here
	SceneManager::getInstance()->addScene(new IntroScene("Intro scene"));
}

void MetroidGame::loadResource()
{
	SpriteManager* asset = SpriteManager::getInstance();
	
	asset->attachResource(new Sprite("samus_aran.png", "resources/charactor/samus_aran.png"));

	asset->attachResource(new Sprite("intro.png", "../resources/intro/intro.png"));

	asset->attachResource(new Sprite("start.png", "../resources/intro/start.png"));

	asset->attachResource(new Sprite("enemies.png", "../resources/enemies/enemies.png"));

	asset->attachResource(new Sprite("tiles.png", "../resources/map/tiles.png"));

	asset->attachResource(new Animation("samus_states.xml", "../resources/charactor/samus_states.xml"));

	asset->attachResource(new TileMap("untitled.tmx", "../resources/map/untitled.tmx"));

	asset->attachResource(new introAnimation("introscene.xml", "../resources/intro/introscene.xml"));

	asset->attachResource(new EnemiesAnimation("enemies.xml", "../resources/enemies/enemies.xml"));
	
	// code that generates quadtree xml file
	
	/*QuadtreeDivision quadtreeDivision;
	quadtreeDivision.preExport("../resources/map/untitled.tmx");
	quadtreeDivision.BuildTree(quadtreeDivision.rootQuadtree);
	quadtreeDivision.Export(quadtreeDivision.rootQuadtree, quadtreeDivision.xml_rootNode);
	quadtreeDivision.endExport("../resources/map/untitledQuadtree.xml");
	quadtreeDivision.release(quadtreeDivision.rootQuadtree);*/
}
