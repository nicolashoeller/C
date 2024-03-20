/*
File: bubbleSort.c
Date: 30.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 20

void iniArray(int* array);
void printArray(int* array);
void bubble(int* array);

int main(int argc, char* argv[])
{
    int array[ARR_LENGTH];

    iniArray(array);
    
    printf("Unsortiertes Array: \n");
    printArray(array);

    bubble(array);

    printf("Sortiertes Array: \n");
    printArray(array);

    return 0;
}

void bubble(int* array){
    int temp = 0;

    for (int i = 0; i < ARR_LENGTH; i++)
    {
        for (int j = 0; j < ARR_LENGTH - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }

    }
}

void iniArray(int * array){
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        array[i] = rand() % 100;
    }
}

void printArray(int* array){
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}