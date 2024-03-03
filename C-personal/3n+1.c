/*
File: 3n+1.c
Date: 03.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    long long n = 0;
    long long temp = n;
    int versuche = 0;

    printf("Bitte gib die Startzahl ein: ");
    scanf("%lld", &n);

    while (1) {
        while(n != 1){
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = 3 * n + 1;
            }
            versuche++;
        }

        printf("Die Anzahl der Versuche von %lld beträgt: %d\n", temp, versuche);
        
        versuche = 0;
        temp++;
        n = temp;
    }  
}