/*
File: shared_memory3.c
Date: 24.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    key_t key = rand() % 1000;

    int shmid;
    int *shmaddr;
    int pid;

    if ((shmid = shmget(key, sizeof(int), IPC_CREAT | 0666)) == -1)
        printf("[!] Error getting memory\n");

    if ((shmaddr = shmat(shmid, NULL, 0)) == (int *) -1 )
        printf("[!] Error attaching memory\n");

    pid = fork();

    if (pid == 0)
    {
        printf("Geben sie eine Zahl ein die dem Vaterprozess übergeben werden soll: ");
        scanf("%d", shmaddr);
    }
    else
    {
        wait(NULL);
        printf("Die empfangene Zahl ist: %d", *shmaddr);

        shmdt(shmaddr);
        if (shmctl(shmid, IPC_RMID, NULL) == -1)
            perror("shmctl");
    }

    return 0;
}