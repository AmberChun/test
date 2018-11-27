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

	

	int result = connect(fd,(struct sockaddr*)&un,sizeof(un));
    if (result == -1) {
        printf ("ensure the server is up\n");
    }
    else
    {
    	printf ("connect sucess!\n");
    }

	return 0;
}