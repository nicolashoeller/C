/*
File: reverse_string.c
Date: 04.11.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define SHM_SIZE 20

volatile int proceed = 0;
volatile int proceed2 = 0;

void handleSignal(int sig)
{
    proceed = 1;
}

void handleSecondSignal(int sig)
{
    proceed2 = 1;
}

int main(int argc, char *argv[])
{
    signal(SIGUSR1, handleSignal);
    signal(SIGUSR2, handleSecondSignal);

    int pid;
    int shmid;
    char *shared_address;

    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    if ((shared_address = (char *)shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    int pid1 = getpid();

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            while (!proceed);
            printf("Kind 2: Invertierter String: %s\n", shared_address);

            kill(pid1, SIGUSR2);
            printf("Kind 2: Signal zur Bestätigung an Vater gesendet\n\n");

            if (shmdt(shared_address) == -1)
            {
                perror("shmdt");
                exit(EXIT_FAILURE);
            }

            exit(0);
        }
        else
        {
            while (!proceed2);

            int first = 0;
            int last = strlen(shared_address) - 1;
            char temp;

            while (first < last)
            {

                temp = shared_address[first];
                shared_address[first] = shared_address[last];
                shared_address[last] = temp;

                first++;
                last--;
            }

            printf("Kind 1: String invertiert\n");

            kill(pid, SIGUSR1);
            printf("Kind 1: Signal zum Ausgeben an Kind 2 gesendet\n\n");
            wait(NULL);

            if (shmdt(shared_address) == -1)
            {
                perror("shmdt");
                exit(EXIT_FAILURE);
            }

            exit(0);
        }
    }
    else
    {
        strcpy(shared_address, "Hallo vom Vater");
        printf("Vater: \"%s\" in die Shared Memory geschrieben\n", shared_address);

        kill(pid, SIGUSR2);
        printf("Vater: Signal zum invertieren an Kind 1 gesendet\n\n");

        while (!proceed2);

        printf("Vater: Beide Kinder haben die Nachricht verarbeitet!\n");

        wait(NULL);

        if (shmdt(shared_address) == -1)
        {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        if (shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}