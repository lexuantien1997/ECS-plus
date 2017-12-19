#include "GameWorld.h"

void ECS::GameWorld::addSystem(System * sys, int index)
{
	sys->setSystemBits(index, true);
	sys->setWorld(this);
	systems[&typeid(*sys)].reset(sys);
}

ECS::Entity * ECS::GameWorld::createEntity(EntityName counter)
{
	auto e = new Entity(counter, this);	
	e->setUniqueId(uniqueId++);
	e->active();
	entities.insert(e);
	return e;
}

void ECS::GameWorld::refreshEntity(Entity * e)
{
	refreshed.push(e);
}

void ECS::GameWorld::removeEntity(Entity * e)
{
	// add into stack and remove when `loop2RefreshAndRemove` is called
	removed.push(e);
	
}

void ECS::GameWorld::loop2RefreshAndRemove()
{
	while (!refreshed.empty())
	{		
		for (auto& s : systems)
		{
			s.second->checkConditionExcludeAndRequire(refreshed.top());			
		}
		refreshed.pop();
	}
	
	while(!removed.empty())
	{
		// erases 
		entities.erase(removed.top());
		removed.pop();
	}
}

ECS::GameWorld::GameWorld()
{
	uniqueId = 0;
}

ECS::GameWorld::~GameWorld()
{
	entities.clear();
	systems.clear();
	
}

void ECS::GameWorld::setScene(ECS::Scene * s)
{
	parentScene = s;
}

ECS::Scene * ECS::GameWorld::getParentScene()
{
	return parentScene;
}
