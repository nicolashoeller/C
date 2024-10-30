/*
File: shared_memory1.c
Date: 21.10.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    key_t key = ftok("key", 65);
    int shmid = shmget(key, sizeof(char*), IPC_CREAT | 0666);

    char* shared_memory = (char*)shmat(shmid, NULL, 0);

    strcpy(shared_memory, "Hallo Welt!");

    printf("%s", shared_memory);

    shmdt(shared_memory);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}