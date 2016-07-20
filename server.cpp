#include <iostream> 
#include <stdint.h>
#include <string>
#include <sstream>
#include<stdio.h>
#include<stddef.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>

using namespace std;
struct Algo {
	//   char types;

	int first;
	int second;
}temp;
int main()
{
	int sum;
	char *tmp1,*tmp2;
	int sockfd ,new_fd;
	struct sockaddr_in *their,*my;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	int sin_size,num1,num2;
//	string buff;
	int numbytes;

	//建立tcp接口

	if ((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket");
		exit(1);
	}
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(1212);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	bzero (&(my_addr.sin_zero),8);
	if((bind(sockfd,(struct sockaddr*)(&my_addr),sizeof(struct sockaddr ))) == -1)
	{
		perror("bind");
		exit(1);
	}
	//绑定套接口
	if (listen(sockfd,20)==-1){
		perror("listen");
		exit(1);
	}
	printf("server is run \n");
	while(1)
	{
		sin_size = sizeof(their_addr);
		if((new_fd=accept(sockfd,(struct sockaddr*)(&their_addr),(socklen_t*)&sin_size))==-1){
			perror("accept");
			exit(1);
		}
		char buff[50];
		if((numbytes = recv(new_fd,buff,sizeof(buff),0))==-1)
		{
			perror("recv");
			exit(1);

		}
		memset(&temp,0,sizeof(temp));
		memcpy(&temp,buff,sizeof(temp));	
       if(temp.first == 90909090 && temp.second == 9090909)
		   exit(0);

		cout << "recieved " << numbytes << "bytes " << endl;
		cout << "The message is:" << temp.first << "\t"<<  temp.second << endl;
		sum =(temp.first) + (temp.second);
		cout << sum << endl;
		if(send(new_fd,&sum,sizeof( sum),0)== -1)
			perror("send");
		close(new_fd);
		//	exit(0);


		close(new_fd);
	}
	close(sockfd);

	return 0;
}



