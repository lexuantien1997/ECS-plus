#include "RenderingSystem.h"
#include "Bound.h"


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
		auto bound = entity->getComponent<Bound>("bound");

		if (bound->runningRight==false )
		{
			if ( transform->getScale().x>0)
			{
				transform->scaling(-1, 1);				
			}
			
		}
		else if (bound->runningRight == true )
		{
			if (transform->getScale().x<0)
			{
				transform->scaling(-1, 1);		
			}		
		}
		transform->setOrigin(spriteComp->getRect().size*0.5f);
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


