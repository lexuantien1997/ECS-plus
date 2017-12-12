#include "CollisionSystem.h"
void CollisionSystem::update(float dt)
{
	double thoigianvacham = dt;
	
	for (auto entity : getEntities())
	{
		if (entity->getName() == "samus")
		{
			auto transformPlayer = entity->getComponent<Transform>("transform component");
			auto velocityPlayer = entity->getComponent<Velocity>("velocity");
			auto boundPlayer = entity->getComponent<Bound>("bound");
			auto collisionPlayer = entity->getComponent<CollisionComponent>("collision component");
			auto spritePlayer = entity->getComponent<SpriteComponent>("sprite component");

			Transform *transformCollision;
			SpriteComponent *spriteCollision;
			for (auto entitySub : getEntities()) {
				auto transformSub = entitySub->getComponent<Transform>("transform component");
				auto velocitySub = entitySub->getComponent<Velocity>("velocity");
				auto boundSub = entitySub->getComponent<Bound>("bound");
				auto collisionSub = entitySub->getComponent<CollisionComponent>("collision component");
				auto spriteSub = entitySub->getComponent<SpriteComponent>("sprite component");
				if (isColliding(*transformPlayer, *velocityPlayer, *boundPlayer, *spritePlayer, collisionPlayer, *transformSub, *velocitySub, *boundSub, *spriteSub, collisionSub, dt)) {
					if (collisionPlayer->timeToCollision == 0) {
						collisionPlayer->dirCantMove[dirCollision(*transformPlayer, *spritePlayer, *transformSub, *spriteSub)] = true;
					}
				}
			}
			for (auto entitySub : getEntities()) {
				if (entity->getName() != "samus")
				{
					auto transformSub = entitySub->getComponent<Transform>("transform component");
					auto velocitySub = entitySub->getComponent<Velocity>("velocity");
					auto boundSub = entitySub->getComponent<Bound>("bound");
					auto collisionSub = entitySub->getComponent<CollisionComponent>("collision component");
					auto spriteSub = entitySub->getComponent<SpriteComponent>("sprite component");
					if (isColliding(*transformPlayer, *velocityPlayer, *boundPlayer, *spritePlayer, collisionPlayer, *transformSub, *velocitySub, *boundSub, *spriteSub, collisionSub, dt)) {
						if (!collisionPlayer->dirCantMove[dirCollision(*transformPlayer, *spritePlayer, *transformSub, *spriteSub)]) {
							if (collisionPlayer->timeToCollision != 0) {
								if (thoigianvacham > collisionPlayer->timeToCollision) {
									transformCollision = transformSub;
									spriteCollision = spriteSub;
									//objectvacham = Collision::listObject[i];
									thoigianvacham = collisionPlayer->timeToCollision;
								}
							}
							else {
								collisionPlayer->dirCantMove[dirCollision(*transformPlayer, *spritePlayer, *transformSub, *spriteSub)] = true;
							}
						}
					}
				}
			}
			break;
			//if (collisionPlayer->dirCantMove[DOWN]) {
			//	//mainChar->groundY = mainChar->getPosition().getY();
			//	velocityPlayer->setVelocity(velocityPlayer->getVelocity().x, 0);
			//}
			if (thoigianvacham > 0 && thoigianvacham < dt) {
				//velocityPlayer->NextPosition(thoigianvacham);
				collisionPlayer->dirCantMove[dirCollision(*transformPlayer, *spritePlayer, *transformCollision, *spriteCollision)] = true;
				/*if ((collisionPlayer->dirCantMove[LEFT] || collisionPlayer->dirCantMove[RIGHT]))
					velocityPlayer->setVelocity(0,velocityPlayer->getVelocity().y);
				if ((collisionPlayer->dirCantMove[UP] || collisionPlayer->dirCantMove[DOWN]))
					velocityPlayer->setVelocity(velocityPlayer->getVelocity().x, 0);*/
			}
			/*else
				mainChar->NextPosition(Delta);*/
			//afterCollision(collisionPlayer);
		}
	}
}
void CollisionSystem::afterCollision(CollisionComponent *collisionPlayer) {
	collisionPlayer->dirCantMove.clear();
	collisionPlayer->dirCantMove.insert(std::pair<Direction, bool>(DOWN, false));
	collisionPlayer->dirCantMove.insert(std::pair<Direction, bool>(UP, false));
	collisionPlayer->dirCantMove.insert(std::pair<Direction, bool>(LEFT, false));
	collisionPlayer->dirCantMove.insert(std::pair<Direction, bool>(RIGHT, false));
}
CollisionSystem::CollisionSystem()
{
	Requires<Require<Transform, Velocity>>();

	Excludes<Exclude<>>();
}


