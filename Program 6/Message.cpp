#include "stdafx.h"

/*
* Filename: Messages.cpp
* Author: Chris Rodriguez
* Classes/Procedures:   getStamp, gets time stamp for message
*                       Message, constructors for new messages or recovering old ones
*                       getMessage, returns message and stamp in a nice format
*/

#include <ctime>
#include <string>
#include "Message.h"

/*
* getStamp()
* gets the date-time stamp needed for every message
* No arguments
*/
void Message::getStamp()
{
	// Neatly displays time in a string format
	time_t rawtime;
	time(&rawtime);
	char str[26];
	ctime_s(str, sizeof str, &rawtime);
	stamp = str;
}

/*
* Message
* constructor for message received this session
* Arguments:    mess, I/P, string
*               the message received
*/
Message::Message(string mess)
{
	getStamp();
	message = mess;
}

/*
* Message (might not be necessary)
* constructor for messages being recovered from storage
* Arguments:    mess, I/P, string       time, I/P, string
*               the message recovered   the stamp recovered
*/
Message::Message(string mess, string time)
{
	message = mess;
	stamp = time;
}

/*
* getMessage
* get the message and stamp in a neat format
* No arguments
*/
string Message::getMessage()
{
	return stamp + "\n" + message;
}
