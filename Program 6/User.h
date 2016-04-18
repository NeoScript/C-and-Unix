/*
* Filename: User.h
* Author: Chris Rodriguez
* Classes/Procedures:   User, a class that stores all info needed for every user
*/

#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include <map>
#include <deque>
#include <utility>
#include "Message.h"
using namespace std;

/*
* User
* Author: Chris Rodriguez
* holds information for a user
*/
class User
{
private:
	map<string, deque<Message> > convos; // conversations separated by user
	deque<string> requests; // users that have requested partnership with you
	string username; // name of user
	string password; // password
public:
	User(string, string);
	void addPartner(string);
	void addRequest(string);
	void removeRequest(string);
	string getListOfPartners();
	string getMessages(string, int);
	bool checkLogin(string, string);
	void addMessage(string, string);
	string getUsername();
	string getListOfRequests();
};

#endif // USER_H_INCLUDED
