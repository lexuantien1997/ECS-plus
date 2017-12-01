#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include "ExComponent.h"
#include "ExSystem.h"

using namespace ECS;



void Test_ECS()
{
	// =============================== create data ==========================

	// Tạo game world
	GameWorld* world=new GameWorld();

	// Tạo các system dùng trong game world này:
	TMovementSystem movementSystem;
	TRenderingSystem renderingSystem;

	// add system vào game world:
	world->addSystem(movementSystem);
	world->addSystem(renderingSystem);

	// Tạo 1 thằng nhân vật có tên là samus
	Entity* player = world->create_Entity("Samus");

	// Các component cần có của nhân vật:
	// `auto` giống `var` trong c# nhưng tốc độ xử lý của `auto rất nhanh
	auto transform=player->addComponent<TTransform>("transform");
	auto velocity=player->addComponent<TVelocity>("velocity");
	player->addComponent<TSprite>("sprite");
	
	// có thể add nhiều gravity
	player->addComponent<TGravity>("gravity 1");
	player->addComponent<TGravity>("gravity 2");
	
	// KHởi tạo các component:
	// ý nghĩa: Player có vị trí (100,100) được phóng to bức hình lên 3 lần và vẽ với góc 90 độ
	transform->initTransform(IVector2f(100, 100), IVector2f(50, 50), IVector2f(3, 3), 90);
	velocity->initVelocity(IVector2f(0, 0));

	// có thể lấy component theo tên:
	auto sprite=player->getComponent<TSprite>("sprite");
	sprite->initSprite("Samus.png");

	auto gravity = player->getComponent<TGravity>("gravity 1");
	gravity->initGraviry();

	// refresh để các system kiểm tra các entity có các component mà system yêu cầu không

	world->refresh();

	// =============================== load resource ==========================

	movementSystem.loadResource();
	movementSystem.loadResource();

	// =============================== init ============================

	movementSystem.init();
	renderingSystem.init();

	// =============================== update ==========================

	movementSystem.update(0.01);
	renderingSystem.update(0.01);

	// =============================== render ==========================

	movementSystem.render();
	renderingSystem.render();

	// =================================================================
}



#endif