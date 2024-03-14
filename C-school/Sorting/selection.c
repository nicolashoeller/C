/*
File: selection.c
Date: 14.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LENGHT 20

void selection(int*);
void iniArray(int*);
void printArray(int*);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int array[ARR_LENGHT];

    printf("Unsortiertes Array: \n");

    iniArray(array);
    printArray(array);

    selection(array);

    printf("Sortiertes Array: \n");

    printArray(array);

    return 0;
}

void selection(int * array){
    int temp = 0;
    int min = 0;
    for (int i = 0; i < ARR_LENGHT - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < ARR_LENGHT; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
            
        }

        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
    
    return;
}

void iniArray(int * array){
    for (int i = 0; i < ARR_LENGHT; i++)
    {
        array[i] = rand() % 100;
    }

    return;
}

void printArray(int* array){
    for (int i = 0; i < ARR_LENGHT; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");

    return;
}