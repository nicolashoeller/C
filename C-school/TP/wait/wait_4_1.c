/*
File: wait_4_1.c
Date: 03.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int id = fork();    


    if (id == 0)        //K1
    {
        wait(NULL);
        printf("K1: %d\n", getpid());
    }
    else
    {
        printf("P: %d\n", getpid());

        id = fork();
        if (id == 0)    //K2
        {
            printf("K2: %d\n", getpid());

            id = fork();
            if (id == 0)    //KK1
            {
                printf("KK1: %d\n", getpid());
            }
            else
            {
                id = fork();
                if (id == 0)    //KK2
                {
                    printf("KK2: %d\n", getpid());
                }
                
            }
            
            
        }
        else
        {
            id = fork();
            if (id == 0)    //K3
            {
                printf("K3: %d\n", getpid());
            }
            
        }
        
        
    }
    
    
}