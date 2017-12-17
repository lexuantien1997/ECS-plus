#include "../ECS Plus/_ECS_Header.h"
#include "../DirectX/_DIRECTX_Header.h"
#include "MetroidGame.h"
#include <Windows.h>
using namespace std;

#include  <list>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpStrCmdLine,
	int nShowCmd)
{

	MetroidGame *metroid = new MetroidGame(hInstance, L"Metroid", GAME_SCREEN_RESOLUTION_320_240_24, 0, 60);

	metroid->runGame();

	return 0;
}

//template<class TSender>
//class BaseDelegate
//{
//public:
//	virtual bool Equals(const BaseDelegate<TSender>* p_other) = 0;
//	virtual void operator()(const TSender* p_sender, void* p_parameter) = 0;
//	virtual void Call(const TSender* p_sender, void* p_parameter) = 0;
//};
//
//template<class TReciever, class TSender>
//class Delegate : public BaseDelegate<TSender>
//{
//private:
//	typedef void (TReciever::*PTF)(const TSender*, void* p_parameter);
//	PTF         m_ptr2Func;
//	TReciever*  m_ptr2Object;
//
//public:
//	Delegate(TReciever* p_ptr2Object, PTF p_ptr2Func)
//	{
//		m_ptr2Func = p_ptr2Func;
//		m_ptr2Object = p_ptr2Object;
//	}
//
//	bool Equals(const BaseDelegate<TSender>* p_other)
//	{
//		const Delegate<TReciever, TSender>* other;
//
//		other = static_cast<const Delegate<TReciever, TSender>*>(p_other);
//
//		assert(other != NULL);
//		assert(m_ptr2Object != NULL);
//
//		return other->m_ptr2Object == m_ptr2Object && other->m_ptr2Func == m_ptr2Func;
//	}
//
//	virtual void operator()(const TSender* p_sender, void* p_parameter)
//	{
//		assert(p_sender != NULL);
//		(m_ptr2Object->*m_ptr2Func)(p_sender, p_parameter);
//	}
//
//	virtual void Call(const TSender* p_sender, void* p_parameter)
//	{
//		assert(p_sender != NULL);
//		(m_ptr2Object->*m_ptr2Func)(p_sender, p_parameter);
//	}
//};
//
//template<class TSender>
//class Event
//{
//	list < BaseDelegate<TSender>* > m_observers;
//	void Register(const BaseDelegate<TSender>* p_handler);
//	void Unregister(const BaseDelegate<TSender>* p_handler);
//public:
//	void operator += (const BaseDelegate<TSender>* p_handler);
//	void operator -= (const BaseDelegate<TSender>* p_handler);
//	void operator () (const TSender* p_sender, void* p_parameter);
//	void Call(const TSender* p_sender, void* p_parameter);
//	~Event();
//};
//
//template<class TSender>
//void Event<TSender>::operator += (const BaseDelegate<TSender>* p_handler)
//{
//	Register(p_handler);
//}
//
//template<class TSender>
//void Event<TSender>::operator -= (const BaseDelegate<TSender>* p_handler)
//{
//	Unregister(p_handler);
//}
//
//template<class TSender>
//void Event<TSender>::operator ()(const TSender* p_sender, void* p_parameter)
//{
//	Call(p_sender, p_parameter);
//}
//
//template<class TSender>
//void Event<TSender>::Register(const BaseDelegate<TSender>* p_handler)
//{
//	assert(p_handler != NULL);
//
//	for (list< BaseDelegate<TSender>* >::iterator itr = m_observers.begin();
//		itr != m_observers.end();
//		itr++)
//	{
//		if ((*itr)->Equals(p_handler))
//			return;
//	}
//
//	m_observers.push_back(const_cast<BaseDelegate<TSender>*>(p_handler));
//}
//
//template<class TSender>
//void Event<TSender>::Unregister(const BaseDelegate<TSender>* p_handler)
//{
//	assert(p_handler != NULL);
//
//	vector< BaseDelegate<TSender>* >::iterator where;
//	for (list< BaseDelegate<TSender>* >::iterator itr = m_observers.begin();
//		itr != m_observers.end();
//		itr++)
//	{
//		if ((*itr)->Equals(p_handler))
//		{
//			where = itr;
//			break;
//		}
//	}
//
//	m_observers.erase(where);
//}
//
//
//template<class TSender>
//void Event<TSender>::Call(const TSender* p_sender, void* p_parameter)
//{
//	for (list< BaseDelegate<TSender>* >::iterator itr = m_observers.begin();
//		itr != m_observers.end();
//		itr++)
//	{
//		(*itr)->Call(p_sender, p_parameter);
//	}
//}
//
//template<class TSender>
//Event<TSender>::~Event()
//{
//	for (list< BaseDelegate<TSender>* >::iterator itr = m_observers.begin();
//		itr != m_observers.end();
//		itr++)
//	{
//		assert(*itr != NULL);
//		delete (*itr);
//	}
//}
//
//class Server;
//class Client;
//
//struct Mess
//{
//
//};
//
//class Server
//{
//public:
//	Event<Server> MessageSent;
//
//	void SendMessage(char* p_msg)
//	{
//		MessageSent(this, p_msg);
//	}
//
//	void SendMessage(Mess* p_msg)
//	{
//		MessageSent(this, p_msg);
//	}
//};
//
//struct IMess :Mess
//{
//public:
//	int a;
//	IMess(int _A) :a(_A) {}
//};
//
//class Client
//{
//	static int s_id;
//	int m_id;
//	void MessageSentHandler(const Server* p_sender, void* p_parameter)
//	{
//		cout << "Client" << m_id << ": received: " << (*(IMess*)p_parameter).a << endl;
//	}
//public:
//	Client(Server* p_server)
//	{
//		m_id = ++s_id;
//		p_server->MessageSent += new Delegate<Client, Server>(this, &Client::MessageSentHandler);
//	}
//};
//int Client::s_id = 0;
//
//
//void main()
//{
//	Server server;
//	Client client1(&server), client2(&server), client3(&server);
//	int a = 10;
//
////	server.SendMessage("Hello");
//
//	server.SendMessage(new IMess(10));
//
//	system("pause");
//}
