/*
File: date.c
Date: 05.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    printf("Parent ID: %d\n", getpid());
    int id = fork();

    if (id == 0)
    {
        char *args[] = {"date", "-u", NULL};
        execv("/bin/date", args);
        perror("execv failed");
    }
    else
    {
        wait(NULL);
        printf("Success! Parent ID: %d\n", getpid());
    }
    
    return 0;
}