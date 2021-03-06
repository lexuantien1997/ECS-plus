﻿#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_
#include <type_traits>
#include <vector>
#include "BaseID.h"
#include <map>
#include "System.h"
#include <cassert>
#include <memory>
#include "../Game/Camera.h"
#include "../DirectX/Define.h"

using namespace std;


namespace ECS
{
	class Entity;
	class TSystem;

	// ================================================= Brief ======================================================
	//
	//	- Game world is an Entity System, We call that name because it holds entities and systems
	//	- Things you can do with `GameWorld`:
	//			+ createEntity : create an entity
	//			+ addSystem | removeSystem : add or remove system
	//			+ getEntity : find and get the entity in the game world
	//			+ hasSystem : check if system exist
	//
	// ==============================================================================================================			
	class GameWorld
	{
	public:
		Camera cam;
		// ==========================================================================================================
		//												System method
		// ==========================================================================================================

		/**
		*@brief  Add system into the `GameWorld`
		* T : Type of System
		**/
		template<class T>
		void addSystem(T& t);

		/**
		*@brief  Remove system out of the `GameWorld`
		* T : Type of System
		**/
		template<class T>
		void removeSystem();


		/**
		*@brief  Check system exist or not in the `GameWorld`
		* T : Type of System
		**/
		template<class T>
		bool hasSystem(ECS::ID::BaseID index);


		/**
		*@brief  Remove all system in the `GameWorld`
		* T : Type of System
		**/
		void clearSystem();

		// ==========================================================================================================
		//												Entity method
		// ==========================================================================================================

		/* NOTE: use when you create a class inherit Entity *
		*@brief  Create an entity and match it into `GameWorld`
		*@para name: name of entity
		*@return : Entity if use
		**/
		template<class T>
		T* createEntity(string name);

		

		/**
		*@brief  Create an entity and match it into `GameWorld`
		*@para name: name of entity
		*@return : Entity if use
		**/
		Entity* create_Entity(string name);

		vector<Entity*> create_Entities(int size);

		/*Chưa làm*
		*@brief  Remove an entity out of `GameWorld`
		* + Step 1: Find entity want to remove
		* + Step 2: Destroy links between `System` and `Entity`
		**/
		void removeEntity(Entity* entity);

		/**
		*@brief  Make Entity active or not
		**/
		void setActiveEntity(Entity* entity, bool value);

		bool isActiveEntity(Entity* entity);

		/*Chưa làm*
		*@brief  Get specific Entity with index
		**/
		Entity* getEntity(std::size_t index);

		// ==========================================================================================================
		//												GameWorld method
		// ==========================================================================================================

		/**
		*@brief  Refresh game
		* When you call this method. GameWorld will automatically specify where `Entity` belong to `System`
		* Call it before update to refresh game
		**/
		void refresh();


		/**
		*@brief  Remove all Entities and Systems
		**/
		void clear();

		/**
		*@brief  Generate id for the Entity
		**/
		long getId() { return id; }

		void increaseid() { id++; }

		// ==========================================================================================================
		//													Constructor
		// ==========================================================================================================
		GameWorld();
		~GameWorld();

	protected:

		// 1 GameWorld has many Systems like MovementSystem, AnimationSystem, CollisionSystem, ... 
		// unique_ptr: https://www.stdio.vn/articles/read/92/c11-smart-pointers-quan-ly-tai-nguyen
		map < ECS::ID::BaseID, std::unique_ptr<TSystem>>  systems;

		// 1 GameWorld has many Entity like Samus, Enemy, Background, Grass, ... 
		// Use map because we have many entity which same type such as:
		// If we create 2 players Samus 1 and Samus 2 
		// It still a Samus class but we must create twice
		// Another example : more enemies in your game
		map <long, Entity*> entities;

		// The id for entity
		long id;

		// =============== Add entity =====================

		void addEntity();

	};




	template<class T>
	inline void GameWorld::addSystem(T& t)
	{
		// static_assert(is_base_of<TSystem, T>, "T is not inherit from TSystem");

		// ?Kiểm tra 2 lần liên tiếp:

		// Lần 1 nếu GameWorld của nó != NULL nghĩa là nó có thể chưa trong cái sence nào hết
		// Chỉ là có thể thôi vì mình có thể cái GameWorld của nó bằng hàm `setGameWorld` thay đổi	

		// hàm assert :
		// Ví dụ muốn tất cả các chuỗi phái có chiều dài  lớn hơn 10
		// Nếu nhỏ hơn 10 in ra lỗi "SAi độ dài chuỗi"
		// assert(strlen(string) > 10, "SAi độ dài chuỗi"); 

		assert(!t.getGameWorld() && "This system has existed");

		// Get the index of system
		BaseID index = ID::ClassID<TSystem>::getBaseTypeID<T>();

		// Lần 2 kiểm tra bằng cách tìm kiếm nó theo BaseID
		// Nếu đếm nó khác 0 nghĩa là nó đã tồn tại rồi
		// systems.count() : đếm số lần cái giá trị đó có
		assert(systems.count(index) == 0, "This system has existed");

		// set GameWorld
		t.setGameWorld(this);

		// insert it into map
		// systems.insert(pair<BaseID, TSystem>(index, t));
		//systems[index] = std::make_unique<TSystem>(t);
		// Tự động ghi đè dữ liệu lên các con trỏ
		systems[index].reset(&t);
	}

	template<class T>
	inline void GameWorld::removeSystem()
	{
		// Get the index of system
		BaseID index = ID::ClassID<TSystem>::getBaseTypeID<T>();

		assert(hasSystem<T>(index) && "This system not exist in GameWorld");

		systems.erase(index);
	}

	template<class T>
	inline bool GameWorld::hasSystem(ECS::ID::BaseID index)
	{
		return systems.find(index) != systems.end();
	}

	template<class T>
	inline T * GameWorld::createEntity(string name)
	{
		static_assert(std::is_base_of<Entity, T>::value, "T not a Entity");

		// create an entity
		T *e = new T(name, this);
		// insert it into map
		entities.insert(pair<long, Entity*>(e->getId(), e));

		// return entity if use
		return static_cast<T*>(e);
	}

}


#endif // !GameWorld_H_
