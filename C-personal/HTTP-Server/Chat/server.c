/*
File: server.c
Date: 27.04.2024
Autor: Nicolas Höller
*/

#include "common.h"

#define SERVER_PORT 18000

int main(int argc, char* argv[])
{
    int serverfd, clientfd,result;
    char buffer[4096];
    struct sockaddr_in *servaddr;

    if ((serverfd = create_Ipv4_Socket()) < 0)
        error_and_die("[!] Failed to create socket.\n");
    printf("[*] Socket successfully created.\n");

    if (!(servaddr = setup_server_address("", SERVER_PORT)))
        error_and_die("[!] Failed to set up server address or convert IP address to binary form.\n");
    printf("[*] Successfully converted IP address to binary form.\n");

    if ((result = bind(serverfd, (SA*)servaddr, sizeof(*servaddr))) < 0)
        error_and_die("[!] Failed to bind the socket to the server address.\n");
    printf("[*] Successfully bound the socket to the server address.\n");

    if ((result = listen(serverfd, 10)) < 0)
        error_and_die("[!] Failed to start listening on the socket.\n");
    printf("[*] Successfully started listening on port %d.\n", SERVER_PORT);

    struct sockaddr_in clientAddress;
    int clientAddressSize = sizeof(clientAddress);

    if ((clientfd = accept(serverfd, (SA *)&clientAddress, (socklen_t*)&clientAddressSize)) < 0)
        error_and_die("[!] Failed to accept the client connection.\n");
    printf("[*] Successfully accepted the client connection.\n");

    recv(clientfd, buffer, sizeof(buffer), 0);

    printf("\nResponse: %s", buffer);

    return 0;
}