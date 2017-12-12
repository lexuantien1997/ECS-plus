#include "CollisionComponent.h"


void CollisionComponent::initCollision(float delta) {
	timeToCollision = delta;
	dirCantMove.insert(std::pair<Direction, bool>(DOWN, false));
	dirCantMove.insert(std::pair<Direction, bool>(UP, false));
	dirCantMove.insert(std::pair<Direction, bool>(LEFT, false));
	dirCantMove.insert(std::pair<Direction, bool>(RIGHT, false));
}
CollisionComponent::CollisionComponent(string name) :Component(name)
{

}


CollisionComponent::~CollisionComponent()
{
}
