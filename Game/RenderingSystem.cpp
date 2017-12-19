#include "RenderingSystem.h"
#include "Bound.h"


RenderingSystem::RenderingSystem()
{
	requireComponent<SpriteComponent>();
	requireComponent<Transform>();
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
		if (entity->getEntityName()== EntityName::SAMUS )
		{
			auto transform = entity->getComponent<Transform>();
			auto spriteComp = entity->getComponent<SpriteComponent>();
			auto bound = entity->getComponent<Bound>();

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
			SpriteManager::getInstance()->draw(spriteComp, transform, getWorld()->getParentScene()->cam);
		}
	}
}

void RenderingSystem::init()
{

}

