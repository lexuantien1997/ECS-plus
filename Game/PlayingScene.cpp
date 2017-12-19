#include "PlayingScene.h"



PlayingScene::PlayingScene(string name):Scene(name)
{
	
}


PlayingScene::~PlayingScene()
{

}

void PlayingScene::update(float dt)
{
	inputSystem.update(dt);
	stateSystem.update(dt);
	movementSystem.update(dt);
	animationSystem.update(dt);
	renderSystem.update(dt);
}

void PlayingScene::init()
{
	// SYSTEMS
	world->addSystem(renderSystem);
	world->addSystem(inputSystem);
	world->addSystem(movementSystem);
	world->addSystem(animationSystem);
	world->addSystem(stateSystem);
	world->addSystem(mapSystem);
	// ENTITY
	Entity* samus = world->create_Entity("samus");
	
	// COMPONENTS
	samus->addComponent<PlayerControllable>("player control");
	StateComponent* stateComp = samus->addComponent<StateComponent>("state component");
	Transform* transformComp = samus->addComponent<Transform>("transform component");
	Bound* bound= samus->addComponent<Bound>("bound");
	Velocity* velocity = samus->addComponent<Velocity>("velocity");
	Gravity* gravity = samus->addComponent<Gravity>("gravity");
	SpriteComponent* spriteComp = samus->addComponent<SpriteComponent>("sprite component");
	AnimationComponent* animationComp= samus->addComponent<AnimationComponent>("animation component");

	// INIT COMPONENTS
	stateComp->initStateComponent("no_state");
	Sprite* samus_sprite= static_cast<Sprite*>(SpriteManager::getInstance()->find("samus_aran.png"));
	animationComp->initAnimationComponent("no_state", "samus_states.xml");
	spriteComp->initSpriteComponent(samus_sprite, Rect(Vector2f(184, 36), Vector2f(18,34)));
	transformComp->initTransform(Vector2f(100,-110), Vector2f(50, 50), Vector2f(2, 2), 0);
	velocity->initVelocity(Vector2f(0, 0));
	gravity->initGravity(-9.8f);

	//
	Entity* Map = world->create_Entity("map");
	//Entity *e = new Entity(0);
	Transform* maptransformComp = Map->addComponent<Transform>("transform component");
	SpriteComponent* TilesetComponent = Map->addComponent<SpriteComponent>("sprite component");
	MapComponent* mapComp = Map->addComponent<MapComponent>("map component");

	Sprite* Tileset = static_cast<Sprite*>(SpriteManager::getInstance()->find("tiles.png"));
	TilesetComponent->initSpriteComponent(Tileset, Rect(Vector2f(0, 0), Vector2f(16, 16)));
	maptransformComp->initTransform(Vector2f(0, -0), Vector2f(0, 0), Vector2f(1, 1), 0);
	mapComp->InitMapComponent();

	//
	Entity* Skree = world->create_Entity("Skree");
	auto skreeTransform = Skree->addComponent<Transform>("transform component");
	auto skreeSpriteComp = Skree->addComponent<SpriteComponent>("sprite component");
	auto skreeAnimationComp = Skree->addComponent<AnimationComponent>("animation component");
	auto skreeVelocity = Skree->addComponent<Velocity>("velocity");
	auto skreeBound = Skree->addComponent<Bound>("bound"); // tại sao phải add cái này mới có trong movement

	skreeTransform->initTransform(Vector2f(300, -20), Vector2f(0, 0), Vector2f(2, 2), NULL);
	auto skreeSprite = static_cast<Sprite*>(SpriteManager::getInstance()->find("enemies.png"));
	skreeSpriteComp->initSpriteComponent(skreeSprite, Rect(Vector2f(15, 30), Vector2f(16, 24)));
	skreeAnimationComp->initAnimationComponent("", "enemies.xml");
	skreeVelocity->initVelocity(Vector2f(0.03, 0.03));

	// Add state into State Component:

	// ========================================================================================
	// NO STATE
	// ========================================================================================
	State* no_state= new State("no_state",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("no_state"));
	}, NULL, NULL);

	// ========================================================================================
	// STAND
	// ========================================================================================
	State* stand_left = new State("stand_left",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("stand"));
	}, NULL, NULL);

	State* stand_right= new State("stand_right",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("stand"));
	}, NULL, NULL);

	// ========================================================================================
	// RUN
	// ========================================================================================
	State* run_left=new State("run_left",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("run"));
	}, NULL, NULL);

	State* run_right= new State("run_right",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("run"));
	}, NULL, NULL);

	// ========================================================================================
	// STAND SHOOT UP
	// ========================================================================================

	State* stand_shoot_up_left = new State("stand_shoot_up_left",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("stand_shoot_up"));
	}, NULL, NULL);

	State* stand_shoot_up_right = new State("stand_shoot_up_right",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("stand_shoot_up"));
	}, NULL, NULL);

	// ========================================================================================
	// RUN SHOOT UP
	// ========================================================================================
	State* run_shoot_up_left = new State("run_shoot_up_left",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("run_shoot_up"));
	}, NULL, NULL);

	State* run_shoot_up_right = new State("run_shoot_up_right",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("run_shoot_up"));
	}, NULL, NULL);

	// ========================================================================================
	// ROLLING
	// ========================================================================================

	State* rolling_left = new State("rolling_left",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("rolling"));
	}, NULL, NULL);

	State* rolling_right = new State("rolling_right",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("rolling"));
	}, NULL, NULL);

	// ========================================================================================
	// RUN SHOOT 
	// ========================================================================================

	State* run_shoot_left = new State("run_shoot_left",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("run_shoot"));
	}, NULL, NULL);

	State* run_shoot_right = new State("run_shoot_right",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("run_shoot"));
	}, NULL, NULL);

	// ========================================================================================
	// JUMP
	// ========================================================================================

	State* jump_left = new State("jump_left",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("jump"));
	}, NULL, NULL);

	State* jump_right = new State("jump_right",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("jump"));
	}, NULL, NULL);


	// ========================================================================================
	// JUMP shoot
	// ========================================================================================

	State* jump_shoot = new State("jump_shoot",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("jump_shoot"));
	}, NULL, NULL);

	// ========================================================================================
	// JUMP shoot up
	// ========================================================================================

	State* jump_shoot_up = new State("jump_shoot_up",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("jump_shoot_up"));
	}, NULL, NULL);

	// ========================================================================================
	// Turning
	// ========================================================================================

	State* turning = new State("turning",
		[=] {
		auto animationComp = samus->getComponent<AnimationComponent>("animation component");
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("turning"));
	}, NULL, NULL);

	stateComp->addState(no_state);

	stateComp->addState(stand_left);
	stateComp->addState(stand_right);

	stateComp->addState(run_left);
	stateComp->addState(run_right);

	stateComp->addState(stand_shoot_up_left);
	stateComp->addState(stand_shoot_up_right);

	stateComp->addState(run_shoot_up_left);
	stateComp->addState(run_shoot_up_right);

	stateComp->addState(rolling_left);
	stateComp->addState(rolling_right);

	stateComp->addState(run_shoot_left);
	stateComp->addState(run_shoot_right);

	stateComp->addState(jump_left);
	stateComp->addState(jump_right);

	stateComp->addState(jump_shoot);

	stateComp->addState(jump_shoot_up);

	stateComp->addState(turning);

	// State Transitions

	// ======================================================================================
	// Make no_state => stand
	// ======================================================================================

	no_state->addTransition(new Transition("no_state", "stand_left", [] {
		return InputManager::getInstance()->getKeyDown(DIK_LEFT)==true;
	}));

	no_state->addTransition(new Transition("no_state", "stand_right", [] {
		return InputManager::getInstance()->getKeyDown(DIK_RIGHT) == true;
	}));

	no_state->addTransition(new Transition("no_state", "stand_shoot_up_right", [=] {
		return InputManager::getInstance()->isKeyDown(DIK_UP,KeyState::current) == true && bound->runningRight==true;
	}));

	// ======================================================================================
	// Make no_state => jump
	// ======================================================================================

	no_state->addTransition(new Transition("no_state", "jump_left", [] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true;
	}));

	no_state->addTransition(new Transition("no_state", "jump_right", [] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true;
	}));


	// ======================================================================================
	// Make stand => run
	// ======================================================================================
	stand_left->addTransition(new Transition("stand_left", "run_left", [] {
		return InputManager::getInstance()->isKeyDown(DIK_LEFT,KeyState::current) == true;
	}));

	stand_left->addTransition(new Transition("stand_left", "run_right", [] {
		return InputManager::getInstance()->isKeyDown(DIK_RIGHT, KeyState::current) == true;
	}));

	stand_right->addTransition(new Transition("stand_right", "run_right", [] {
		return InputManager::getInstance()->isKeyDown(DIK_RIGHT, KeyState::current) == true;
	}));
	
	stand_right->addTransition(new Transition("stand_right", "run_left", [] {
		return InputManager::getInstance()->isKeyDown(DIK_LEFT, KeyState::current) == true;
	}));

	// ======================================================================================
	// Make stand => jump
	// ======================================================================================

	stand_left->addTransition(new Transition("stand_left", "jump_left", [] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true;
	}));

	stand_right->addTransition(new Transition("stand_right", "jump_right", [] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true;
	}));

	// ======================================================================================
	// Make stand => rolling
	// ======================================================================================

	stand_left->addTransition(new Transition("stand_left", "rolling_left", [] {
		return InputManager::getInstance()->getKeyDown(DIK_DOWN) == true;
	}));

	stand_right->addTransition(new Transition("stand_right", "rolling_right", [] {
		return InputManager::getInstance()->getKeyDown(DIK_DOWN) == true;
	}));


	// ======================================================================================
	// Make run => turning
	// ======================================================================================
	
	run_left->addTransition(new Transition("run_left", "turning", [] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true;
	}));

	run_right->addTransition(new Transition("run_right", "turning", [] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true;
	}));

	// ======================================================================================
	// Make run => run shoot
	// ======================================================================================

	run_left->addTransition(new Transition("run_left", "run_shoot_left", [] {
		return InputManager::getInstance()->isKeyDown(DIK_LEFT, KeyState::current)==true 
			&& InputManager::getInstance()->isKeyDown(DIK_X, KeyState::current) == true ;
	}));

	run_right->addTransition(new Transition("run_right", "run_shoot_right", [] {
		return InputManager::getInstance()->isKeyDown(DIK_RIGHT, KeyState::current) == true
			&& InputManager::getInstance()->isKeyDown(DIK_X, KeyState::current) == true;
	}));

	// ======================================================================================
	// Make run => stand
	// ======================================================================================
	
	run_left->addTransition(new Transition("run_left", "stand_left", [] {
		return InputManager::getInstance()->getKeyUp(DIK_LEFT) == true;
	}));
	
	run_left->addTransition(new Transition("run_left", "stand_right", [] {
		return InputManager::getInstance()->getKeyDown(DIK_RIGHT) == true;
	}));

	run_right->addTransition(new Transition("run_right", "stand_right", [] {
		return InputManager::getInstance()->getKeyUp(DIK_RIGHT) == true;
	}));

	run_right->addTransition(new Transition("run_right", "stand_left", [] {
		return InputManager::getInstance()->getKeyDown(DIK_LEFT) == true;
	}));

	// ======================================================================================
	// Make run => run shoot up
	// ======================================================================================

	run_left->addTransition(new Transition("run_left", "run_shoot_up_left", [] {
		return InputManager::getInstance()->isKeyDown(DIK_LEFT, KeyState::current) == true 
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	run_right->addTransition(new Transition("run_right", "run_shoot_up_right", [] {
		return InputManager::getInstance()->isKeyDown(DIK_RIGHT, KeyState::current) == true
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	// ======================================================================================
	// Make stand shoot up => stand
	// ======================================================================================

	stand_shoot_up_left->addTransition(new Transition("stand_shoot_up_left", "stand_left", [] {
		return InputManager::getInstance()->getKeyUp(DIK_UP) == true;
	}));

	stand_shoot_up_right->addTransition(new Transition("stand_shoot_up_right", "stand_right", [] {
		return InputManager::getInstance()->getKeyUp(DIK_UP) == true ;
	}));

	// ======================================================================================
	// Make stand shoot up => jump shoot up
	// ======================================================================================

	stand_shoot_up_left->addTransition(new Transition("stand_shoot_up_left", "jump_shoot_up", [=] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true && bound->onGround==false 
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	stand_shoot_up_right->addTransition(new Transition("stand_shoot_up_right", "jump_shoot_up", [=] {
		return InputManager::getInstance()-> getKeyDown(DIK_Z) == true && bound->onGround == false
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	// ======================================================================================
	// Make stand shoot up => run shoot up
	// ======================================================================================

	stand_shoot_up_left->addTransition(new Transition("stand_shoot_up_left", "run_shoot_up_left", [] {
		return InputManager::getInstance()->isKeyDown(DIK_LEFT, KeyState::current) == true 
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	stand_shoot_up_left->addTransition(new Transition("stand_shoot_up_left", "run_shoot_up_right", [] {
		return InputManager::getInstance()->isKeyDown(DIK_RIGHT, KeyState::current) == true
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	stand_shoot_up_right->addTransition(new Transition("stand_shoot_up_right", "run_shoot_up_left", [] {
		return InputManager::getInstance()->isKeyDown(DIK_LEFT, KeyState::current) == true
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	stand_shoot_up_right->addTransition(new Transition("stand_shoot_up_right", "run_shoot_up_right", [] {
		return InputManager::getInstance()->isKeyDown(DIK_RIGHT, KeyState::current) == true
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	// ======================================================================================
	// Make run shoot up => stand shoot up
	// ======================================================================================

	run_shoot_up_left->addTransition(new Transition("run_shoot_up_left", "stand_shoot_up_left", [] {
		return InputManager::getInstance()->getKeyUp(DIK_LEFT) == true 
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	run_shoot_up_right->addTransition(new Transition("run_shoot_up_right", "stand_shoot_up_right", [] {
		return InputManager::getInstance()->getKeyUp(DIK_RIGHT) == true
			&& InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	// ======================================================================================
	// Make run shoot up => run
	// ======================================================================================
	
	run_shoot_up_left->addTransition(new Transition("run_shoot_up_left", "run_left", [] {
		return InputManager::getInstance()->getKeyUp(DIK_UP) == true
			&& InputManager::getInstance()->isKeyDown(DIK_LEFT, KeyState::current) == true;
	}));

	run_shoot_up_right->addTransition(new Transition("run_shoot_up_right", "run_right", [] {
		return InputManager::getInstance()->getKeyUp(DIK_UP) == true
			&& InputManager::getInstance()->isKeyDown(DIK_RIGHT, KeyState::current) == true;
	}));

	// ======================================================================================
	// Make run shoot up => stand
	// ======================================================================================

	run_shoot_up_left->addTransition(new Transition("run_shoot_up_left", "stand_left", [] {
		return InputManager::getInstance()->getKeyUp(DIK_UP) == true
			&& InputManager::getInstance()->getKeyUp(DIK_LEFT)== true;
	}));

	run_shoot_up_right->addTransition(new Transition("run_shoot_up_right", "stand_right", [] {
		return InputManager::getInstance()->getKeyUp(DIK_UP) == true
			&& InputManager::getInstance()->getKeyUp(DIK_RIGHT) == true;
	}));

	// ======================================================================================
	// Make stand => stand shoot up
	// ======================================================================================
	stand_left->addTransition(new Transition("stand_left", "stand_shoot_up_left", [] {
		return InputManager::getInstance()->isKeyDown(DIK_UP,KeyState::current) == true;
	}));

	stand_right->addTransition(new Transition("stand_right", "stand_shoot_up_right", [] {
		return InputManager::getInstance()->isKeyDown(DIK_UP, KeyState::current) == true;
	}));

	// ======================================================================================
	// Make rolling => stand
	// ======================================================================================
	
	rolling_left->addTransition(new Transition("rolling_left", "stand_left", [] {
		return InputManager::getInstance()->getKeyUp(DIK_UP) == true
			|| InputManager::getInstance()->getKeyUp(DIK_Z) == true;
	}));

	rolling_right->addTransition(new Transition("rolling_right", "stand_right", [] {
		return InputManager::getInstance()->getKeyUp(DIK_UP) == true
			|| InputManager::getInstance()->getKeyUp(DIK_Z) == true;
	}));

	// ======================================================================================
	// Make run shoot => run
	// ======================================================================================
	
	run_shoot_left->addTransition(new Transition("run_shoot_left", "run_left", [] {
		return InputManager::getInstance()->isKeyDown(DIK_LEFT, KeyState::current) == true
			&& InputManager::getInstance()->getKeyUp(DIK_X) == true;
	}));

	run_shoot_right->addTransition(new Transition("run_shoot_right", "run_right", [] {
		return InputManager::getInstance()->isKeyDown(DIK_RIGHT, KeyState::current) == true
			&& InputManager::getInstance()->getKeyUp(DIK_X) == true;
	}));

	// ======================================================================================
	// Make run shoot => stand
	// ======================================================================================

	run_shoot_left->addTransition(new Transition("run_shoot_left", "stand_left", [] {
		return InputManager::getInstance()->getKeyUp(DIK_LEFT) == true
			&& InputManager::getInstance()->getKeyUp(DIK_X) == true;
	}));

	run_shoot_left->addTransition(new Transition("run_shoot_left", "stand_right", [] {
		return InputManager::getInstance()->getKeyDown(DIK_RIGHT) == true;
	}));

	run_shoot_right->addTransition(new Transition("run_shoot_right", "stand_left", [] {
		return InputManager::getInstance()->getKeyDown(DIK_LEFT) == true;
	}));

	run_shoot_right->addTransition(new Transition("run_shoot_right", "stand_right", [] {
		return InputManager::getInstance()->getKeyUp(DIK_RIGHT) == true
			&& InputManager::getInstance()->getKeyUp(DIK_X) == true;
	}));

	// ======================================================================================
	// Make run shoot up => jump
	// ======================================================================================

	run_shoot_up_left->addTransition(new Transition("run_shoot_up_left", "jump_left", [] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true;
	}));

	run_shoot_up_right->addTransition(new Transition("run_shoot_up_right", "jump_right", [] {
		return InputManager::getInstance()->getKeyDown(DIK_Z) == true;
	}));

	// ======================================================================================
	// Make jump => stand
	// ======================================================================================

	jump_right->addTransition(new Transition("jump_right", "stand_right", [=] {
		return bound->onGround == true;
	}));

	jump_left->addTransition(new Transition("jump_left", "stand_left", [=] {
		return bound->onGround == true;
	}));

	// ======================================================================================
	// Make jump => jump shoot
	// ======================================================================================

	jump_right->addTransition(new Transition("jump_right", "jump_shoot", [=] {
		return bound->onGround == false && InputManager::getInstance()->getKeyDown(DIK_X) == true;
	}));

	jump_left->addTransition(new Transition("jump_left", "jump_shoot", [=] {
		return bound->onGround == false && InputManager::getInstance()->getKeyDown(DIK_X) == true;
	}));


	// ======================================================================================
	// Make jump => jump shoot up
	// ======================================================================================

	jump_right->addTransition(new Transition("jump_right", "jump_shoot_up", [=] {
		return bound->onGround == false && InputManager::getInstance()->getKeyDown(DIK_UP) == true;
	}));

	jump_left->addTransition(new Transition("jump_left", "jump_shoot_up", [=] {
		return bound->onGround == false && InputManager::getInstance()->getKeyDown(DIK_UP) == true;
	}));


	// ======================================================================================
	// Make jump shoot => stand
	// ======================================================================================

	jump_shoot->addTransition(new Transition("jump_shoot", "stand_left", [=] {
		return bound->onGround == true ;
	}));

	jump_shoot->addTransition(new Transition("jump_shoot", "stand_right", [=] {
		return bound->onGround == true;
	}));

	// ======================================================================================
	// Make jump shoot up => stand
	// ======================================================================================

	jump_shoot_up->addTransition(new Transition("jump_shoot_up", "stand_left", [=] {
		return bound->onGround == true;
	}));

	jump_shoot_up->addTransition(new Transition("jump_shoot_up", "stand_right", [=] {
		return bound->onGround == true;
	}));


	// ======================================================================================
	// Make turning => stand
	// ======================================================================================
	
	turning->addTransition(new Transition("turning", "stand_right", [=] {
		return bound->onGround == true;
	}));

	turning->addTransition(new Transition("turning", "stand_left", [=] {
		return bound->onGround == true;
	}));

	// refresh the game world:
	world->refresh();

	stateSystem.init("no_state");

	
}

void PlayingScene::render()
{
	inputSystem.render();
	movementSystem.render();
	mapSystem.render();
	renderSystem.render();
}

void PlayingScene::release()
{

}
