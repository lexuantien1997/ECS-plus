#ifndef SERVER_H_
#define SERVER_H_

#include "Event.h"
#include "Mess.h"

class Server
{
public:
	Event<Server> MessageSent;

	void SendMessage(Mess* p_msg)
	{
		MessageSent(this, p_msg);
	}
};

#endif // !SERVER_H_
