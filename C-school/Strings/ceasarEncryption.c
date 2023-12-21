/*
File: ceasarEncryption.c
Date: 21.12.2023
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void ceasarDecryption(char*, int);

int main(int argc, char* argv[])
{
    char stringEingabe[MAX];
    int verschiebung = 0;

    printf("Bitte geben Sie einen String ein: ");
    fgets(stringEingabe, MAX, stdin);
    printf("Um wie viele Stellen soll der String verschoben werden? ");
    scanf("%d", &verschiebung);

    ceasarDecryption(stringEingabe, verschiebung);

    printf("Der verschlüsselte String lautet: %s", stringEingabe);
    return 0;
}

void ceasarDecryption(char* string, int verschiebung)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = ((string[i] - 'a' + verschiebung) % 26) + 'a';
        }
    }
}