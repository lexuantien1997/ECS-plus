#include "IntroScene.h"



IntroScene::IntroScene(string name) : Scene(name)
{
}


IntroScene::~IntroScene()
{
}

void IntroScene::update(float dt)
{
	animationSystem.update(dt);
	renderSystem.update(dt);
	inputSystem.update(dt);
}

void IntroScene::init()
{
	world->addSystem(renderSystem);
	world->addSystem(inputSystem);
	world->addSystem(animationSystem);

	Entity * intro = world->create_Entity("intro");

	intro->addComponent<PlayerControllable>("player controlable");
	SpriteComponent* spriteComp = intro->addComponent<SpriteComponent>("sprite component");
	Transform* transformComp = intro->addComponent<Transform>("transform component");
	AnimationComponent* introAnimationComp = intro->addComponent<AnimationComponent>("animation component");


	auto intro_sprite = static_cast<Sprite*>(SpriteManager::getInstance()->find("intro.png"));
	spriteComp->initSpriteComponent(intro_sprite, Rect(Vector2f(0, 0), Vector2f(260, 244)));
	transformComp->initTransform(Vector2f(0, -0), Vector2f(0, 0), Vector2f(320.0 / 260.0, 240.0 / 244.0), NULL);
	introAnimationComp->initAnimationComponent("", "introscene.xml");

	world->refresh();
}

void IntroScene::render()
{
	renderSystem.render();
}

void IntroScene::release()
{
}
