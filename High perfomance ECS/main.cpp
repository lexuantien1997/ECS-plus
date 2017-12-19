//#include <iostream>
//using namespace std;
//
//#include "Entity.h"
//#include "Component.h"
//#include "GameWorld.h"
//#include "System.h"
//using namespace ECS;
//
//class Transform :public ECS::Component
//{
//public:
//	int a, b;
//	Transform(int _a,int _b):a(_a),b(_b){ }
//};
//
//class Transform2 :public ECS::Component
//{
//public:
//	int a, b;
//	Transform2(int _a, int _b) :a(_a), b(_b) { }
//};
//
//class Transform3 :public ECS::Component
//{
//public:
//	int a, b;
//	Transform3(int _a, int _b) :a(_a), b(_b) { }
//};
//
//class Transform4 :public ECS::Component
//{
//public:
//	int a, b;
//	Transform4(int _a, int _b) :a(_a), b(_b) { }
//};
//
//
//struct Test:public System
//{
//public:
//	Test()
//	{
//		requireComponent<Transform>();
//		requireComponent<Transform2>();
//		requireComponent<Transform3>();
//
//		excludeComponent<Transform4>();
//	}
//};
//
//void main()
//{
//	GameWorld* w = new GameWorld();
//	auto e = w->createEntity();
//	Test *t = w->addSystem<Test>(new Test());
//	e->addComponent<Transform>(new Transform(10, 10));
//	e->addComponent<Transform2>(10, 2);
//	e->addComponent<Transform3>(69, 69);
//	
//	e->refresh();
//	w->loop2RefreshAndRemove();
//
//	e->removeComponent<Transform>();
//	e->refresh();
//	w->loop2RefreshAndRemove();
//
//	system("pause");
//}