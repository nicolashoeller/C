/*
File: parameterToArray.c
Date: 13.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

void store(int argc, char* argv[argc], int array[argc]);
void printArray(int argc, int array[argc]);

int main(int argc, char* argv[])
{
    int array[argc];

    store(argc, argv, array);
    printArray(argc, array);
    
    return 0;
}

void store(int argc, char* argv[argc], int array[argc]){
    int values = 0;

    for (int i = 0; i < argc; i++)
    {
        values = atoi(argv[i]);
        array[i] = values;
    }
}

void printArray(int argc, int array[argc]){
    for (int i = 0; i < argc; i++)
    {
        printf("%d\n", array[i]);
    }
}