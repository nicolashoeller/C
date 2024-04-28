#include "common.h"

void error_and_die(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}

int create_Ipv4_Socket() {
    return socket(AF_INET, SOCK_STREAM, 0);
}

struct sockaddr_in* setup_server_address(const char *ip_address, int port) {
    struct sockaddr_in *servaddr = malloc(sizeof(struct sockaddr_in));
    if (servaddr) {
        bzero(servaddr, sizeof(*servaddr));
        servaddr->sin_family = AF_INET;
        servaddr->sin_port = htons(port);

        if (strlen(ip_address) == 0)
            {servaddr->sin_addr.s_addr = INADDR_ANY;}
        else
            if (inet_pton(AF_INET, ip_address, &servaddr->sin_addr.s_addr) <= 0){
                free(servaddr);
                servaddr = NULL;
            }
    }
    return servaddr;
}
