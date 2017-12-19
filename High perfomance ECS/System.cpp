#include "System.h"
#include "GameWorld.h"



void ECS::System::removeEntity(Entity * e)
{
	activeEntities.erase(std::remove(activeEntities.begin(), activeEntities.end(), e), activeEntities.end());
}

void ECS::System::addEntity(Entity * e)
{
	activeEntities.push_back(e);
}

void ECS::System::setSystemBits(int pos, bool value)
{
	systemBits[pos] = value;
}

bitset<BITSIZE> ECS::System::getSystemBits()
{
	return systemBits;
}

bool ECS::System::checkCondition(Entity * e)
{
	// Kiểm tra những thứ mà `System` yêu cầu có `Entity` nó có không
	for (size_t i = 0; i < requireBits.size(); i++)
	{
		// Nếu trong những thứ mà `System` bắt buộc có mà `Entity` không có thì return false luôn
		if (requireBits[i] && !e->getCompBits()[i])
			return false;
	}

	// Nếu như Entity có những thứ mà System cần thì tiếp tục kiểm tra những thứ
	// system yêu cầu không được có
	for (size_t i = 0; i < excludeBits.size(); i++)
	{
		// Nếu có bất cứ component nào mà cả 2 đều có thì return false luôn
		if (excludeBits[i] && e->getCompBits()[i])
			return false;
	}

	// Thỏa hết tất cả điều kiện
	return true;

}

void ECS::System::checkConditionExcludeAndRequire(Entity * e)
{
	bool contains = (systemBits & e->getSystemsBits()) == systemBits;
	bool check = checkCondition(e);

	if (check && !contains)
	{
		addEntity(e);
		e->addSystemBits(systemBits);
	}
	else if (!check && contains)
	{
		removeEntity(e);
		e->removeSystemBits(systemBits);
	}
	
	/*bool requires = (requireBits & e->getCompBits()) == requireBits;
	bool excludes = (excludeBits & e->getCompBits()) == excludeBits;
	if (requires && !excludes && !contains)
	{
		addEntity(e);
		e->addSystemBits(systemBits);
	}
	else if ((!requires || excludes) && contains)
	{
		removeEntity(e);
		e->removeSystemBits(systemBits);
	}*/
}

ECS::System::System()
{

}

ECS::System::~System()
{
	activeEntities.clear();
	world = NULL;
}
