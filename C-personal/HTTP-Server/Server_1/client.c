/*
File: client.c
Date: 27.04.2024
Autor: Nicolas Höller
*/

#include "common.h"

#define SERVER_PORT 18000

int main(int argc, char* argv[])
{
    int sockfd, n;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE];

    if (argc != 2)
        error_and_die("usage: .%s <server address>", argv[0]);
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)             //AF_INET == Adress Family - Internet && SOCK_STREAM == Stream socket
        error_and_die("Error while creating the socket!");
    

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);                         //htons == Host to network, short

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)       //"1.2.3.4" --> [1,2,3,4]
        error_and_die("inet_pton error for %s", argv[1]);
    
    if  (connect(sockfd, (SA*) &servaddr, sizeof(servaddr)) < 0)
        error_and_die("connect failed!");
    
    sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
    sendbytes = strlen(sendline);

    //Write request

    printf("Using port %d\n\n-----------------\n\n", SERVER_PORT);

    if (write(sockfd, sendline, sendbytes) != sendbytes)
        error_and_die("Write error");
    
    
    memset(recvline, 0, MAXLINE);

    while ((n = read(sockfd, recvline, MAXLINE-1)) > 0)
    {
        printf("%s", recvline);
    }

    if (n < 0)
        error_and_die("read error");
    
    exit(0);    
}