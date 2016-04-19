#include <iostream>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <netdb.h>

using namespace std;

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
		std::cout << "connect error";
	else
		cout << "Connection Established" << endl;
	
	bool menu = true;
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
