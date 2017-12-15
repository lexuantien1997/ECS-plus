#include "MapSystem.h"
#include <sstream>



MapSystem::MapSystem()
{
	Requires<Require<SpriteComponent, MapComponent, Transform>>();
	Excludes<Exclude<>>();
}

void MapSystem::update(float dt)
{
}

void MapSystem::render()
{
	for (auto entity : getEntities())
	{
		//if (entity->getName() == "map")
		{
			auto transform = entity->getComponent<Transform>("transform component");
			auto spriteComp = entity->getComponent<SpriteComponent>("sprite component");
			auto mapComp = entity->getComponent<MapComponent>("map component");

			int _xOld = transform->getPosition().x;
			int _yOld = transform->getPosition().y;

			for (int i = 0; i < mapComp->map->getRow(); i++)
			{
				for (int j = 0; j < mapComp->map->getColumn(); j++)
				{
					int x = mapComp->map->getSize().x * j;
					int y = mapComp->map->getSize().y * i;
					int camX = getGameWorld()->cam.getCamPosition().x;
					int camY = getGameWorld()->cam.getCamPosition().y;
					if (mapComp->map->value[i][j] != 0)
					{
						spriteComp->setRect(Rect(((mapComp->map->value[i][j] - 1) % 11) * 16, ((mapComp->map->value[i][j] - 1) / 11) * 16, 16, 16));
						SpriteManager::getInstance()->draw(spriteComp, transform, getGameWorld()->cam);
						/*std::ostringstream ss;
						ss << "x: " << spriteComp->getRect().left_top.x << " , y: " << spriteComp->getRect().left_top.y << endl;
						OutputDebugStringA(ss.str().c_str());*/
						
						//mapComp->map->value[i][j].setPositionInCamera(x, -y);
					}
					transform->moving(16, 0);
				}
				//transform->moving(0, 16);
				transform->setPosition(0, transform->getPosition().y - 16);
			}
			transform->setPosition(_xOld, _yOld);
			break;
		}
	}
}

void MapSystem::init()
{
}



void MapSystem::loadResource()
{
}

MapSystem::~MapSystem()
{
}
