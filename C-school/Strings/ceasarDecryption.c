/*
File: ceasarEncryption.c
Date: 21.12.2023
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stringInput(char *);
void ceasarDecryption(char *, int);
void ceasarEncryption(char *);

int main(int argc, char *argv[])
{
    char stringEingabe[MAX];
    int verschiebung = 0;
    int auswahl = 0;

    printf("Möchten Sie einen String verschlüsseln (1) oder entschlüsseln (2)? ");
    scanf("%d", &auswahl);

    if (auswahl == 1)
    {
        verschiebung = stringInput(stringEingabe);
        ceasarDecryption(stringEingabe, verschiebung);
        printf("Der verschlüsselte String lautet: %s", stringEingabe);
    }
    else if (auswahl == 2)
    {
        fflush(stdin);
        fgets(stringEingabe, MAX, stdin);
        ceasarEncryption(stringEingabe);
        printf("Der entschlüsselte String lautet: %s", stringEingabe);
    }
    else
    {
        printf("Ungültige Eingabe!");
    }

    return 0;
}

int stringInput(char *string)
{
    int verschiebung = 0;
    printf("Bitte geben Sie einen String ein: ");
    fgets(string, MAX, stdin);
    printf("Um wie viele Stellen soll der String verschoben werden? ");
    scanf("%d", &verschiebung);

    return verschiebung;
}

void ceasarEncryption(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = ((string[i] - 'a' - i) % 26) + 'a';
        }
    }
}

void ceasarDecryption(char *string, int verschiebung)
{
    for (int i = 0; i < 26; i++)
    {
        for (int i = 0; string[i] != '\0'; i++)
        {
            if (string[i] >= 'a' && string[i] <= 'z')
            {
                string[i] = ((string[i] - 'a' + i) % 26) + 'a';
            }
        }
        printf("%s\n", string);
    }
}