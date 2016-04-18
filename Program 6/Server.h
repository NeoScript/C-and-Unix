/*
* Filename: Server.h
* Author: Chris Rodriguez
* Classes/Procedures:   Server, a class that stores all info needed and facilitates communication between clients
*/

#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include "User.h"

/*
* Server
* Author: Chris Rodriguez
* the class that facilitates client communication and stores info
*/
class Server
{
private:
	deque<User> users;
public:
	User getUser(string);
	bool userExists(string);
	void addUser(string, string);
	string getListOfUsers();
	void requestMade(string, string);
	string getRequests(string);
	void finalizeRequest(string, string, string);
	string getPartners(string);
	void depositMessage(string, string, string);
	string viewMessages(string, string, int);
	bool arePartners(string, string);
	bool requestBetween(string, string);
};

#endif
