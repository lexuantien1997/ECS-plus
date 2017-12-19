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
	for (Entity* entity : getEntities())
	{
		if (entity->getName() == "samus")
		{
			Transform* transform = entity->getComponent<Transform>("transform component");
			SpriteComponent* spriteComp = entity->getComponent<SpriteComponent>("sprite component");
			Bound* bound = entity->getComponent<Bound>("bound");

			if (bound->runningRight == false)
			{
				if (transform->getScale().x>0)
				{
					transform->scaling(-1, 1);
				}

			}
			else if (bound->runningRight == true)
			{
				if (transform->getScale().x<0)
				{
					transform->scaling(-1, 1);
				}
			}
			transform->setOrigin(spriteComp->getRect().size*0.5f);
			SpriteManager *batch = SpriteManager::getInstance();
			batch->draw(spriteComp, transform, getGameWorld()->cam);
		}
		else if (entity->getName() == "intro")
		{
			Transform* transform = entity->getComponent<Transform>("transform component");
			SpriteComponent* spriteComp = entity->getComponent<SpriteComponent>("sprite component");

			SpriteManager::getInstance()->drawLeftTopTransform(spriteComp, transform, getGameWorld()->cam);
		}
		else if (entity->getName() == "start")
		{
			Transform* transform = entity->getComponent<Transform>("transform component");
			SpriteComponent* spriteComp = entity->getComponent<SpriteComponent>("sprite component");

			SpriteManager::getInstance()->drawLeftTopTransform(spriteComp, transform, getGameWorld()->cam);
		}
		else if (entity->getName() == "Skree")
		{
			Transform* transform = entity->getComponent<Transform>("transform component");
			SpriteComponent* spriteComp = entity->getComponent<SpriteComponent>("sprite component");

			SpriteManager::getInstance()->draw(spriteComp, transform, getGameWorld()->cam);
		}
	}
}

void RenderingSystem::init()
{

}

void RenderingSystem::loadResource()
{

}


