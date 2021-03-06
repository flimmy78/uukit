//date 11.8 by gong
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <string>

#define BUFSIZE 1024
#include <iostream>
using namespace std;

int sockfd;
int portno; /* port to listen on */
struct sockaddr_in clientaddr; /* client addr */
struct hostent *hostp; /* client host info */

char *hostaddrp; /* dotted decimal host addr string */		
pthread_t pid;

//printf error 
void error(string str) {
  perror(str.c_str());
  exit(1);
}
int recieveData(int sfd,char* buf,struct sockaddr_in &clientaddr);
int buiSocAndBind(int &sfd,int port){

	int optval; /* flag value for setsockopt */
	struct sockaddr_in serveraddr; /* server's addr */
	
	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sfd < 0){ 
		error("ERROR opening socket");
		return -1;
	}

	optval = 1;
	setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, 
	     (const void *)&optval , sizeof(int));

	//build server's Internet address
	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)port);

	//bind socket with a port 
	if (bind(sfd, (struct sockaddr *) &serveraddr, 
	   sizeof(serveraddr)) < 0) {
		
		error("ERROR on binding");	
		return -1;
	}	
	return 0;
}

int sendData(int sfd,char* buf,struct sockaddr_in cli_addr){
	
	//send data
	int n; /* message byte size */
	socklen_t clientlen= sizeof(cli_addr);
	
    n = sendto(sfd, buf, strlen(buf), 0, 
	  (struct sockaddr *) &cli_addr, clientlen);
    if (n < 0) {
		error("ERROR in sendto");
		return -1;
	}	
	return 0;
	//business...
}

void* threadFunc(void *agrv){
	
	char buf[BUFSIZE]; /* message buf */
	bzero(buf, BUFSIZE);
	int sockfd;
	struct sockaddr_in clientaddr;
	sockfd = *(((int**)agrv)[0]);
	clientaddr = *(((struct sockaddr_in**)agrv)[1]);
		
	while (1) 
	{
	
	//recieve data
	if(recieveData(sockfd,buf,clientaddr)!=0){
		
		cout<<"ERROR:recieveData"<<endl;
		continue ;
	}
	//send data
	if(sendData(sockfd,buf,clientaddr)!=0){
		cout<<"ERROR:sendData"<<endl;
		continue ;
	}
    sleep(1);
    
	}	
		
}

int recieveData(int sfd,char* buf,struct sockaddr_in &clientaddr){

	int n=0;
	socklen_t clientlen = sizeof(clientaddr);
	n = recvfrom(sfd, buf, BUFSIZE, 0,
		 (struct sockaddr *) &clientaddr, &clientlen);
    if (n < 0){
		error("ERROR in recvfrom");
		return -1;
	}

    //gethostbyaddr: determine who sent the datagram
    hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
			  sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
		error("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
		error("ERROR on inet_ntoa\n");
	
    printf("server received datagram from %s (%s)::%u\n", 
	   hostp->h_name, hostaddrp,clientaddr.sin_port);
    printf("server received %d/%d bytes: %s\n", strlen(buf), n, buf);
	return 0;
	//business .....	
}

int main(int argc, char **argv) {

	int error;
	if (argc != 2) {
		fprintf(stderr, "usage: %s \n", argv[0]);
		exit(1);
	}
	
	portno = atoi(argv[1]);  //port

	if(buiSocAndBind(sockfd,portno)!=0) //importand function
		return -1;
			
	//transform argv
	void* args[2]={(void*)&sockfd,(void*)&clientaddr};
	//create thread 
	error=pthread_create(&pid,NULL,&threadFunc,args);
	if(error!=0)
		cout<<"create thread fail"<<endl;
	cout<<"return main"<<endl;
	
	pthread_join(pid,NULL);
	return 0;
}





