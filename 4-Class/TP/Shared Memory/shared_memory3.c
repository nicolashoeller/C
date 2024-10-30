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
#include <signal.h>

int resume_timer = 1;

void handle_countdown(int sig){
    if (resume_timer)
    {
        resume_timer = 0;
    } else
    {
        resume_timer = 1;
    }
    
}

int main(int argc, char* argv[])
{
    signal(SIGINT, handle_countdown);
    
    key_t key = ftok("key", 65);
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

    int* shared_memory = shmat(shmid, NULL, 0);

    *shared_memory = 0;

    int pid = fork();

    if (pid == 0)
    {
        for (int i = 0; i < 50; i++)
        {
            while(resume_timer);
            *shared_memory = i*2+1;
            printf("Vater: %d\n", *shared_memory);
            resume_timer = 1;
            kill(getppid(), SIGINT);
        }
        
        exit(0);
        
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            while(!resume_timer);
            *shared_memory = i*2;
            printf("Kind: %d\n", *shared_memory);
            resume_timer = 0;
            kill(pid, SIGINT);
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