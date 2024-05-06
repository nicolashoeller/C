/*
File: signals_1.c
Date: 02.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    int id = fork();

    if (id == 0)
    {
        while (1)
        {
            printf("Hi_");
            usleep(50000);
        }
        
    }
    else
    {
        sleep(2);
        kill(id, SIGSEGV);
    }
    
    

    return 0;
}