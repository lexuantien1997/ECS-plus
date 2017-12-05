#ifndef CLIENT_H_
#define CLIENT_H_

#include "Server.h"
#include "Delegate.h"

class Client
{

	virtual void MessageSentHandler(const Server* p_sender, void* p_parameter) = 0;

public:

	Client(Server* p_server)
	{
		p_server->MessageSent += new Delegate<Client, Server>(this, &Client::MessageSentHandler);
	}

};


#endif // !CLIENT_H_

