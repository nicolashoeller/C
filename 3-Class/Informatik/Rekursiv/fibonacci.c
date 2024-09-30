/*
File: fibonacci.c
Date: 14.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 

int fibonacci(int n, int* cache);

int main(int argc, char* argv[])
{
    int zahl = 0;

    printf("Gib eine Zahl ein: ");
    scanf("%d", &zahl);

    int cache[MAX];
    for(int i=0; i<MAX; i++){
        cache[i] = -1;
    }

    zahl = fibonacci(zahl, cache);

    printf("Das Ergebnis ist: %d\n", zahl);

    return 0;
}

int fibonacci(int n, int* cache){
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
        if(cache[n] == -1){
            cache[n] = fibonacci(n - 1, cache) + fibonacci(n - 2, cache);
        }
        return cache[n];
    }
}