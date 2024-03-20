/*
File: insertion.c
Date: 18.03.2024
Autor: Nicolas Höller
*/

#include <stdlib.h>
#include <stdio.h>

#define ARR_LENGTH 20

void insertion(int* array);
void verschieben(int* array, int index1, int index2);
void iniArray(int* array);
void printArray(int* array);

int main(int argc, char* argv[])
{
    int array[ARR_LENGTH];

    iniArray(array);

    printf("Before sorting: \n");

    printArray(array);

    insertion(array);

    printf("After sorting: \n");
    
    printArray(array);

    return 0;
}

void insertion(int* array) {
    int j;
    for (int i = 1; i < ARR_LENGTH; i++) {
        j = i;
        while (j > 0 && array[j - 1] > array[j]) {
            verschieben(array, j, j - 1);
            j--;
        }
    }
}

void verschieben(int* array, int index1, int index2){
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
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