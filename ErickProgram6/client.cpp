#include <iostream>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

using namespace std;

int sockfd; // so the socketfd is in the scope of all helper functions
const char *msg; // so the char array address is available to all
int len; // so the length is available to all

string getInput()
{
	char input[1000];
	recv(sockfd, input, 1000, 0);
	return string(input);
}

void sendInfo(string message)
{
	msg = message.c_str();
	len = strlen(msg);
	send(sockfd, msg, len, 0);
}

bool signIn(){
		getInput();
		cout << "Please enter your username: ";
		string username;
		cin >> username;
		cout >> "\nPlease enter a password: ";
		string password;
		cin >> password;
		sendInfo(username);
		getInput(); //Gets the okay
		sendInfo(password);
		return (getInput=="reject");
}

bool registerUser() {
		getInput();
		cout << "Please enter your username: ";
		string username;
		cin >> username;
		cout >> "\nPlease enter a password: ";
		string password;
		cin >> password;
		sendInfo(username);
		getInput(); //Gets the okay
		sendInfo(password);
		return (getInput=="reject");
}

void helper1()
{
	// I'm getting the list of users
	string users = getInput();
	cout << users << endl;
}

void helper2()
{
	getInput(); // get the "Ready" from the server
	cout << "Please enter the user you want to make a partnership request to: ";
	// get the username
	string name;
	getline(cin, name);
	sendInfo(name); // send the username
	cout << getInput() << endl;
}

void helper3()
{
	cout << "List of requests:\n" << getInput() << endl;
}

void helper4()
{
	getInput(); // get "Ready"
	
	// get and send the request
	cout << "Which request do you want to act on? ";
	string request;
	cin >> request;
	sendInfo(request);
	
	// get and send the action
	getInput(); // get the "okay"
	string action;
	while (true)
	{
		cout << "Do you want to accept or reject the request? ";
		getline(cin, action);
		if (action == "accept")
		{
			sendInfo("true");
			break;
		}
		else if (action == "reject")
		{
			sendInfo("false");
			break;
		}
		else
		{
			cout << "Invalid action." << endl;
		}
	}
	
	// Display the message from the server
	cout << getInput() << endl;
}

void helper5()
{
	cout << "List of partners" << getInput() << endl;
}

void helper6()
{
	getInput(); // get "Ready"
	
	// get and send the username
	string partner;
	cout << "Which partner do you want to send a message to? ";
	getline(cin, partner);
	sendInfo(partner);
	
	getInput(); // get the "okay"
	
	// get and send the message
	string mess;
	cout << "Enter your message: ";
	getline(cin, mess);
	sendInfo(mess);
	
	// display the message from the server
	cout << getInput() << endl;
}

bool is_number(const string& s){
   for(int i = 0; i < s.length(); i++)//for each char in string,
      if(! (s[i] >= '0' && s[i] <= '9' || s[i] == ' ') ) return false;
      //if s[i] is between '0' and '9' of if it's a whitespace (there may be some before and after
      // the number) it's ok. otherwise it isn't a number.

   return true;
}

void helper7()
{
	getInput(); // get "Ready"
	
	// get and send the username
	string partner;
	cout << "Which partner do you want to view messages from? ";
	getline(cin, partner);
	sendInfo(partner);
	
	getInput(); // get the "okay"
	
	// get and send the number of messages wanted
	string mess;
	string numbers = "";
	while (true)
	{
		cout << "How many messages do you want to see? ";
		getline(cin, mess);
		if (is_number(mess))
		{
			sendInfo(mess);
			break;
		}
		else
			cout << "Please enter a number." << endl;
	}
	
	
	// display the message from the server
	cout << getInput() << endl;
}

void startSocket(char* ip, char* msg, char* port){
	int status;
	struct addrinfo host_info;
	struct addrinfo *host_info_list;
	
	memset(&host_info, 0 , sizeof host_info);
	
	std::cout << "Setting up the structs..." << std::endl;
	
	host_info.ai_family = AF_UNSPEC;
	host_info.ai_socktype = SOCK_STREAM;
	
	status = getaddrinfo(ip, port, &host_info, &host_info_list);
	
	if(status!=0) std::cout << "getaddrinfo error" << gai_strerror(status);
	
	std::cout << "Creating a socket..." << std::endl;
	int socketfd;
	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,
					  host_info_list->ai_protocol);
	if(socketfd == -1) std::cout << "socket error ";
	
	std::cout << "Connect()ing..." << std::endl;
	status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if (status == -1) 
		std::cout << "connect error" << strerror(errno);
	else
		cout << "Connection Established" << endl;
	

	bool menu = true;

	// for helper methods
	sockfd = socketfd;

	while (true) {
		
		if(menu){
			const char * startMenu = "Login Menu: \n\t"
								 "1) Sign-in\n\t2)Register\n\n";
			std::cout << startMenu << std::endl;
			char userInput[] = "";
			std::cin >> userInput;
			
			int len;
			ssize_t bytes_sent;
			len = strlen(userInput);
			
			
			if(len != 1){
				cout << "Invalid input: len = " << len << endl;
				continue;
			}
			bytes_sent = send(socketfd, userInput, len, 0);
			char userInputInt = (int)*userInput;
			switch (userInputInt){
				//case 1: menu = signIn();
				//break;
				//case 2: menu = registerUser();
				//break;
				default: cout << "Invalid option/n" << endl;
			}
			
		}
		else {
			const char * mainMenu = "Main Menu: \n\t1)View a list of other users"
									"\n\t2)Request a partnership with another user"
									"\n\t3)View partner requests"
									"\n\t4)Accept or reject partner request"
									"\n\t5)View a list of partners"
									"\n\t6)Send deposit message for a partner"
									"\n\t7)View messages between a partner";
			
			std::cout << mainMenu << std::endl;
			char userInput[] = "";
			std::cin >> userInput;
			int len;
			ssize_t bytes_sent;
			len = strlen(userInput);
			
			if(len != 1){
				cout << "Invalid input: len = " << len << endl;
				continue;
			}
			
			bytes_sent = send(socketfd, userInput, len, 0);
			char userInputInt = (int)*userInput;
			switch(userInputInt){
					//case 1: helper1();
					//break;
					//case 2: helper2();
					//break;
					//case 3: helper3();
					//break;
					//case 4: helper4();
					//break;
					//case 5: helper5();
					//break;
					//case 6: helper6();
					//break;
					//case 7: helper7();
					//break;
					default: cout << "Invalid Option\n" << endl;
			}
			
		}
		//std::cout << socketfd << std::endl;
		//close(socketfd);
	}
	std::cout << "Receving complete. Closing socket..." << std::endl;
	freeaddrinfo(host_info_list);
	
} 

int main(int argc, char* argv[]) {
	//const char * mainMenu = "Main Menu: \n\t"
							//"1)View Users\n\t2)Request Partnership\n\t"
							//"3)View Partner Requests\n\t4)Accept or"
							//"Reject Partner Request\n\t5)View a list"
							//" of partners\n\t6)Send deposit message for a partner"
							//"\n\t7)View messages between partners";
	//cout << mainMenu << endl;
	//char userInput;
	//cin >> userInput;
	//cout << userInput << endl;
	//char ip[] = "216.58.195.46";
	//char msg[] = "GET / HTTP/1.1\nhost: www.google.com\n\n";
	//char port[] = "80";

	char ip[] = "10.0.2.15";
	char msg[] = "GET / HTTP/1.1\nhost: www.google.com\n\n";

	char port[] = "5555";
	startSocket(ip,msg, port);
	
	return 0;
}
