/*
File: shared_memory4.c
Date: 23.10.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>



int main(int argc, char* argv[])
{
    key_t key = ftok("race_condition", 65);
    int pid;

    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

    int *race_countown = (int *)shmat(shmid, NULL, 0);

    pid = fork();

    if (pid == 0)
    {
        *race_countown = *race_countown + 1;
        printf("Kind\n");
        *race_countown = *race_countown + 1;
        printf("Kind\n");
        *race_countown = *race_countown + 1;
        printf("Kind\n");
        exit(0);
    }
    else
    {
        *race_countown = *race_countown + 2;
        printf("Vater\n");
        *race_countown = *race_countown + 2;
        printf("Vater\n");
        *race_countown = *race_countown + 2;
        printf("Vater\n");
        wait(NULL);
        exit(0);
    }

    return 0;
}