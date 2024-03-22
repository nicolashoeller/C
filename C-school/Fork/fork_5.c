/*
File: fork_5.c
Date: 22.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("EP: %d\n", getpid());

    if (!fork())
    {
        sleep(1);
        printf("KP: %d, EP: %d", getpid(), getppid());
    }

    return 0;
}