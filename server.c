#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>

#define SERV_PORT 8888
#define SERVER_IP "127.0.0.1"

int main()
{

	int fd = socket(AF_INET,SOCK_STREAM,IPPROTO_IP);

	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERV_PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	listen(fd,10);

	int clientfd;
	if(clientfd = accept(fd,NULL,NULL))
	{
		printf("recv connect!\n");
	}

	char revMsg[20];
	while(recv(clientfd,revMsg,20,MSG_WAITALL) > 0)
	{
		printf("rev: %s\n",revMsg);
		memset(revMsg,0,sizeof(revMsg));
		break;
	}

	char message[20] = "server send!";
	send(clientfd,message,20,MSG_CONFIRM);

	return 0;
}