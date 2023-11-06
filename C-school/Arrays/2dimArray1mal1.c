/*
File: 2dimArray.c
Date: 06.11.2023
Autor: Nicolas Höller
*/

#include <stdio.h>

int array[10][10] = {0};


int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[i][j]= (i+1)*(j+1);

            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}
