#include "SceneManager.h"
#include "Scene.h"


ECS::SceneManager::SceneManager()
{

}


ECS::SceneManager::~SceneManager()
{

}

void ECS::SceneManager::addScene(Scene * s)
{
	scenes.emplace_back(s);

	scenes.back()->init();
}

void ECS::SceneManager::removeScene()
{
	if (!scenes.empty())
	{
		delete scenes.back();

		scenes.pop_back();
	}
}

void ECS::SceneManager::clear()
{
	if (!scenes.empty())
		scenes.clear();
}

ECS::Scene * ECS::SceneManager::getCurrentScene()
{
	return scenes.empty() != NULL ? scenes.back() : NULL;
}

void ECS::SceneManager::replaceScene(Scene * s)
{
	removeScene();

	addScene(s);
}

void ECS::SceneManager::update(float dt)
{
	if (!scenes.empty())
		scenes.back()->update(dt);
}

void ECS::SceneManager::init()
{
	if (!scenes.empty())
		scenes.back()->init();
}

void ECS::SceneManager::render()
{
	if (!scenes.empty())
		scenes.back()->render();
}

void ECS::SceneManager::release()
{
	for (Scene* scene :scenes)
	{
		scene->release();
	}

	clear();
}
