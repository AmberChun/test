#include <sys/socket.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/un.h>

#define UNIXCONN_STR "server_socket"

int main()
{
	struct sockaddr_un un;
	int fd = socket(AF_UNIX,SOCK_STREAM,0);

	unlink(UNIXCONN_STR);

	memset(&un,0,sizeof(un));
	un.sun_family = AF_UNIX;
	strcpy (un.sun_path, UNIXCONN_STR);
	//strncpy(un.sun_path,UNIXCONN_STR,sizeof(un.sun_path));
	//int len = offsetof(struct sockaddr_un,sun_path) + strlen(UNIXCONN_STR);

	if(bind(fd,(struct sockaddr*)&un,sizeof(un)) < 0)
	{
		printf("bind fail!\n");
		return 0;
	}

	if(listen(fd,10) < 0)
	{
		printf("listen fail!\n");
		return 0;
	}

	int clientfd;
	if(clientfd = accept(fd,NULL,NULL))
	{
		printf("recv connect!\n");
	}


	return 0;
}