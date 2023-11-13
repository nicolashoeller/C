/*
File: sqrt.c
Date: 11.11.2023
Autor: Nicolas Höller
*/

#include<stdio.h>

void main()
{
    int number;

    float temp, sqrt;

    printf("Provide the number: \n");

    scanf("%d", &number);

    sqrt = number / 2;
    temp = 0;

    while(sqrt != temp){

        temp = sqrt;


        sqrt = ( number/temp + temp) / 2;
    }

    printf("The square root of '%d' is '%d'", number, (int)sqrt);
}
