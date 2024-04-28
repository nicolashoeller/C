/*
File: client.c
Date: 27.04.2024
Autor: Nicolas Höller
*/

#include "common.h"

#define SERVER_PORT 18000

int main(int argc, char *argv[])
{
    int socketfd, result;
    char*message;
    char buffer[4096];
    char*ip_address = argv[1];
    struct sockaddr_in *servaddr;

    if (argc != 2)
        error_and_die("[!] Usage: %s <server address>\n", argv[0]);

    if ((socketfd = create_Ipv4_Socket()) < 0)
        error_and_die("[!] Failed to create socket.\n");
    printf("[*] Socket successfully created.\n");
    
    if (!(servaddr = setup_server_address(ip_address, SERVER_PORT)))
        error_and_die("[!] Failed to set up server address or convert IP address '%s' to binary form.\n", ip_address);
    printf("[*] Successfully converted IP address '%s' to binary form.\n", ip_address);

    if ((result = connect(socketfd, (SA*)servaddr, sizeof(*servaddr))) != 0)
        error_and_die("[!] Failed to establish connection with server at %s:%d\n", ip_address, SERVER_PORT);
    
    printf("[*] Successfully established connection with server at %s:%d\n", ip_address, SERVER_PORT);


    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socketfd, message, strlen(message), 0);

    recv(socketfd, buffer, sizeof(buffer), 0);

    printf("\nResponse: %s", buffer);

    return 0;
}