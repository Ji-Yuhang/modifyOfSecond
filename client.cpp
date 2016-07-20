#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct Algo {
//	char types;
	int first;
	int second;
 }msg;
int main(){


	char data[50];
	int buf;
	int sockfd,numbytes;
//	struct Algo msg;
	struct sockaddr_in their_addr;
   // stringstream os;
 

	cin >> msg.first ;
	 cin >> msg.second;

     memset(data,0,sizeof(data));
	 memcpy(data,&msg,sizeof(msg));
	 //建立一个tcp套接口

		
			 if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){
				perror("socket");
				exit(1);
				}
    their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(1212);
	their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&(their_addr.sin_zero),8);
			 if(connect(sockfd,(struct sockaddr*)&their_addr,sizeof(struct sockaddr)) == -1){
				perror("connect");
				exit(1);
				}
			if ((send(sockfd,data,sizeof(data),0)) ==-1)
				{ perror("send");
				exit(1);
				}
            if((numbytes = recv(sockfd,&buf,sizeof(buf),0))==-1){
			perror("recv");
			exit (1);
			}
			cout << buf << endl;
			close(sockfd);
			return 0;
			}

