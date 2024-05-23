/*
File: shared_memory2.c
Date: 23.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <sys/ipc.h>

void error_and_die(const char* error);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    //Vars for shared memory
    int shmid;
    int ctlErrCode;
    int key = rand() % 1000;
    char *shared_memory;

    //Vars for fork
    int pid;

    if ((shmid = shmget(key, 100 * sizeof(char), IPC_CREAT | 0666)) == -1)
        error_and_die("[!] Error getting memory");

    if ((shared_memory = shmat(shmid, NULL, 0)) == (char*)-1)
        error_and_die("[!] Error attaching memory");

    if ((pid = fork()) == -1)
        error_and_die("[!] Error forking");
    
    if (pid == 0)
    {
        char* character = "Hi";
        strcpy(shared_memory, character);
    }
    else
    {
        wait(NULL);
        char character[100];
        strcpy(character, shared_memory);
        printf("%s", character);

        if (shmdt(shared_memory) == -1)
            error_and_die("[!] Error detaching memory");

        if (shmctl(shmid, IPC_RMID, NULL) == -1)
            error_and_die("[!] Error deleting memory segment");
    }
    
    return 0;
}

void error_and_die(const char* error) {
    printf("%s", error);
    printf("\n");
    exit(0);
}