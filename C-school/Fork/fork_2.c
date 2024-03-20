/*
File: fork_2.c
Date: 20.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int id = fork();

    if (id < 0)
    {
        printf("Beim forken ist ein Fehler aufgetreten!\n");
        return -1;
    }
    
    if (id > 0)
    {
        printf("Ich bin der Vaterprozess\n");
    }
    else
    {
        printf("Ich bin der Kindprozess\n");
    }
}