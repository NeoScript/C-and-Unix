/*
* Filename: User.cpp
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

#include "User.h"

User::User(string name, string pass)
{
	username = name;
	password = pass;
}

/*
* addPartner
* adds a partner to the user
* Arguments:    partner, I/P, string
*               partner to be added
*/
void User::addPartner(string partner)
{
	convos.insert(pair <string, deque<Message>>("partner", deque<Message>()));
}

/*
* addRequest
* adds a request from a person to the user
* Arguments:    person, I/P, string
*               person that has made the request
*/
void User::addRequest(string person)
{
	requests.push_front(person);
}

/*
* removeRequest
* removes a request to the user
* Arguments:    person, I/P, string
*               person to be removed from requests
*/
void User::removeRequest(string person)
{
	for (unsigned int i = 0; i < requests.size(); i++)
	{
		if (requests.at(i) == person)
		{
			requests.erase(requests.begin() + i - 1);
			break;
		}
	}
}

/*
* getListOfPartners
* returns list of user's partners
* No arguments
*/
string User::getListOfPartners()
{
	string partners = "";

	for (map<string, deque<Message>>::iterator it = convos.begin(); it != convos.end(); ++it)
	{
		partners += it->first + "\n";
	}
	if (partners == "")
		return "empty";
	
	return partners;
}

/*
* getMessages
* returns all messages between the user and the partner
* Arguments:    partner, I/P, string                n, I/P, int
*               partner the messages are between    the number of messages to return
*/
string User::getMessages(string partner, int n)
{
	string mess = "";
	deque<Message> deck = convos.at(partner);

	for (int i = 0; i < n; i++)
	{
		mess += deck.at(i).getMessage() + "\n";
	}
	
	if (mess == "")
		return "empty";
	
	return mess;
}

/*
* checkLogin
* checks the login info against what the user inputs
* Arguments:    name, I/P, string       pass, I/P, string
*               the alleged user name   the alleged password
*/
bool User::checkLogin(string name, string pass)
{
	if (name == username && password == pass)
		return true;
	return false;
}

/*
* addMessage
* adds a message
* Arguments:	partner, I/P, string				mess, I/P, string
*				the partner the user's talking to	the message being added
*/
void User::addMessage(string partner, string mess)
{
	Message messy(mess);
	convos.at(partner).push_front(messy);
}

/*
* getUsername
* returns the username of this user
* No arguments
*/
string User::getUsername()
{
	return username;
}

/*
* getListOfRequests
* return list of requests
* No arguments
*/
string User::getListOfRequests()
{
	string reqs = "";
	for (unsigned int i = 0; i < requests.size(); i++)
		reqs += requests.at(i) + "\n";
	if (reqs == "")
		return "empty";
	return reqs;
}

bool User::isPartner(string partner)
{
	if (convos.find(partner) == convos.end())
		return false;
	return true;
}

bool User::hasRequest(string request)
{
	for (unsigned int i = 0; i < requests.size(); i++)
		if (request == requests.at(i))
			return true;
	return false;
}
