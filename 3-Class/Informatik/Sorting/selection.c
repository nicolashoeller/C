/*
File: selection.c
Date: 14.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LENGTH 20

void selectionSortRecursive(int *array, int start, int n) ;
void iniArray(int*);
void printArray(int*);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int array[ARR_LENGTH];

    printf("Unsortiertes Array: \n");

    iniArray(array);
    printArray(array);

    selectionSortRecursive(array, 0, ARR_LENGTH);

    printf("Sortiertes Array: \n");

    printArray(array);

    return 0;
}

void selectionSortRecursive(int *array, int start, int n) {
    if (start >= n-1){
        return;
    }

    int min_index = start;
    for (int i = start+1; i < n; i++) {
        if (array[i] < array[min_index]){
            min_index = i;
        }
    }

    if (min_index != start) {
        int temp = array[start];
        array[start] = array[min_index];
        array[min_index] = temp;
    }

    selectionSortRecursive(array, start+1, n);
}

void iniArray(int * array){
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        array[i] = rand() % 100;
    }

    return;
}

void printArray(int* array){
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");

    return;
}