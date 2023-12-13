/*
File: parameterToArray.c
Date: 13.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int array[argc];
    int values = 0;

    for (int i = 0; i < argc; i++)
    {
        values = atoi(argv[i]);
        array[i] = values;
    }
    for (int i = 0; i < argc; i++)
    {
        printf("%d\n", array[i]);
    }

    
    return 0;
}