#include "stdafx.h"

/*
* Filename: SuperServer.cpp
* Author: Chris Rodriguez
* Classes/Procedures:   User, constructor for User class
*                       addPartner, adds user name to list of partners
*                       addRequest, adds user name to list of requests
*                       removeRequest, removes user name from list of requests
*                       getListOfPartners, returns list of the user's partners
*                       getMessages, returns the last n messages between the user and that partner
*						checkLogin, checks the login credentials of the user
*						addMessage, adds a message between a specific partner
*						getUsername, returns the name of the user
*						getListOfRequests, returns a list of requests
*/

#include "SuperServer.h"

string SuperServer::getInput()
{
	char input[1000];
	recv(sockfd, input, n, 0);
	return string(input);
}

void SuperServer::sendInfo(string message)
{

	msg = message.c_str();
	len = strlen(msg);
	send(sockfd, msg, len, 0);
}

void SuperServer::signIn()
{
	// Send confirmation
	sendInfo("Ready");
	
	// get username
	string name = getInput(10);
	
	// send confirmation of name received
	sendInfo("got it");

	// get password
	string pass = getInput(10);

	// check login
	if (userExists(name))
	{
		if (getUser(name).checkLogin())
			sendInfo("accept");
		else
			sendInfo("reject");
	}
	else
		sendInfo("reject");
}

void SuperServer::registerUser()
{
	sendInfo("Ready");

	// get username
	string name = getInput(10);

	// send confirmation of name received
	sendInfo("got it");

	// get password
	string pass = getInput(10);

	if (userExists(name))
		sendInfo("reject");
	else
	{
		addUser(name, pass);
		sendInfo("accept");
	}

	void SuperServer::helper1()
	{
		cout << "option 1";
	}
}