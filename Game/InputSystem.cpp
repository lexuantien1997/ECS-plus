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


		// ==================================================================================
		// RIGHT + LEFT
		// ==================================================================================
		if (input->isKeyDown(playCon->controls.RIGHT, KeyState::current))
		{

		    velocity->setVelocity(Vector2f(bound->SPEED, velocity->getVelocity().y));
		    bound->runningRight = true;

		}
		else if (input->isKeyDown(playCon->controls.LEFT,KeyState::current))
		{
		    
		    velocity->setVelocity(Vector2f(-bound->SPEED, velocity->getVelocity().y));
		    bound->runningRight = false;
			
		}
		 

		// ==================================================================================
		// JUMP
		// ==================================================================================
		
		 if (bound->onGround == true && input->getKeyDown(playCon->controls.JUMP)==true)
		 {

			// source: http://jsfiddle.net/LyM87/ make object jump

			 velocity->setVelocity(Vector2f(velocity->getVelocity().x, bound->HEIGHT));
			 bound->onGround = false;
			 
		 }

		 else if (input->getKeyUp(playCon->controls.JUMP))
		{

			if (velocity->getVelocity().y>=-bound->JUMP_1)
			{
				velocity->setVelocity(Vector2f(velocity->getVelocity().x, -bound->JUMP_1));
			}
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
