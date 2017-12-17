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

	for (Entity* entity : getEntities())
	{
		if (entity->getName() == "intro")
		{
			if (InputManager::getInstance()->isKeyDown(DIK_RETURN, KeyState::current))
			{
				SceneManager::getInstance()->removeScene();
			}
		}
		else
		{
			PlayerControllable* playCon = entity->getComponent<PlayerControllable>("player control");
			Velocity* velocity = entity->getComponent<Velocity>("velocity");
			AnimationComponent* animationCom = entity->getComponent<AnimationComponent>("animation component");
			Bound* bound = entity->getComponent<Bound>("bound");

			// init:
			string actionName = animationCom->getCurrentAction()->getName();
			InputManager* input = InputManager::getInstance();


			// ==================================================================================
			// RIGHT + LEFT
			// ==================================================================================

			if (input->isKeyDown(playCon->controls.LEFT, KeyState::current))
			{
				//if (input->getKeyDown(playCon->controls.JUMP))
				//{
				//	bound->turning = true;
				//	velocity->setVelocity(Vector2f(-bound->SPEED, velocity->getVelocity().y));
				//}
				//else {
				//	velocity->setVelocity(Vector2f(-bound->SPEED, velocity->getVelocity().y));
				//	bound->runningRight = false;
				//	bound->no_state = false;
				//}
				Vector2i camPos = getGameWorld()->cam.getCamPosition();
				camPos.x = camPos.x - 2;
				getGameWorld()->cam.setCamPosition(camPos);
				velocity->setVelocity(Vector2f(-bound->SPEED, velocity->getVelocity().y));
				bound->runningRight = false;
			}
			else if (input->isKeyDown(playCon->controls.RIGHT, KeyState::current))
			{
				/*if (input->getKeyDown(playCon->controls.JUMP) )
				{
				bound->turning = true;
				velocity->setVelocity(Vector2f(bound->SPEED, velocity->getVelocity().y));
				}
				else {
				velocity->setVelocity(Vector2f(bound->SPEED, velocity->getVelocity().y));
				bound->runningRight = true;
				bound->no_state = false;
				}*/
				Vector2i camPos = getGameWorld()->cam.getCamPosition();
				camPos.x = camPos.x + 2;
				getGameWorld()->cam.setCamPosition(camPos);
				Vector2i c = getGameWorld()->cam.getCamPosition();
				velocity->setVelocity(Vector2f(bound->SPEED, velocity->getVelocity().y));
				bound->runningRight = true;
			}

			// ==================================================================================
			// JUMP
			// ==================================================================================

			if (bound->onGround == true && input->getKeyDown(playCon->controls.JUMP) == true)
			{
				//if (bound->rolling == true)
				//{
				//bound->rolling = false;
				//}
				//else if(bound->rolling == false && animationCom->getPreviousAction()->getName()!="rolling")
				//{
				//// source: http://jsfiddle.net/LyM87/ make object jump
				//velocity->setVelocity(Vector2f(velocity->getVelocity().x, -bound->HEIGHT));
				//bound->onGround = false;
				//bound->no_state = false;
				//}
				velocity->setVelocity(Vector2f(velocity->getVelocity().x, bound->HEIGHT));
				bound->onGround = false;

			}

			else if (input->getKeyUp(playCon->controls.JUMP))
			{

				//if (velocity->getVelocity().y<=-bound->JUMP_1)
				//{
				//	velocity->setVelocity(Vector2f(velocity->getVelocity().x, -bound->JUMP_1));
				//}
				//if (bound->onGround==true)
				//{
				//	bound->turning = false;
				//}
				//
				//bound->no_state = false;
				if (velocity->getVelocity().y >= -bound->JUMP_1)
				{
					velocity->setVelocity(Vector2f(velocity->getVelocity().x, -bound->JUMP_1));
				}
			}

			// ==================================================================================
			// UP
			// ==================================================================================
			/*if (input->isKeyDown(playCon->controls.UP, KeyState::current) == true)
			{
			bound->shoot_up = true;
			bound->no_state = false;
			bound->rolling = 0;
			}
			if(input->isKeyDown(playCon->controls.UP, KeyState::current) == false)
			{
			bound->shoot_up = false;
			bound->no_state = false;
			}*/

			// ==================================================================================
			// SHOOT
			// ==================================================================================

			//if (input->isKeyDown(playCon->controls.SHOOT, KeyState::current) == true)
			//{
			//	bound->shoot_straight = true;
			//	bound->no_state = false;

			//}
			//else if (input->isKeyDown(playCon->controls.SHOOT, KeyState::current) == false)
			//{
			//	bound->shoot_straight = false;
			//	bound->no_state = false;
			//}

			// ==================================================================================
			// ROLLING
			// ==================================================================================
			/*if (input->isKeyDown(playCon->controls.DOWN, KeyState::current) == true)
			{
			if (bound->onGround==true)
			{
			bound->rolling = true;
			bound->no_state = false;
			}
			}*/
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
