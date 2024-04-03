/*
File: wait_4.c
Date: 27.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fehler beim Erzeugen des Kindprozesses.\n");
        return -1;
    }

    if (pid == 0)
    {
        printf("K1: %d\n", getpid());
        pid_t pid2 = fork();

        if (pid2 == 0)
        {
            printf("KK1: %d\n", getpid());
        }
        else
        {
            wait(NULL);
            printf("K1: %d\n", getpid());
            pid_t pid3 = fork();

            if (pid3 == 0)
            {
                printf("KK2: %d\n", getpid());
            }
            else
            {
                wait(NULL);
                printf("K1: %d\n", getpid());
            }
        }
    }
    else
    {
        wait(NULL);
        printf("P: %d\n", getpid());
        pid_t pid4 = fork();

        if (pid4 == 0)
        {
            printf("K2: %d\n", getpid());
        }
        else
        {
            wait(NULL);
            printf("P: %d\n", getpid());
        }
    }

    return 0;
}