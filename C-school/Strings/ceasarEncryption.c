/*
File: ceasarEncryption.c
Date: 21.12.2023
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, char* argv[])
{
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                      'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                      'u', 'v', 'w', 'x', 'y', 'z'};

    char stringEingabe[MAX];
    int verschiebung = 0;

    printf("Bitte geben Sie einen String ein: ");
    fgets(stringEingabe, MAX, stdin);
    printf("Um wie viele Stellen soll der String verschoben werden? ");
    scanf("%d", &verschiebung);

    for (int i = 0; stringEingabe[i] != '\0'; i++)
    {
        if (stringEingabe[i] >= 'a' && stringEingabe[i] <= 'z') {
            stringEingabe[i] = ((stringEingabe[i] - 'a' + verschiebung) % 26) + 'a';
        }
    }


    printf("Der verschlüsselte String lautet: %s", stringEingabe);
    return 0;
}