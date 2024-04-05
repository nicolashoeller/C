/*
File: execv.c
Date: 05.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* args[] = {"ls", "-l", NULL};

    execv("/bin/ls", args);

    perror("execv failed");

    return -1;
}