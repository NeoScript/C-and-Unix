/*
* Filename: Messages.h
* Author: Chris Rodriguez
* Classes/Procedures:   Message, a wrapper class of sorts for every message stored by the server
*/

#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include <string>
#include <ctime>
#include <time.h>
using namespace std;
/*
* Message
* Author: Chris Rodriguez
* Wrapper class for messages
*/
class Message
{
private:
	string message; // actual message stored here
	string stamp; // date-time stamp of the message
	void getStamp();
public:
	Message(string);
	Message(string, string);
	string getMessage();
};
#endif // MESSAGE_H_INCLUDED
