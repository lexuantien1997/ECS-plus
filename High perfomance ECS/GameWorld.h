#ifndef _GAMEWORLD_H_
#define _GAMEWORLD_H_

#include <map>
#include <stack>
#include <vector>
#include <unordered_set>

#include "Entity.h"
#include "System.h"

namespace ECS
{
	class Scene;
	class GameWorld
	{
	private:
	
		long int uniqueId;						// id will count when createEntity function is called 
		unordered_set<Entity*> entities;		// holds all entities in game world
		stack<Entity*> refreshed;				// entities need to be refreshed next frame
		stack<Entity*> removed;					// entities need to be deleted next frame
		map<const type_info*, unique_ptr<System>> systems; // holds all systems in game world
		Scene* parentScene;
		/*function*/
		void addSystem(System* sys, int index);
	public:
		
		Entity* createEntity(EntityName counter = EntityName::NO_NAME);
		void refreshEntity(Entity* e);
		template <typename system_type> system_type* addSystem(system_type* system);
		template<class T> void addSystem(T& t);
		void removeEntity(Entity* e);
		void loop2RefreshAndRemove();
		GameWorld();		
		~GameWorld();
		void setScene(ECS::Scene* s);
		Scene* getParentScene();
	};

	template<typename system_type>
	inline system_type* GameWorld::addSystem(system_type * sys)
	{
		static_assert(std::is_base_of<System,system_type>(), "system_type is not a system");
		assert(!t.getWorld() , "This system has existed");
		int index = TypeId<System>::get<system_type>();
		addSystem(sys, index);
		return sys;
	}

	template<class T>
	inline void GameWorld::addSystem(T& t)
	{
		static_assert(std::is_base_of<System, T>(), "system_type is not a system");
		assert(!t.getWorld() , "This system has existed");

		int index = TypeId<System>::get<T>();

		addSystem(&t, index);
	}

}

#endif // !_GAMEWORLD_H_

