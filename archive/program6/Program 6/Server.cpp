/*
* Filename: Server.cpp
* Author: Chris Rodriguez
* Classes/Procedures:   addUser, adds a user to the server with new username and password
						getListOfUsers, returns a list of users in a string
						getUser, returns the user we're looking for
						requestMade, adds a request to a user's list of requests
						getRequests, returns the requests for a user
						finalizeRequest, takes an action on a request
						getPartners, get the list of partners for a particular user
						depositMessage, deposits a message between the sender and the recipient
						viewMessages, returns num messages between user and partner
						userExists, checks if the user exists
*/

#include "Server.h"

/*
* addUser
* establishes a new user
* Arguments:	name, I/P, string	pass, I/P, string
*				name of the user	password for the user
*/
void Server::addUser(string name, string pass)
{
	User user(name, pass);
	users.push_front(user);
	
}

/*
* getListOfUsers
* returns a list of users as a single string
* No arguments
*/
string Server::getListOfUsers()
{
	string names;
	for (unsigned int i = 0; i < users.size(); i++)
		names += users.at(i).getUsername() + "\n";
	return names;
}

/*
* getUser
* returns the user we want to find (assumes that the user is in the deque)
* Arguments:	user, I/P, string
*				the name of the user we're looking for
*/
User Server::getUser(string user)
{
	for (unsigned int i = 0; i < users.size(); i++)
		if (users.at(i).getUsername() == user)
			return users.at(i);
	User g("g", "g");
	return g;
}

/*
* requestMade
* adds request to user's list of requests
* Arguments:	user, I/P, string				request, I/P, string
*				the name of the user we want	the user making the request
*/
void Server::requestMade(string user, string request)
{
	getUser(user).addRequest(request);
}

/*
* getRequests
* returns the list of requests for user
* Arguments:	user, I/P, string
*				the user we want the requests for
*/
string Server::getRequests(string user)
{
	return getUser(user).getListOfRequests();
}

/*
* finalizeRequest
* takes an action on a request
* Arguments:	user, I/P, string		request, I/P, string			accept, I/P, string
*				the user taking action	the user that made the request	whether the request was accepted
*/
void Server::finalizeRequest(string user, string request, string accept)
{
	getUser(user).removeRequest(request);
	if (accept == "true")
	{
		getUser(user).addPartner(request);
		getUser(request).addPartner(user);
	}
}

/*
* getPartners
* returns the list of partners of a user
* Arguments:	user, I/P, string
*				the user we want the list of partners for
*/
string Server::getPartners(string user)
{
	return getUser(user).getListOfPartners();
}

/*
* depositMessage
* deposits a message sent from one user to another
* Arguments:	sender, I/P, string			recipient, I/P, string			message, I/P, string
*				the sender of the message	the recipient of the message	the message being sent
*/
void Server::depositMessage(string sender, string recipient, string message)
{
	getUser(sender).addMessage(recipient, message);
	getUser(recipient).addMessage(sender, message);
}

/*
* viewMessages
* returns num messages between user and partner
* Arguments:	user, I/P, string					partner, I/P, string					num, I/P, int
*				the user wanting to view messages	the partner the messages are between	the number of messages
*/
string Server::viewMessages(string user, string partner, int num)
{
	return getUser(user).getMessages(partner, num);
}

/*
* userExists
* checks to see if this user exists on the server
* Arguments:	user, I/P, string
*				the user we're checking for the existence of
*/
bool Server::userExists(string user)
{
	for (unsigned int i = 0; i < users.size(); i++)
		if (users.at(i).getUsername() == user)
			return true;
	return false;
}

bool Server::arePartners(string user, string other)
{
	return userExists(other) && getUser(user).isPartner(other);
}

bool Server::requestBetween(string user, string request)
{
	return userExists(request) && getUser(user).hasRequest(request);
}
