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
	auto input = InputManager::getInstance();

	for (auto entity : getEntities())
	{
		auto playCon = entity->getComponent<PlayerControllable>("player control");

		auto velocity = entity->getComponent<Velocity>("velocity");

		auto bound = entity->getComponent<Bound>("bound");

		velocity->setVelocity(Vector2f(0, 0), VelocityType::normal);

		if (input->isKeyDown(playCon->controls.right,KeyState::current))
		{
			velocity->setVelocity(Vector2f(bound->SPEED, 0), VelocityType::normal);

			SendMessage(new eMess(entity));

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
