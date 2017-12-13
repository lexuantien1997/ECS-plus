#include "TSystem.h"



ECS::TSystem::TSystem()
{

}


ECS::TSystem::~TSystem()
{
}

void ECS::TSystem::addEntity(Entity * entity)
{
	v_entities.push_back(entity);
}

void ECS::TSystem::removeEntity(Entity * entity)
{
	v_entities.erase(std::remove(v_entities.begin(), v_entities.end(), entity), v_entities.end());
}
