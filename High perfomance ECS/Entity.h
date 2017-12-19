#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <iostream>
#include <bitset>
#include <map>
#include <array>
#include <memory>
#include <cassert>

#include "BaseTypeID.h"
#include "Constant.h"
#include "Component.h"

#include "EntityName.h"

using namespace std;

namespace ECS
{
	class GameWorld;
	class Entity
	{
	private:

		bool isActive;						// active or not
		EntityName name;					// enum type name
		long int uniqueId;					// unique id
		GameWorld* world;					// world
		bitset<BITSIZE> compBits;			// position components of entity in the world 
		bitset<BITSIZE> sysBits;				// position systems of entity in the world 
		map<ComponentId, Component*> components; // components of entity

		/*Function*/
		void replace(ComponentId index,Component* comp);
		void addComponent(ComponentId index, Component* comp);
	public:

		void removeEntity();
		
		template<typename Comp> Comp* addComponent(Comp* component);
		template<typename T, typename ...Args> T* addComponent(Args &&... args);
		template<typename Comp> void replaceComponent(Comp* comp);
		template<typename T,typename ...Args> void replaceComponent(Args &&... args);
		template<typename T> void removeComponent();
		template<typename T> T* getComponent();
		template<typename T> bool hasComponent();

		
		void active();
		void refresh();
		void deactive();
		bool checkActive();		
		long int getUniqueId();
		void removeAllComponent();
		EntityName getEntityName();
		bitset<BITSIZE> getCompBits();
		bitset<BITSIZE> getSystemsBits();
		void setUniqueId(long int uniqueId);
		void addSystemBits(bitset<BITSIZE> sysBits);
		void removeSystemBits(bitset<BITSIZE> sysBits);

		Entity(EntityName _counter,GameWorld* world);
		Entity(GameWorld* world, EntityName _counter = EntityName::NO_NAME);
		~Entity();

	};

	template<typename Comp>
	inline Comp* Entity::addComponent(Comp* comp)
	{
		static_assert(std::is_base_of<Component, Comp>(), "comp is not a component");
		int index = TypeId<Component>::get<Comp>();

		if (compBits[index])
			replace(index, comp);
		else // -> add and make compPos = true
			addComponent(index, comp);

		// return if use
		return comp;
	}

	template<typename T, typename ...Args>
	inline void Entity::replaceComponent(Args && ...args)
	{
		if (hasComponent<T>()) // has component
		{
			auto comp= new T{ forward<Args>(args)... };
			replace(TypeId<Component>::get<T>(), comp);
		}
		else // not have component
			addComponent<T>(args);
	}

	template<typename T, typename ...Args>
	inline T * Entity::addComponent(Args && ...args)
	{
		// check T is component ?
		static_assert(std::is_base_of<Component, T>(), "T is not a component");
		// add all parametter into constructor
		auto comp = new T{ forward<Args>(args)... };
		// get Position in world
		int index = TypeId<Component>::get<T>();

		// if already exist -> just replace
		if (compBits[index])
			replace(index, comp);
		else // -> add and make compPos = true
			// add
			addComponent(index, comp);
			
		// return if use
		return comp;
	}

	template<typename Comp>
	inline void Entity::replaceComponent(Comp * comp)
	{
		static_assert(std::is_base_of<Component, Comp>(), "T is not a component");

		if (hasComponent<Comp>()) // has component
			replace(TypeId<Component>::get<Comp>(), comp);
		else // not have component
			addComponent(TypeId<Component>::get<Comp>(),comp);
	}

	template<typename T>
	inline void Entity::removeComponent()
	{
		// check sth
		static_assert(is_base_of<Component, T>(), "T is not component");
		assert(hasComponent<T>(), "T is not have component");
		// get pos
		int index= TypeId<Component>::get<T>();
		// remove component
		components.erase(index);
		// delete compPos
		compBits[index] = false;
	}


	template<typename T>
	inline T* Entity::getComponent()
	{
		// check sth 
		static_assert(is_base_of<Component, T>(), "T is not component");
// 		static_assert(hasComponent<T>(), "T is not have component");
		// get id
		int index = TypeId<Component>::get<T>();
		// ép kiểu
		return static_cast<T*>(components[index]);
	}

	template<typename T>
	inline bool Entity::hasComponent()
	{
		// Check is component ?
		static_assert(std::is_base_of<Component, T>(), "T is ot Component");
		// get Position in world
		int index = TypeId<Component>::get<T>();
		// check exist in entity ?
		bool checkExist = compBits[index];
		// return value
		return checkExist;

	}
}


#endif
