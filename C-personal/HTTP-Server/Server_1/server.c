/*
File: server.c
Date: 27.04.2024
Autor: Nicolas Höller
*/

#include "common.h"

#define SERVER_PORT 18000

int main(int argc, char const *argv[])
{
    int listenfd, connfd, n;
    struct sockaddr_in servaddr;
    uint8_t buff[MAXLINE + 1];
    uint8_t recvline[MAXLINE + 1];

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error_and_die("socket error.");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT);

    if ((bind(listenfd, (SA *)&servaddr, sizeof(servaddr))) < 0)
        error_and_die("bind error.");

    if ((listen(listenfd, 10)) < 0)
        error_and_die("listen error.");

    for (;;)
    {
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr); // Initialize addr_len
        char client_address[MAXLINE + 1];

        printf("----------------------------------\nWaiting for connection on port %d\n\n", SERVER_PORT);
        fflush(stdout);
        connfd = accept(listenfd, (SA *)&addr, &addr_len);

        inet_ntop(AF_INET, &addr.sin_addr, client_address, MAXLINE); // Use addr.sin_addr instead of addr
        printf("Client address: %s\n", client_address);

        memset(recvline, 0, MAXLINE);

        while ((n = read(connfd, recvline, MAXLINE - 1)) > 0)
        {
            fprintf(stdout, "\n%s\n\n%s", bin2hex(recvline, n), recvline);

            if (recvline[n - 1] == '\n')
                break;

            memset(recvline, 0, MAXLINE);
        }

        if (n < 0)
            error_and_die("read error.");

        // response

        snprintf((char *)buff, sizeof(buff), "HTTP/1.0 200 OK\r\n\r\nResponse");

        write(connfd, (char *)buff, strlen((char *)buff));
        close(connfd);
    }
}
