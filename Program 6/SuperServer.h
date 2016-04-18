include "stdafx.h"

/*
* Filename: SuperServer.h
* Author: Chris Rodriguez
* Classes/Procedures:   SuperServer, a class that facilitates communication between clients
*/

#ifndef SUPERSERVER_H_INCLUDED
#define SUPERSERVER_H_INCLUDED
#include "Server.h";
#include <sys/socket.h>

class SuperServer : Server
{
private:
	string user; // store the username
	const char *msg;
	int sockfd;
	int len;
	void signIn();
	void registerUser();
	void helper1();
	void helper2();
	void helper3();
	void helper4();
	void helper5();
	void helper6();
	void helper7();
	string getInput();
	void sendInfo(string);
};

#endif