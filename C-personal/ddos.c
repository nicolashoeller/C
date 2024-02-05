#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <target_ip> <target_port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &target.sin_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) < 0) {
        perror("connect");
        return 1;
    }

    while (1) {
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        send(sock, buffer, sizeof(buffer), 0);
    }

    close(sock);
    return 0;
}