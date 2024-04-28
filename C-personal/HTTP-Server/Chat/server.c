/*
File: server.c
Date: 27.04.2024
Autor: Nicolas Höller
*/

#include "common.h"

#define SERVER_PORT 18000

struct AcceptedSocket
{
    int acceptedSocketFD;
    struct sockaddr_in address;
    int error;
    bool acceptedSuccessfully;
};

struct AcceptedSocket acceptedSockets[30];
int acceptedSocketsCount = 0;

struct AcceptedSocket * acceptClientConnection(int serverfd);
void receiveAndPrintResponse(int clientSocketFD);
void startIncomingConnections(int serverfd);
void createNewThread(struct AcceptedSocket*pSocket);
void sendReceivedMessageToClients(char* buffer, int socketfd);

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

    startIncomingConnections(serverfd);

    printf("[*] Shutting down server..\n\n");

    if (shutdown(serverfd, SHUT_RDWR) < 0)
        error_and_die("[!] Failed to shutdown the server socket.\n");

    return 0;
}

struct AcceptedSocket* acceptClientConnection(int serverfd) {
    struct sockaddr_in clientAddress;
    int clientAddressSize = sizeof(struct sockaddr_in);
    int clientfd = accept(serverfd, (SA*)&clientAddress, (socklen_t*)&clientAddressSize);

    struct AcceptedSocket*acceptedSocket = malloc(sizeof(struct AcceptedSocket));
    acceptedSocket->address = clientAddress;
    acceptedSocket->acceptedSocketFD = clientfd;
    acceptedSocket->acceptedSuccessfully = clientfd > 0;

    if (!acceptedSocket->acceptedSuccessfully)
        acceptedSocket->error = clientfd;
    
    return acceptedSocket;
}

void receiveAndPrintResponse(int clientSocketFD) {
    char buffer[4096];
    ssize_t amountReceived;

    while (true) {
        amountReceived = recv(clientSocketFD, buffer, sizeof(buffer) - 1, 0);
        if (amountReceived > 0) {
            buffer[amountReceived] = '\0';
            printf("%s", buffer);

            sendReceivedMessageToClients(buffer, clientSocketFD);
        }

        if (amountReceived <= 0)
            break;
    }
    close(clientSocketFD);
}

void sendReceivedMessageToClients(char* buffer, int socketfd){
    for (int i = 0; i < acceptedSocketsCount; i++)
    {
        if (acceptedSockets[i].acceptedSocketFD != socketfd)
        {
            send(acceptedSockets[i].acceptedSocketFD, buffer, strlen(buffer), 0);
        }
    }
    
}

void startIncomingConnections(int serverfd){
    while (true)
    {
        struct AcceptedSocket*clientSocket = acceptClientConnection(serverfd);
        acceptedSockets[acceptedSocketsCount++] = *clientSocket;

        createNewThread(clientSocket);
    }
}

void createNewThread(struct AcceptedSocket*pSocket){
    pthread_t id;
    pthread_create(&id, NULL, receiveAndPrintResponse, pSocket->acceptedSocketFD);
}