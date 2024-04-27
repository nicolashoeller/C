#include "common.h"

void error_and_die(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}

char *bin2hex(const unsigned char *input, size_t len) {
    char *result;
    char *hexits = "0123456789ABCDEF";

    if (input == NULL || len <= 0)
        return NULL;

    int resultlenght = (len*3)+1;

    result = malloc(resultlenght);
    bzero(result, resultlenght);

    for (int i = 0; i < len; i++)
    {
        result[i*3] = hexits[input[i] >> 4];
        result[(i*3)+1] = hexits[input[i] &0x0F];
        result[(i*3)+1] = ' ';
    }

    return result;
}