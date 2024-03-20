/*
File: insertion.c
Date: 18.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ARR_LENGHT 20

void insertion();
void verschieben(int*, int, int);
void iniArray(int*);

int main(int argc, char* argv[])
{
    int array[ARR_LENGHT];

    iniArray(array);
}

void verschieben(int* array, int index1, int index2){
    
}

void iniArray(int * array){
    for (int i = 0; i < ARR_LENGHT; i++)
    {
        array[i] = rand() % 100;
    }

    return;
}
