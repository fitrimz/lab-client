#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
	int main (int argc, char *argv[])
{
		int socket_desc;
		struct sockaddr_in server;
		char *message;

	//create socket
		socket_desc=socket(AF_INET,SOCK_STREAM,0);
		if(socket_desc== -1)
		{
			printf("COULD NOT CREATE SOCKET");
		}

		server.sin_addr.s_addr=inet_addr("192.168.1.27");
		server.sin_family= AF_INET;
		server.sin_port=htons(22);

		//connect to remote server

		if(connect(socket_desc,(struct sockaddr*)&server,sizeof(server))<0)
		{
	puts("connect error");
	return 1;
		}

	puts("connected \n");
//SEND SOME MESSAGE
message ="connect";

if (send(socket_desc, message,strlen(message),0)<0)
{
	puts("SEND FAILED");
	return 1;

}
	puts("Data Send\n");
	return 0;
}
