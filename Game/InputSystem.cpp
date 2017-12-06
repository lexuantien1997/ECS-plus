#include "InputSystem.h"
#include "Velocity.h"
#include "Bound.h"

using namespace ECS;
InputSystem::InputSystem()
{
	Requires<Require<PlayerControllable, AnimationComponent>>();
	Excludes<Exclude<>>();
}

InputSystem::~InputSystem()
{
}


void InputSystem::update(float dt)
{
	

	for (auto entity : getEntities())
	{
		auto playCon = entity->getComponent<PlayerControllable>("player control");

		auto velocity = entity->getComponent<Velocity>("velocity");

		auto animationCom= entity->getComponent<AnimationComponent>("animation component");

		auto bound = entity->getComponent<Bound>("bound");

		velocity->setVelocity(Vector2f(0, 0), VelocityType::normal);

		string actionName= animationCom->getCurrentAction()->getName();

		auto input = InputManager::getInstance();

		if (!input->isKeyDown(playCon->controls.right, KeyState::current))
		{
			if (animationCom->getCurrentAction()->getName() == "run_right")
			{
				actionName = "stand_right";
			}

			SendMessage(new eMess(entity, animationCom->getCurrentAction()->getName(), actionName));

		}
		if (input->isKeyDown(playCon->controls.right,KeyState::current))
		{
					
			if (animationCom->getCurrentAction()->getName()=="no_state")
			{
				actionName = "stand_right";
			}
			else if (animationCom->getCurrentAction()->getName() == "stand_right")
			{
				actionName = "run_right";
			}
			
			velocity->setVelocity(Vector2f(bound->SPEED, 0), VelocityType::normal);

			SendMessage(new eMess(entity, animationCom->getCurrentAction()->getName(), actionName));

			
		}
		else if(input->isKeyDown(playCon->controls.left, KeyState::current))
		{
			velocity->setVelocity(Vector2f(-bound->SPEED, 0), VelocityType::normal);
		}
	}
}

void InputSystem::render()
{
}

void InputSystem::init()
{
}

void InputSystem::loadResource()
{
}
