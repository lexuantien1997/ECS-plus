#include "GameWorld.h"
#include "Entity.h"
#include "TSystem.h"


void ECS::GameWorld::clear()
{
	systems.clear();

	entities.clear();
}

ECS::GameWorld::GameWorld()
{
	id = 0;
}


ECS::GameWorld::~GameWorld()
{
}

void ECS::GameWorld::addEntity()
{
}

void ECS::GameWorld::clearSystem()
{
	systems.clear();
}


ECS::Entity * ECS::GameWorld::create_Entity(string name)
{
	// create an entity
	Entity *e = new Entity(name, this);
	// insert it into map
	entities.insert(pair<long, Entity*>(e->getId(), e));

	// return entity if use
	return e;
}



void ECS::GameWorld::removeEntity(Entity * entity)
{

}


void ECS::GameWorld::setActiveEntity(Entity * entity, bool value)
{
	value ? entity->active() : entity->deActive();
}

bool ECS::GameWorld::isActiveEntity(Entity * entity)
{
	return entity->isAlive();
}

ECS::Entity * ECS::GameWorld::getEntity(std::size_t index)
{
	return NULL;
}

void ECS::GameWorld::refresh()
{

	// Duyệt từng `Entity` để thêm từng `Entity` vào `System` phù hợp
	for (auto &it:entities /*it = entities.begin(); it != entities.end(); ++it*/)
	{		
		auto entity = it.second;

		// Nếu cái entity này còn xài được thì mới thêm vào system
		if (entity->isAlive())
		{
			// Duyệt từng system
			for ( auto& jt : systems)
			{
				auto index = jt.first;
				//auto system = jt.second;
				// Kiểm tra điều kiện các thành phần `Component` mà `System` cần có trong `Entity` không
				// Đồng thời cũng kiểm tra các thành phần `Component` yêu cầu không được có , có tồn tại trong `Entity` không
				if (jt.second->getChecker().checkComponentsSystem(entity))
				{
					// Nếu như nó chưa tồn tại trong system và chưa được xét lần nào
					if (entity->systems.size()<= index || !entity->systems[index])
					{
						jt.second->addEntity(entity);
						//system.addEntity(entity);
						if (entity->systems.size() <= index)
							entity->systems.resize(index + 1);

						entity->systems[index] = true; // Chuyển thành true vì system đã tồn tại trong entity
					}
					
				}

				// Nếu như nó bị lỗi, mà trước đó nó đã tồn tại trong System rồi thì phải xóa nó đi
				// Vì sao nó bị lỗi: Có thể sau khi refresh xong, Entity đó nó lại thêm 1 component khác vào nữa
				// Mà component đó lại là component mà system yêu cầu không được có
				// Lúc này thì lần refresh tiếp theo chúng ta phải xóa `Entity` đó ra khỏi `Component`
				else if (entity->systems.size() >  index && entity->systems[index])
				{
					jt.second->removeEntity(entity);
					entity->systems[index] = false;
				}
			}
		}
	}
}
