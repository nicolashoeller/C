/*
File: fork.c
Date: 18.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int id = fork();

    for (int i = 0; i < 100000; i++)
    {
        id = getpid();
        printf("Nr. %d -- ID: %d\n", i, id);
    }
    
    return 0;
}