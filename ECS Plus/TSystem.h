#ifndef TSYSTEM_H_
#define TSYSTEM_H_

#include "SystemStoreID.h"
namespace ECS
{
	class GameWorld;
	class Entity;
	/*
	* Why we must use class `ISystem` ?
	* This is just a trick. Because `System` has a template in front of
	* => You can't use it to count id or use std::is_base_of
	*/

	// =================================================== Brief ====================================================
	//	- System is where defides the logic for particular parts (components) of your game
	//	- Example
	//
	//
	class TSystem
	{
	private:

		// each system will have an array about require and exclude component
		Checker checker;
		// Base GameWorld:
		GameWorld* gameWorld;
		// 1 system may be represent for more than 1 entity:
		std::vector<Entity*> v_entities;
	public:

		// ========================================================================
		//  Getter - Setter method 
		// ========================================================================

		void setGameWorld(GameWorld* s) { gameWorld = s; }

		GameWorld* getGameWorld() { return gameWorld; }

		Checker getChecker() { return checker; }

		vector<Entity*> getEntities() { return v_entities; }

		TSystem();
		
		~TSystem();

		// =======================================================================
		// Base method
		// =======================================================================

		// Important function
		template<class Requires>
		void Requires();

		// Important function
		template<class Exclude>
		void Exclude();

		void addEntity(Entity* entity);

		void removeEntity(Entity* entity);
	};

	template<class Requires>
	inline void TSystem::Requires()
	{
		checker._requires = addRequire<Requires>();
	}

	template<class Exclude>
	inline void TSystem::Exclude()
	{
		checker._excludes = addExclude<Exclude>();
	}
}



#endif // !TSYSTEM_H_


