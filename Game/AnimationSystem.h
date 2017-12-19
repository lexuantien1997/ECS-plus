#ifndef ANIMATIONSYSTEM_H_
#define ANIMATIONSYSTEM_H_

#include "AnimationComponent.h"
#include "SpriteComponent.h"

class AnimationSystem:public ECS::System
{
private:
	
	float stateTime;
public:

	AnimationSystem();

	~AnimationSystem();

	void update(float dt);

	void onUpdate(Entity * entity,float);

	void onActionChanged(Entity* e, string name);

	void render();

	void init();


};

#endif // !ANIMATIONSYSTEM_H_


