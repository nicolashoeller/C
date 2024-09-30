/*
File: str.c
Date: 22.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

int lenghtFn(char* string, int index);

int main(int argc, char* argv[])
{
    char*string = "Hallo Welt";

    int lenght = lenghtFn(string, 0);

    printf("%d", lenght);

    return 0;
}

int lenghtFn(char* string, int index){
    if (string[index] == '\0')
    {
        return index;
    }

    return lenghtFn(string, index+1);
}