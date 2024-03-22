/*
File: fork_6.c
Date: 22.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printVars(int var1, int var2);

int var1 = 1;

int main(int argc, char* argv[])
{
    int var2 = 1;
    int id = fork();

    if (id < 0)
        {
            printf("Beim forken ist ein Fehler aufgetreten!\n");
            return -1;
        }
    
    if (id > 0)
    {
        printVars(var1, var2);

        sleep(2);

        printVars(var1, var2);
    }
    else
    {
        sleep(1);

        printVars(var1, var2);

        var1 ++;
        var2 ++;

        printVars(var1, var2);
    }
    
    return 0;
}

void printVars(int var1, int var2){
    printf("KP: Var1: %d, Addr: %p\n", var1, &var1);
    printf("KP: Var2: %d, Addr: %p\n", var2, &var2);
}