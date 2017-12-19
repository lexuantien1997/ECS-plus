#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "Entity.h"
#include <vector>
#include "Component.h"
class Component;

namespace ECS
{
	class System
	{
	private:

		GameWorld* world;
		vector<Entity*> activeEntities;
		bitset<BITSIZE> requireBits;
		bitset<BITSIZE> excludeBits;
		bitset<BITSIZE> systemBits;

		/*function*/
		bool checkCondition(Entity* e);
	public:
		
		template<typename component_type> void requireComponent();
		template<typename component_type> void excludeComponent();

		vector<Entity*> getEntities() { return activeEntities; }
		void removeEntity(Entity* e);
		void addEntity(Entity* e);
		void setSystemBits(int pos,bool value);
		void setWorld(GameWorld* world) { this->world = world; }
		GameWorld* getWorld() { return world; }
		bitset<BITSIZE> getSystemBits();
		void checkConditionExcludeAndRequire(Entity* e);

		System();

		~System();

		/*Overide these method*/
		virtual void initialize(){ }
		virtual void update(float dt){ }
		virtual void render() { }
	};

	template<typename component_type>
	inline void System::requireComponent()
	{
		int index = TypeId<Component>::get<component_type>();
		requireBits[index] = true;
	}

	template<typename component_type>
	inline void System::excludeComponent()
	{
		int index = TypeId<Component>::get<component_type>();
		excludeBits[index] = true;
	}
}


#endif