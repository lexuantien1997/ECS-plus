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
	movementSystem.update(dt);
	renderSystem.update(dt);
}

void PlayingScene::init()
{
	// SYSTEMS
	world->addSystem(renderSystem);
	world->addSystem(inputSystem);
	world->addSystem(movementSystem);
	world->addSystem(animationSystem);
	// ENTITY
	Entity* samus = world->create_Entity("samus");

	// COMPONENTS
	samus->addComponent<PlayerControllable>("player control");

	auto transformComp = samus->addComponent<Transform>("transform component");

	auto bound= samus->addComponent<Bound>("bound");

	auto velocity = samus->addComponent<Velocity>("velocity");

	auto spriteComp = samus->addComponent<SpriteComponent>("sprite component");

	auto animationComp= samus->addComponent<AnimationComponent>("animation component");

	// INIT COMPONENTS

	auto samus_sprite= static_cast<Sprite*>(SpriteManager::getInstance()->find("samus_aran.png"));

	animationComp->initAnimationComponent("no_state", "samus_states.xml");

	spriteComp->initSpriteComponent(samus_sprite, Rect(Vector2f(184, 36), Vector2f(18,34)));

	transformComp->initTransform(Vector2f(200,200), Vector2f(50, 50), Vector2f(2,2.2), 0);

	velocity->initVelocity(Vector2f(0, 0), Vector2f(0, 0));

	// refresh the game world:
	world->refresh();

}

void PlayingScene::render()
{
	inputSystem.render();
	movementSystem.render();
	renderSystem.render();

}

void PlayingScene::release()
{

}
