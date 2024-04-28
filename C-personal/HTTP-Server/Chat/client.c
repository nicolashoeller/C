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
    char*ip_address = argv[1];
    char*line = NULL;
    char buffer[4096];
    struct sockaddr_in *servaddr;
    size_t lineSize = 0;
    ssize_t charCount;

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

    printf("[*] Welcome in the chat room... (type exit to disconnect)\n\n");

    while (true)
    {
        if ((charCount = getline(&line, &lineSize, stdin)) > 0){
            if (!strcmp(line, "exit\n")){
                printf("[*] Disconnecting...\n");
                break;
            }
            
            size_t wasSend = send(socketfd, line, charCount, 0);
        }
    }

    close(socketfd);

    return 0;
}