/*
File: array.c
Date: 11.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>

int arraySum(int array[], int n);

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Die Summe des Arrays ist %d", arraySum(array, n));
    return 0;
}

int arraySum(int array[], int n) {
    if (n <= 0)
        return 0;
    else
        return (arraySum(array, n - 1) + array[n - 1]);
}