#include <iostream>
#include <sys/socket.h>
using namespace std;


int main() {

	int socketfd;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	cout << "Hello, World!" << endl;
	return 0;
}