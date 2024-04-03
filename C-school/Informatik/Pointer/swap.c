/*
File: swap.c
Date: 03.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char* argv[])
{
    int x = 10;
    int y = 5;

    printf("Before swap:\n");
    printf("x: %d, y: %d\n\n", x, y);

    swap(&x, &y);

    printf("After swap:\n");
    printf("x: %d, y: %d\n", x, y);

    return 0;
}