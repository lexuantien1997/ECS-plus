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

		// init:
		string actionName= animationCom->getCurrentAction()->getName();
		auto input = InputManager::getInstance();

#pragma region close  
		//auto isPressedUp = input->isKeyDown(playCon->controls.up, KeyState::current);

		//if (input->isKeyDown(playCon->controls.right, KeyState::current))
		//{
		//	if (isPressedUp)
		//	{
		//		actionName = "run_right_shoot_up";
		//	}
		//	else
		//	{
		//		actionName = "run_right";
		//	}
		//	velocity->setVelocity(Vector2f(bound->SPEED, 0), VelocityType::normal);
		//	SendMessage(new eMess(entity, animationCom->getCurrentAction()->getName(), actionName));

		//}
		//else if (input->isKeyDown(playCon->controls.left, KeyState::current))
		//{
		//	if (isPressedUp)
		//	{
		//		actionName = "run_left_shoot_up";
		//	}
		//	else
		//	{
		//		actionName = "run_left";
		//	}
		//	velocity->setVelocity(Vector2f(-bound->SPEED, 0), VelocityType::normal);
		//	SendMessage(new eMess(entity, animationCom->getCurrentAction()->getName(), actionName));
		//}
		//else
		//{
		//	velocity->setVelocity(Vector2f(0, 0), VelocityType::normal);
		//	if (isPressedUp)
		//	{
		//		actionName = "stand_left_shoot_up";
		//	}
		//	else
		//	{
		//		actionName = "stand_left";
		//	}
		//	SendMessage(new eMess(entity, animationCom->getCurrentAction()->getName(), actionName));
		//}

#pragma endregion 

		// ==================================================================================
		// RIGHT + LEFT
		// ==================================================================================

		if (input->isKeyDown(playCon->controls.LEFT,KeyState::current))
		{
			velocity->setVelocity(Vector2f(-bound->SPEED, 0));
			bound->runningRight = false;
			bound->no_state = false;
		}
		else if (input->isKeyDown(playCon->controls.RIGHT, KeyState::current))
		{
			velocity->setVelocity(Vector2f(bound->SPEED, 0));
			bound->runningRight = true;	
			bound->no_state = false;
		}

		// ==================================================================================
		// JUMP
		// ==================================================================================
		 if (input->isKeyDown(playCon->controls.JUMP, KeyState::current) && bound->onGround == true)
		{
			 // source: http://jsfiddle.net/LyM87/ make object jump
			velocity->setVelocity(Vector2f(0, -bound->HEIGHT));
			bound->onGround = false;
			bound->no_state = false;

		}

		if (!input->isKeyDown(playCon->controls.JUMP, KeyState::current) && input->isKeyDown(playCon->controls.JUMP, KeyState::previous))
		{			
			if (velocity->getVelocity().y<=-bound->JUMP_1)
			{
				velocity->setVelocity(Vector2f(0, -bound->JUMP_1));
			}
			bound->no_state = false;
		}

		// ==================================================================================
		// UP
		// ==================================================================================
		if (input->isKeyDown(playCon->controls.UP, KeyState::current) == true)
		{
			bound->shoot_up = true;
			bound->no_state = false;
			bound->rolling = false;
		}
		 if(input->isKeyDown(playCon->controls.UP, KeyState::current) == false)
		{
			bound->shoot_up = false;
			bound->no_state = false;
		}

		// ==================================================================================
		// SHOOT
		// ==================================================================================

		if (input->isKeyDown(playCon->controls.SHOOT, KeyState::current) == true)
		{
			bound->shoot_straight = true;
			bound->no_state = false;
			bound->rolling = false;
		}
		else if (input->isKeyDown(playCon->controls.SHOOT, KeyState::current) == false)
		{
			bound->shoot_straight = false;
			bound->no_state = false;
		}

		// ==================================================================================
		// ROLLING
		// ==================================================================================
		if (input->isKeyDown(playCon->controls.DOWN, KeyState::current) == true)
		{
			bound->rolling = true;
			bound->no_state = false;
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
