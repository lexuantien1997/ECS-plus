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
	string from,to;
	eMess(ECS::Entity* e,string _from,string _to):e1(e), from(_from),to(_to)
	{

	}
};

#endif // !MESS_H_