CollisionSystem::~CollisionSystem()
{
	
}
Direction CollisionSystem::dirCollision(Transform transformPlayer,SpriteComponent spritePlayer, Transform transformSub,SpriteComponent spriteSub) {
	if ((transformPlayer.getPosition().y - spritePlayer.getRect().size.y) == transformSub.getPosition().y)
		return DOWN;
	if ((transformSub.getPosition().y - spriteSub.getRect().size.y) == transformPlayer.getPosition().y)
		return UP;
	if ((transformPlayer.getPosition().x + spritePlayer.getRect().size.x) == transformSub.getPosition().x)
		return RIGHT;
	if ((transformSub.getPosition().x + spriteSub.getRect().size.x) == transformPlayer.getPosition().x)
		return LEFT;

}
double CollisionSystem::sweptAABB(Transform transformPlayer, Velocity velocityPlayer, Bound boundPlayer,SpriteComponent spritePlayer, Transform transformSub, Velocity velocitySub, SpriteComponent spriteSub, Bound boundSub, float delta) {
	double dxEntry, dxExit;
	double dyEntry, dyExit;

	double txEntry, txExit;
	double tyEntry, tyExit;

	if (velocityPlayer.getVelocity().x > 0.0f)
	{
		dxEntry = transformSub.getPosition().x - (transformPlayer.getPosition().x + spritePlayer.getRect().size.x);
		dxExit = (transformSub.getPosition().x + spritePlayer.getRect().size.x) - transformPlayer.getPosition().x;
	}
	else
	{
		dxEntry = (transformSub.getPosition().x + spriteSub.getRect().size.x ) - transformPlayer.getPosition().x;
		dxExit = transformSub.getPosition().x - (transformPlayer.getPosition().x + spritePlayer.getRect().size.x);
	}

	if (velocityPlayer.getVelocity().y < 0.0f)
	{
		dyEntry = (transformSub.getPosition().y - (transformPlayer.getPosition().y - spritePlayer.getRect().size.y));
		dyExit = ((transformSub.getPosition().y - spriteSub.getRect().size.y) - transformPlayer.getPosition().y);
	}
	else
	{
		dyEntry = ((transformSub.getPosition().y - spriteSub.getRect().size.y) - transformPlayer.getPosition().y);
		dyExit = (transformSub.getPosition().y - (transformPlayer.getPosition().y - spritePlayer.getRect().size.y));
	}
	if (velocityPlayer.getVelocity().x == 0.0f)
	{
		if (dxEntry <= 0 || dxEntry >= (spritePlayer.getRect().size.x + spriteSub.getRect().size.x ))
			txEntry = std::numeric_limits<double>::infinity();
		else
			txEntry = -std::numeric_limits<double>::infinity();
		txExit = std::numeric_limits<double>::infinity();
	}
	else
	{
		txEntry = dxEntry / velocityPlayer.getVelocity().x;
		txExit = dxExit / velocityPlayer.getVelocity().x;
	}

	if (velocityPlayer.getVelocity().y == 0.0f)
	{
		// no collision respect with Oy
		if (-dyEntry <= 0 || -dyEntry >= (spritePlayer.getRect().size.y + spriteSub.getRect().size.y))
			tyEntry = std::numeric_limits<double>::infinity();
		else
			tyEntry = -std::numeric_limits<double>::infinity();
		tyExit = std::numeric_limits<double>::infinity();
	}
	else
	{
		tyEntry = dyEntry / velocityPlayer.getVelocity().y;
		tyExit = dyExit / velocityPlayer.getVelocity().y;
	}

	double entryTime = txEntry > tyEntry ? txEntry : tyEntry;
	double exitTime = txExit > tyExit ? tyExit : txExit;

	if (entryTime > exitTime || (txEntry < 0.0f && tyEntry < 0.0f) || txEntry > delta || tyEntry > delta)
	{
		/*if (i == 6 && (transformPlayer.getPosition().x + delta*velocityPlayer.getVelocity().x) < 512 && velocityPlayer.getVelocity().x < 0.f&& transformPlayer.getPosition().y <= -128)
			int dasda = 0;*/
		return delta;
	}
	/*if (i == 6)
		int dasda = 0;*/
	return entryTime;
}
bool CollisionSystem::isColliding(Transform transformPlayer, Velocity velocityPlayer, Bound boundPlayer, SpriteComponent spritePlayer, CollisionComponent *collisionPlayer,Transform transformSub, Velocity velocitySub, Bound boundSub, SpriteComponent spriteSub,CollisionComponent *collisionSub,float delta)
{
	if (boundPlayer.GRAVITY < 0.0f && collisionPlayer->dirCantMove[DOWN]) {
		velocityPlayer.setVelocity(velocityPlayer.getVelocity().x, velocityPlayer.getVelocity().y + boundPlayer.GRAVITY);
	}
	if (boundSub.GRAVITY < 0.0f && collisionSub->dirCantMove[DOWN]) {
		velocitySub.setVelocity(velocitySub.getVelocity().x, velocitySub.getVelocity().y + boundSub.GRAVITY);
	}
	collisionPlayer->timeToCollision = sweptAABB( transformPlayer,  velocityPlayer,  boundPlayer,  spritePlayer,transformSub, velocitySub, spriteSub, boundSub,delta);
	if (collisionPlayer->timeToCollision >= delta) {
		return false;
	}
	return true;

	/*if (object1.gravity < 0.0f && !object1.dirCantMove[DOWN]) {
		object1.setVelocity(Vector(velocityPlayer.getVelocity().x, (object1.getVelocity().getY() + object1.gravity)));
	}
	if (object2.gravity <0.0f && !object2.dirCantMove[DOWN])
		object2.setVelocity(Vector(object2.getVelocity().getX(), object2.getVelocity().getY() + object2.gravity));
	Collision::timeToCollision = sweptAABB(object1, object2, delta, i);
	if (Collision::timeToCollision >= delta) {
		return false;
	}
	return true;*/
	
}

