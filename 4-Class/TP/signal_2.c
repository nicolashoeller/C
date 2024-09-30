/*
File: signal_2.c
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

int signal_received;

void handle_signal(int sig)
{
    signal_received = 1;
}

int main(int argc, char* argv[])
{
    signal(SIGINT, handle_signal);
    int pid = fork();
    if (pid == 0)
    {
        kill(getppid(), SIGINT);
        signal_received = 0;
        printf("Child: waiting for signal\n");
        while (!signal_received){}
        signal_received = 0;
        printf("Child: signal received\n");
        kill(getppid(), SIGINT);
    }
    else
    {
        while (!signal_received){}
        signal_received = 0;
        printf("Parent: sending signal\n");
        kill(pid, SIGINT);
        printf("Parent: waiting for response\n");
        while (!signal_received){}
        signal_received = 0;
        printf("Parent: response received\n");
    }
    
    return 0;
}