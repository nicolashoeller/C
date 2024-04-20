/*
File: smallestArray.c
Date: 19.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>

int _minArray(int index, int* array, int minIndex);
int minArray(int * array, int size);

int main(int argc, char* argv[])
{
    int array[] = {1,2,1,4,53,2,3,0};
    int size = sizeof(array)/sizeof(array[0]);
    int minIndex = minArray(array, size);
    printf("%d", array[minIndex]);

    return 0;
}

int minArray(int * array, int size){
    int minIndex = _minArray(size-1, array, 0);
    return minIndex;
}

int _minArray(int index, int * array, int minIndex){
    if (index < 0)
    {
        return minIndex;
    }
    if (array[index] < array[minIndex])
    {
        minIndex = index;
    }

    return _minArray(index-1, array, minIndex);
}