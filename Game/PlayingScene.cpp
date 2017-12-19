#include "PlayingScene.h"



PlayingScene::PlayingScene(string name):Scene(name)
{
	
}


PlayingScene::~PlayingScene()
{

}

void PlayingScene::render()
{
	mapSystem.render();
	renderSystem.render();
}

void PlayingScene::update(float dt)
{
	inputSystem.update(dt);
	stateSystem.update(dt);
	movementSystem.update(dt);
	animationSystem.update(dt);
}

void PlayingScene::release()
{

}



void PlayingScene::init()
{

	initSystem();

	initEntity();

	// refresh the game world:
	world->loop2RefreshAndRemove();

	stateSystem.init("no_state");	
}

void PlayingScene::initSystem()
{

	// SYSTEMS
	world->addSystem(renderSystem);
	world->addSystem(inputSystem);
	world->addSystem(movementSystem);
	world->addSystem(animationSystem);
	world->addSystem(stateSystem);
	world->addSystem(mapSystem);
}

void PlayingScene::initEntity()
{

	// Create the entity
	Entity* samus = world->createEntity(EntityName::SAMUS);
	Entity* Map = world->createEntity(EntityName::MAP);

	Map->refresh();
	samus->refresh();
	// ===================================================================================================
	// create components for `samus`
	// ===================================================================================================

	auto stateComp = samus->addComponent<StateComponent>();
	auto transformComp = samus->addComponent<Transform>();
	auto bound = samus->addComponent<Bound>();
	auto velocity = samus->addComponent<Velocity>();
	auto gravity = samus->addComponent<Gravity>();
	auto spriteComp = samus->addComponent<SpriteComponent>();
	auto animationComp = samus->addComponent<AnimationComponent>();


	// ===================================================================================================
	// create components for `map`
	// ===================================================================================================

	auto maptransformComp = Map->addComponent<Transform>();
	auto TilesetComponent = Map->addComponent<SpriteComponent>();
	auto mapComp = Map->addComponent<MapComponent>();

	// ===================================================================================================
	// init components for `samus`
	// ===================================================================================================

	stateComp->initStateComponent("no_state");
	auto samus_sprite = static_cast<Sprite*>(SpriteManager::getInstance()->find("samus_aran.png"));
	animationComp->initAnimationComponent("no_state", "samus_states.xml");
	spriteComp->initSpriteComponent(samus_sprite, Rect(Vector2f(184, 36), Vector2f(18, 34)));
	transformComp->initTransform(Vector2f(0, 0), Vector2f(50, 50), Vector2f(2, 2.2), 0);
	velocity->initVelocity(Vector2f(0, 0));
	gravity->initGravity(-9.8f);


	// ===================================================================================================
	// init components for `map`
	// ===================================================================================================

	auto Tileset = static_cast<Sprite*>(SpriteManager::getInstance()->find("tiles.png"));
	TilesetComponent->initSpriteComponent(Tileset, Rect(Vector2f(0, 0), Vector2f(16, 16)));
	maptransformComp->initTransform(Vector2f(0, 0), Vector2f(0, 0), Vector2f(1, 1), 0);
	mapComp->InitMapComponent();

	// ===================================================================================================
	//	create state for `samus`
	// ===================================================================================================
	auto input = InputManager::getInstance();
#pragma region "No state"
	auto no_state = new State("no_state",
		[=] {
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("no_state"));
	}, NULL, NULL);
#pragma endregion
	
#pragma region "stand"
	auto stand_right = new State("stand_right",
		[=] {
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("stand"));
	}, NULL, NULL);

	auto stand_left = new State("stand_left",
		[=] {
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("stand"));
	}, NULL, NULL);

	auto stand_up = new State("stand_up",
		[=] {
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("stand_up"));
	}, NULL, NULL);
#pragma endregion

#pragma region "run"

	auto run_right = new State("run_right",
		[=] {
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("run"));
	}, NULL, NULL);

	auto run_left = new State("run_left",
		[=] {
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("run"));
	}, NULL, NULL);

#pragma endregion

#pragma region "jump"

	auto jump = new State("jump",
		[=] {
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("jump"));
	}, NULL, NULL);

	auto jump_shoot = new State("jump_shoot",
		[=] {
			animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("jump_shoot"));
	}, NULL, NULL);

	auto jump_shoot_up = new State("jump_shoot_up",
		[=] {
		animationComp->setCurrentAction(animationComp->getAniamtion()->findAction("jump_shoot_up"));
	}, NULL, NULL);


