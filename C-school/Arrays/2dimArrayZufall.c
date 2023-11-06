/*
File: 2dimArrayZufall.c
Date: 06.11.2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

int main()
{
    srand(time(NULL));

    int array[7][13] = {0};
    int sum[7] = {0};
    int bigNum = 0;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            array[i][j] = rand() % 501 + 500;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    printf("---------------------------------------------\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 13; j++) {
            sum[i] += array[i][j];
        }
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d\t",sum[i]);
    }

    printf("\n---------------------------------------------\n");
    
    for (int i = 0; i < 7; i++)
    {
        if (sum[i] > sum[0])
        {
            sum[0] = sum[i];
        }

    }
    printf("\n%d", sum[0]);
    
}