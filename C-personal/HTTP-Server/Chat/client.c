/*
File: client.c
Date: 27.04.2024
Autor: Nicolas Höller
*/

#include "common.h"

#define SERVER_PORT 18000

void createNewThread(int socketfd);
void listenAndPrint(int socketfd);

int main(int argc, char *argv[])
{
    int socketfd, result;
    char *ip_address = argv[1];
    char *line = NULL;
    char *name = NULL;
    char buffer[4096];
    struct sockaddr_in *servaddr;
    size_t lineSize = 0;
    size_t nameSize = 0;
    ssize_t charCount = 0;
    ssize_t nameCount = 0;

    if (argc != 2)
        error_and_die("[!] Usage: %s <server address>\n", argv[0]);

    if ((socketfd = create_Ipv4_Socket()) < 0)
        error_and_die("[!] Failed to create socket.\n");
    printf("[*] Socket successfully created.\n");

    if (!(servaddr = setup_server_address(ip_address, SERVER_PORT)))
        error_and_die("[!] Failed to set up server address or convert IP address '%s' to binary form.\n", ip_address);
    printf("[*] Successfully converted IP address '%s' to binary form.\n", ip_address);

    if ((result = connect(socketfd, (SA *)servaddr, sizeof(*servaddr))) != 0)
        error_and_die("[!] Failed to establish connection with server at %s:%d\n", ip_address, SERVER_PORT);
    printf("[*] Successfully established connection with server at %s:%d\n", ip_address, SERVER_PORT);

    printf("[*] Welcome in the chat room... (type exit to disconnect)\n");

    do
    {
        printf("--------------------------------\n[*] Username: ");
        nameCount = getline(&name, &nameSize, stdin);
    } while (nameCount == 1);

    name[strlen(name) - 1] = '\0';

    createNewThread(socketfd);

    while (true)
    {
        if ((charCount = getline(&line, &lineSize, stdin)) > 0)
        {
            if (!strcmp(line, "exit\n"))
            {
                printf("[*] Disconnecting...\n");
                break;
            }
            line[lineSize - 1] = '\0';
            sprintf(buffer, "%s: %s", name, line);

            size_t wasSend = send(socketfd, buffer, strlen(buffer), 0);
        }
    }

    close(socketfd);

    return 0;
}

void createNewThread(int socketfd)
{
    pthread_t id;
    pthread_create(&id, NULL, (void*)listenAndPrint, socketfd);
}

void listenAndPrint(int socketfd)
{
    char buffer[4096];
    ssize_t amountReceived;

    while (true)
    {
        amountReceived = recv(socketfd, buffer, sizeof(buffer) - 1, 0);
        if (amountReceived > 0)
        {
            buffer[amountReceived] = '\0';
            printf("%s", buffer);
        }

        if (amountReceived <= 0)
            break;
    }
    close(socketfd);
}