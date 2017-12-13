#include "StateSystem.h"



void StateSystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		auto stateComp = entity->getComponent<StateComponent>("state component");
		State* nextState = NULL;
		auto currentState = stateComp->getCurrentState();

		// Kiểm tra từng transition của trạng thái hiện tại
		// Nếu thỏa điều kiện sang trạng thái tiếp theo thì trả về trạng thái tiếp theo
		// Ngược lại thì thôi
		for (auto transition : currentState->getTransitions())
		{
			if (transition->condition != NULL)
			{
				if (transition->condition() == true)
				{
					nextState=stateComp->findState(transition->getName());
				}
			}
		}

		// Nếu thỏa điều kiện trạng thái tiếp theo:
		// Thì chuyển sang trạng thái tiếp theo
		// Ngược lại thì cập nhật 1 vài thứ cho trạng thái hiện tại như thay đổi tốc độ, thay đổi scale
		if (nextState != NULL) 
		{
			stateComp->changeState(nextState);
		}
		else
		{
			if (currentState->update != NULL) {
				currentState->update(dt);
			}
		}
	}
}

void StateSystem::render()
{

}

void StateSystem::init()
{

}

void StateSystem::init(string stateName)
{
	for (auto entity : getEntities())
	{
		auto stateComp = entity->getComponent<StateComponent>("state component");

		stateComp->serCurrentState(stateComp->findState(stateName));
		if (stateComp->getCurrentState()->enter != NULL)
		{
			stateComp->getCurrentState()->enter();
			stateComp->serPreviousState(stateComp->getCurrentState());
		}
	}
}

void StateSystem::loadResource()
{
}

StateSystem::StateSystem()
{
	Requires<Require<StateComponent>>();
	Excludes<Exclude<>>();
}


StateSystem::~StateSystem()
{
}
