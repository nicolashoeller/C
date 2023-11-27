/*
File: main.c
Date: 27.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

int berechnung();

int main()
{
    int a = 0;
    scanf("%d", &a);
    a = berechnung(a);
    printf("%d", a);
}

int berechnung(int a){
    if (a<0)
    {
        return -1;
    }
    else if (a>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}