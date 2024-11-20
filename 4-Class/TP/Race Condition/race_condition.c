/*
File: race_condition.c
Date: 06.11.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

int main(int argc, char* argv[])
{
    int pid;
    int shmid;
    int* shared_address;

    if ((shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666)) == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    if ((shared_address = (int*)shmat(shmid, NULL, 0)) == (int*)-1)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    } 

    pid = fork();

    if (pid == 0)
    {
        /* code */
    }
    else
    {
        /* code */
    }

    return 0;
}