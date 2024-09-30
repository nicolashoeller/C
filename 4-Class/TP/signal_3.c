/*
File: signal_3.c
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
#include <time.h>

int signal_received = 0;

void handle_response(int sig)
{
    signal_received = 1;
}

int main(int argc, char *argv[])
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    time_t sec;
    signal(SIGINT, handle_response);
    int pid = fork();
    int second = 1;
    if (pid == 0)
    {
        while (1)
        {
            signal_received = 0;
            while (!signal_received){}
            signal_received = 0;
            printf("Zeitstempel %d %d Sekunde", time(&sec), second);
            for (int i = 0; i < second; i++)
            {
                printf(".");
            }
            second++;
            printf("\n");
        }
    }
    else
    {
        while (1)
        {
            kill(pid, SIGINT);
            sleep(1);
        }
    }

    return 0;
}