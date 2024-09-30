/*
File: fork_4.c
Date: 22.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int c = 5;
    int id = fork();

    if (id == 0)
    {
        c += 5;
    }
    else
    {
        id = fork();
        c += 10;
        if (id)
        {
            c += 10;
        }
    }

    fork();
    printf("%d\n", c);
    
    return 0;
}