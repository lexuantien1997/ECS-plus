#include "RenderingSystem.h"



RenderingSystem::RenderingSystem()
{
	Requires<Require<SpriteComponent, Transform>>();

	Excludes<Exclude<>>();
}


RenderingSystem::~RenderingSystem()
{

}

void RenderingSystem::update(float dt)
{

}

void RenderingSystem::render()
{
	for (auto entity : getEntities())
	{
		auto transform = entity->getComponent<Transform>("transform component");
		auto spriteComp = entity->getComponent<SpriteComponent>("sprite component");

		auto batch = SpriteManager::getInstance();
		batch->draw(spriteComp, transform);
	}
}

void RenderingSystem::init()
{

}

void RenderingSystem::loadResource()
{

}


