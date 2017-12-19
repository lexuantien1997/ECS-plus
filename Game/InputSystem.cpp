#include "InputSystem.h"
#include "Velocity.h"
#include "Bound.h"

using namespace ECS;
InputSystem::InputSystem()
{
	requireComponent<Bound>();
	requireComponent<Velocity>();
}

InputSystem::~InputSystem()
{
}


void InputSystem::update(float dt)
{

	for (auto entity : getEntities())
	{
		auto velocity = entity->getComponent<Velocity>();
		auto bound = entity->getComponent<Bound>();


		auto input = InputManager::getInstance();


		// ==================================================================================
		// RIGHT + LEFT
		// ==================================================================================
		if (input->isKeyDown(DIK_RIGHT, KeyState::current))
		{

		    velocity->setVelocity(Vector2f(bound->SPEED, velocity->getVelocity().y));
		    bound->runningRight = true;

		}
		else if (input->isKeyDown(DIK_LEFT,KeyState::current))
		{
		    
		    velocity->setVelocity(Vector2f(-bound->SPEED, velocity->getVelocity().y));
		    bound->runningRight = false;
			
		}
		 

		// ==================================================================================
		// JUMP
		// ==================================================================================
		
		 if (bound->onGround == true && input->getKeyDown(DIK_Z)==true)
		 {

			// source: http://jsfiddle.net/LyM87/ make object jump

			 velocity->setVelocity(Vector2f(velocity->getVelocity().x, bound->HEIGHT));
			 bound->onGround = false;
			 
		 }
		else if (input->getKeyUp(DIK_Z))
		{

			if (velocity->getVelocity().y>=-bound->JUMP_1)
			{
				velocity->setVelocity(Vector2f(velocity->getVelocity().x, -dt));
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
