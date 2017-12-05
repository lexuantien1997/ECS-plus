#ifndef MESS_H_
#define MESS_H_

#include "../ECS Plus/_ECS_Header.h"
using namespace ECS;

struct Mess
{

};

struct eMess :Mess
{
public:
	ECS::Entity* e1;
	eMess(ECS::Entity* e):e1(e)
	{

	}
};

#endif // !MESS_H_

