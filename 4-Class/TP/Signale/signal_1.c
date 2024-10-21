/*
File: signal.c
Date: 23.09.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <signal.h>

void sig_handler(int signum){
    printf("\nInside handler function\n");
}

int main(int argc, char* argv[])
{
    signal(SIGINT, sig_handler);
    for (int i = 1;; i++)
    {
        printf("%d : Inside main function\n", i);
        sleep(1);
    }

    return 0;
}