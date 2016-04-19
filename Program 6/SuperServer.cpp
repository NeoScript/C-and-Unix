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
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	cout << "before construct" << endl;
	SuperServer uh;
	cout << "after conadsfadsjf;lkadf" << endl;
	return 0;
}

SuperServer::SuperServer()
{
	cout << "in super server constradsfadsf" << endl;
	int status;
    struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
    struct addrinfo *host_info_list; // Pointer to the to the linked list of host_info's.

    // The MAN page of getaddrinfo() states "All  the other fields in the structure pointed
    // to by hints must contain either 0 or a null pointer, as appropriate." When a struct
    // is created in c++, it will be given a block of memory. This memory is not nessesary
    // empty. Therefor we use the memset function to make sure all fields are NULL.
    memset(&host_info, 0, sizeof host_info);

    std::cout << "Setting up the structs..."  << std::endl;

    host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
    host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.
    host_info.ai_flags = AI_PASSIVE;     // IP Wildcard

    // Now fill up the linked list of host_info structs with google's address information.
    status = getaddrinfo(NULL, "5555", &host_info, &host_info_list);
    // getaddrinfo returns 0 on succes, or some other value when an error occured.
    // (translated into human readable text by the gai_gai_strerror function).
    if (status != 0)  std::cout << "getaddrinfo error" << gai_strerror(status) ;


    std::cout << "Creating a socket..."  << std::endl;
    int socketfd ; // The socket descripter
    socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,
                      host_info_list->ai_protocol);
    if (socketfd == -1)  std::cout << "socket error " ;

    std::cout << "Binding socket..."  << std::endl;
    // we use to make the setsockopt() function to make sure the port is not in use
    // by a previous execution of our code. (see man page for more information)
    int yes = 1;
    status = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    status = bind(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
    if (status == -1)  std::cout << "bind error" << std::endl ;

    std::cout << "Listen()ing for connections..."  << std::endl;
    status =  listen(socketfd, 5);
    if (status == -1)  std::cout << "listen error" << std::endl ;


    int new_sd;
    struct sockaddr_storage their_addr;
    socklen_t addr_size = sizeof(their_addr);
    new_sd = accept(socketfd, (struct sockaddr *)&their_addr, &addr_size);
    if (new_sd == -1)
    {
        std::cout << "listen error" << std::endl ;
    }
    else
    {
        std::cout << "Connection accepted. Using new socketfd : "  <<  new_sd << std::endl;
    }
    sockfd = new_sd; // needed for helper methods

	while (true)
	{
		std::cout << "Waiting to recieve data..."  << std::endl;
		/*ssize_t bytes_recieved;
		char incomming_data_buffer[1000];
		bytes_recieved = recv(new_sd, incomming_data_buffer,1000, 0);
		// If no data arrives, the program will just wait here until some data arrives.
		if (bytes_recieved == 0) std::cout << "host shut down." << std::endl ;
		if (bytes_recieved == -1)std::cout << "recieve error!" << std::endl ;
		std::cout << bytes_recieved << " bytes recieved :" << std::endl ;
		incomming_data_buffer[bytes_recieved] = '\0';
		std::cout << incomming_data_buffer << std::endl;*/
		string num = getInput();
		if (num == "1")
			signIn();
		else if (num == "2")
			registerUser();
		else if (num == "0")
			break;


		/*std::cout << "send()ing back a message..."  << std::endl;
		const char *msg = "thank you.";
		int len;
		ssize_t bytes_sent;
		len = strlen(msg);
		bytes_sent = send(new_sd, msg, len, 0);*/
	}
    std::cout << "Stopping server..." << std::endl;
    freeaddrinfo(host_info_list);
    //close(new_sd);
    //close(socketfd);
}

string SuperServer::getInput()
{
	char input[1000];
	memset(&input, 0 , sizeof input);
	recv(sockfd, input, 1000, 0);
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
	cout << "READY" << endl;
	// get username
	string name = getInput();
	
	// send confirmation of name received
	sendInfo("got it");
	cout << "got it"<< endl;
	// get password
	string pass = getInput();

	// check login
	if (userExists(name))
	{
		if (getUser(name).checkLogin(name, pass))
		{
			sendInfo("accept");
			user = name;
			mainMenu();
		}
		else
			sendInfo("reject");
	}
	else
		sendInfo("reject");
}

void SuperServer::registerUser()
{
	sendInfo("Ready");
	cout << "READY" << endl;

	// get username
	string name = getInput();
	
	// send confirmation of name received
	sendInfo("got it");
	cout << "got it" << endl;
	// get password
	string pass = getInput();

	if (userExists(name))
		sendInfo("reject");
	else
	{
		addUser(name, pass);
		sendInfo("accept");
		cout << "accept" << endl;
		user = name;
		mainMenu();
	}
}

void SuperServer::mainMenu()
{
	cout << "main menu" << endl;
	while (true)
	{
		string num = getInput();
		cout << num << endl;
		if (num == "1")
		{
			cout << "1" << endl;
			helper1();
		}
		else if (num == "2")
			helper2();
		else if (num == "3")
			helper3();
		else if (num == "4")
			helper4();
		else if (num == "5")
			helper5();
		else if (num == "6")
			helper6();
		else if (num == "7")
			helper7();
		else if (num == "0")
			break;
	}
}

void SuperServer::helper1()
{
	cout << getListOfUsers() << endl;
	sendInfo(getListOfUsers());
	cout << "helper1" << endl;
}

void SuperServer::helper2()
{
	sendInfo("Ready");
	cout << "READY" << endl;
	string partner = getInput();
	cout << partner << endl;
	if (userExists(partner))
	{
		requestMade(partner, user);
		sendInfo("success");
	}
	else
		sendInfo("failure");
	cout << "helper1" << endl;

}

void SuperServer::helper3()
{
	sendInfo(getRequests(user));
}

void SuperServer::helper4()
{
	sendInfo("Ready");
	string request = getInput();
	sendInfo("okay");
	string accept = getInput();
	if (requestBetween(user, request))
	{
		finalizeRequest(user, request, accept);
		sendInfo("success");
	}
	else
		sendInfo("failure");
}

void SuperServer::helper5()
{
	sendInfo(getPartners(user));
}

void SuperServer::helper6()
{
	sendInfo("Ready");
	string partner = getInput();
	sendInfo("okay");
	string message = getInput();
	if (arePartners(user, partner))
	{
		depositMessage(user, partner, message);
		sendInfo("success");
	}
	else
		sendInfo("failure");
}

void SuperServer::helper7()
{
	cout << "Ready" << endl;
	sendInfo("ReadyF");
	cout << "Ready" << endl;
	string partner = getInput();
	sendInfo("okay");
	cout << "okay" << endl;
	string num = getInput();
	cout << num << endl;
	if (num == "")
		cout << "empty" << endl;
	int n = atoi(num.c_str());
	cout << n << endl;
	if (arePartners(user, partner))
		sendInfo(viewMessages(user, partner, n));
	else
		sendInfo("Couldn't find partner");
}
