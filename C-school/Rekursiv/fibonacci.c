/*
File: fibonacci.c
Date: 11.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(int argc, char* argv[])
{
    int zahl = 0;

    printf("Gib eine Zahl ein: ");
    scanf("%d", &zahl);
    zahl = fibonacci(zahl);

    printf("Das Ergebnis ist: %d\n", zahl);
    return 0;
}

int fibonacci(int n){
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}