/*
File: wait_3.c
Date: 27.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int anzahl = 0;

    printf("Gib die Anzahl der Prozesse ein: ");
    scanf("%d", &anzahl);
    int id = getpid();

    for (int i = 0; i < anzahl; i++)
    {
        if (id > 0) {
            id = fork();
        }
    }

    if (id == 0)
    {
        printf("Kindprozess mit PID %d erstellt\n", getpid());
    }
    

    if (id > 0)
    {
        wait(NULL);
    }

    return 0;
    
}