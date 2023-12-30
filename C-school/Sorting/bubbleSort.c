/*
File: bubbleSort.c
Date: 30.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

#define ARRLENGTH 20

int main(int argc, char* argv[])
{
    int array[ARRLENGTH] = { 2, 5, 4, 3, 10, 9, 7, 8, 1, 6, 12, 11, 15, 13, 18, 20, 19, 17, 16, 14 };
    int temp = 0;

    for (int i = 0; i < ARRLENGTH; i++)
    {
        for (int j = 0; j < ARRLENGTH - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }

        printf("Durchlauf %d: ", i + 1);
        for (int k = 0; k < ARRLENGTH; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");
    }

    return 0;
}