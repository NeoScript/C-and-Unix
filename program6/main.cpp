#include <signal.h>
#include <bits/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {

	int listenfd, connfd;
	pid_t childpid;
	socklen_t clientLength;
	struct sockaddr_in cliaddr, servaddr;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	return 0;
}