#ifndef COLLISIONSYSTEM_H_
#define COLLISIONSYSTEM_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "Velocity.h"
#include "Bound.h"
#include "CollisionComponent.h"
class CollisionSystem :public ECS::TSystem
{
public:

	void update(float dt);

	void render(){}

	void init(){}

	void loadResource(){}


	CollisionSystem();
	Direction dirCollision(Transform transformPlayer, SpriteComponent spritePlayer, Transform transformSub, SpriteComponent spriteSub);
	bool isColliding(Transform transformPlayer, Velocity velocityPlayer, Bound boundPlayer, SpriteComponent spritePlayer, CollisionComponent *collisionPlayer, Transform transformSub, Velocity velocitySub, Bound boundSub, SpriteComponent spriteSub, CollisionComponent *collisionSub, float delta);
	double sweptAABB(Transform transformPlayer, Velocity velocityPlayer, Bound boundPlayer, SpriteComponent spritePlayer, Transform transformSub, Velocity velocitySub, SpriteComponent spriteSub, Bound boundSub, float delta);
	void afterCollision(CollisionComponent *collisionPlayer);
	~CollisionSystem();
};
#endif // COLLISIONSYSTEM_H_

