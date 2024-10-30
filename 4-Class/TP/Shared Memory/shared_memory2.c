/*
File: shared_memory2.c
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
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

    int* shared_memory = shmat(shmid, NULL, 0);

    *shared_memory = 0;

    int pid = fork();

    if (pid == 0)
    {
        while (1)
        {
            if (*shared_memory == 20)
            {
                break;
            }

            if (*shared_memory % 2 != 0)
            {
                *shared_memory = *shared_memory + 1;
                printf("Kind: %d\n", *shared_memory);
            }
        }
        exit(0);
        
    }
    else
    {
        while (1)
        {
            if (*shared_memory == 20)
            {
                break;
            }
            
            if (*shared_memory % 2 == 0)
            {
                *shared_memory = *shared_memory + 1;
                printf("Vater: %d\n", *shared_memory);
            }
        }

        wait(NULL);

        shmdt(shared_memory);
        if (shmctl(shmid, IPC_RMID, NULL) < 0){
            perror("shmctl: ");
        }
        exit(0);
    }
    return 0;
}