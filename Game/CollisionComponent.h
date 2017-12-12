#ifndef COLLISIONCOMPONENT_H_
#define COLLISIONCOMPONENT_H_

#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"

using namespace ECS;

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};


class CollisionComponent :public ECS::Component
{
public:

	CollisionComponent(string name);

	double timeToCollision;
	std::map<Direction, bool> dirCantMove;
	void initCollision(float delta);
	~CollisionComponent();
};
#endif // !COLLISIONCOMPONENT_H_

