/*
File: primzahlen.c
Date: 27.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

int primzahlen(int);

int main()
{
    int grenze = 0;

    printf("Gib ein bis zu welcher Zahl die Primzahl ausgegeben werden sollen\n----> ");
    scanf("%d", &grenze);
    printf("----------------------\n");

    if (grenze <= 2)
    {
        printf("Gib eine groessere Zahl ein!");
    }
    else
    {
        for (int i = 0; i < grenze; i++)
        {
            if (primzahlen(i) == 0)
            {
                printf("%d\n", i);
            }
        }
    }
}

int primzahlen(int i)
{
    if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}