#ifndef SCENE_H_
#define SCENE_H_
#include "GameWorld.h"
#include "../Game/Camera.h"
namespace ECS
{
	class Scene
	{

	private:

		string name;

	public:
		Camera cam;

		GameWorld *world;

		Scene(string _name) :name(_name), world(new GameWorld()) { world->setScene(this); }

		~Scene() { }

		virtual void update(float dt) = 0;

		virtual void init() = 0;

		virtual void render() = 0;

		virtual void release() { };

	};
}



#endif // !SCENE_H_