#pragma endregion

#pragma region " add into state component:"
	// add into state component:

	stateComp->addState(no_state);

	stateComp->addState(stand_right);
	stateComp->addState(stand_left);
	stateComp->addState(stand_up);

	stateComp->addState(run_right);
	stateComp->addState(run_left);

	stateComp->addState(jump);

	stateComp->addState(jump_shoot);

	stateComp->addState(jump_shoot_up);

#pragma endregion

	

#pragma region " Transition No-state"

	no_state->addTransition(new Transition("no_state", "stand_right", [=] {
		return input->getKeyDown(DIK_RIGHT); }));

	no_state->addTransition(new Transition("no_state", "stand_left", [=] {
		return input->getKeyDown(DIK_LEFT); }));

	no_state->addTransition(new Transition("no_state", "stand_up", [=] {
		return input->isKeyDown(DIK_UP,KeyState::current); }));

	no_state->addTransition(new Transition("no_state", "jump", [=] {
		return input->isKeyDown(DIK_Z, KeyState::current); }));

#pragma endregion
	
#pragma region " Transition stand"

	stand_right->addTransition(new Transition("stand_right", "run_right", [=] {
		return input->isKeyDown(DIK_RIGHT, KeyState::current); }));
	stand_left->addTransition(new Transition("stand_left", "run_left", [=] {
		return input->isKeyDown(DIK_LEFT, KeyState::current); }));
	//----
	stand_right->addTransition(new Transition("stand_right", "stand_left", [=] {
		return input->getKeyDown(DIK_LEFT); }));
	stand_left->addTransition(new Transition("stand_left", "stand_right", [=] {
		return input->getKeyDown(DIK_RIGHT); }));
	//----
	stand_right->addTransition(new Transition("stand_right", "jump", [=] {
		return input->isKeyDown(DIK_Z, KeyState::current); }));
	stand_left->addTransition(new Transition("stand_left", "jump", [=] {
		return input->isKeyDown(DIK_Z, KeyState::current); }));
	//----
	stand_left->addTransition(new Transition("stand_left", "stand_up", [=] {
		return input->isKeyDown(DIK_UP, KeyState::current); }));
	stand_right->addTransition(new Transition("stand_right", "stand_up", [=] {
		return input->isKeyDown(DIK_UP, KeyState::current); }));
	//----
	stand_up->addTransition(new Transition("stand_up", "stand_right", [=] {
		return input->getKeyUp(DIK_UP); }));
	stand_up->addTransition(new Transition("stand_up", "stand_left", [=] {
		return input->getKeyUp(DIK_UP); }));

#pragma endregion

#pragma region " Transition run"
	
	run_right->addTransition(new Transition("run_right", "stand_right", [=] {
		return input->getKeyUp(DIK_RIGHT); }));

	run_left->addTransition(new Transition("run_left", "stand_left", [=] {
		return input->getKeyUp(DIK_LEFT); }));

	run_right->addTransition(new Transition("run_right", "stand_left", [=] {
		return input->getKeyDown(DIK_LEFT); }));

	run_left->addTransition(new Transition("run_left", "stand_right", [=] {
		return input->getKeyDown(DIK_RIGHT); }));

#pragma endregion

#pragma region " Transition jump"

	jump->addTransition(new Transition("jump", "stand_right", [=] {
		return bound->onGround; }));
	jump->addTransition(new Transition("jump", "stand_left", [=] {
		return bound->onGround; }));
	//----
	jump->addTransition(new Transition("jump", "jump_shoot", [=] {
		return input->isKeyDown(DIK_X, KeyState::current); }));
	jump->addTransition(new Transition("jump", "jump_shoot_up", [=] {
		return input->isKeyDown(DIK_UP, KeyState::current); }));

#pragma endregion

#pragma region " Transition jump - shoot"

	jump_shoot->addTransition(new Transition("jump_shoot", "stand_right", [=] {
		return bound->onGround; }));
	jump_shoot->addTransition(new Transition("jump_shoot", "stand_left", [=] {
		return bound->onGround; }));
	//----
	jump_shoot_up->addTransition(new Transition("jump_shoot_up", "stand_right", [=] {
		return bound->onGround;  }));
	jump_shoot_up->addTransition(new Transition("jump_shoot_up", "stand_left", [=] {
		return bound->onGround; }));
#pragma endregion


}
