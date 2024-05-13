/*
File: shared_merory1.c
Date: 13.05.2024
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
    int shmid;
    key_t key = 1234;
    char *shared_memory;
    char string[15] = "Hello World!";

    if ((shmid = shmget(key, sizeof(char), IPC_CREAT)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shared_memory = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    strcpy(shared_memory, string);

    wait(NULL);
    printf("Value from shared memory: %s\n", shared_memory); 

    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}