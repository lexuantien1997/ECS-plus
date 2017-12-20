#include "Start_GameOver_Scene.h"



Start_GameOver_Scene::Start_GameOver_Scene(string name):Scene(name)
{
}


Start_GameOver_Scene::~Start_GameOver_Scene()
{
}

void Start_GameOver_Scene::update(float dt)
{
	renderSystem.update(dt);
	inputSystem.update(dt);
}

void Start_GameOver_Scene::init()
{
	world->addSystem(renderSystem);
	world->addSystem(inputSystem);

	Entity * start = world->create_Entity("start");

	start->addComponent<PlayerControllable>("player controlable");
	SpriteComponent* spriteComp = start->addComponent<SpriteComponent>("sprite component");
	Transform* transformComp = start->addComponent<Transform>("transform component");


	auto start_sprite = static_cast<Sprite*>(SpriteManager::getInstance()->find("start.png"));
	spriteComp->initSpriteComponent(start_sprite, Rect(Vector2f(5, 56), Vector2f(256, 220)));
	transformComp->initTransform(Vector2f(0, -0), Vector2f(0, 0), Vector2f(640.0 / 256.0, 480.0 / 220.0), NULL);

	world->refresh();
}

void Start_GameOver_Scene::render()
{
	renderSystem.render();
}

void Start_GameOver_Scene::release()
{
}
