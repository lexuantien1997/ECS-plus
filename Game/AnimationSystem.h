#ifndef ANIMATIONSYSTEM_H_
#define ANIMATIONSYSTEM_H_

#include "AnimationComponent.h"
#include "SpriteComponent.h"
#include "Mess.h"
#include "Client.h"

class AnimationSystem:public ECS::TSystem,public Client
{
private:
	
	float stateTime;
public:

	AnimationSystem(Server* p_server);

	~AnimationSystem();

	void update(float dt);

	void onUpdate(Entity * entity);

	void onActionChanged(Entity* e, string name);

	void render();

	void init();

	void loadResource();

	void MessageSentHandler(const Server* p_sender, void* p_parameter);
};

#endif // !ANIMATIONSYSTEM_H_


