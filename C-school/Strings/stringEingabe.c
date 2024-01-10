/*
File: stringEingabe.c
Date: 20.12.2023
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void processString(char *, int);
void capsAfterSpace(char *);

int main(int argc, char *argv[])
{
    char string[MAX];
    int option;

    printf("Bitte geben Sie einen String ein: ");
    fgets(string, MAX, stdin); // fgets liest auch Leerzeichen ein, stdin ist der Standardinput (Tastatur)

    printf("Soll der String in Großbuchstaben (1) oder in Kleinbuchstaben (2) ausgegeben werden?\n", string);
    scanf("%d", &option);

    processString(string, option);
    capsAfterSpace(string);
    printf("%s", string);

    return 0;
}

void capsAfterSpace(char *string)
{
    if (string[0] >= 'a' && string[0] <= 'z')
    {
        string[0] = string[0] - 32;
    }
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == ' ')
        {
            if (string[i + 1] >= 'a' && string[i + 1] <= 'z')
            {
                string[i + 1] = string[i + 1] - 32;
            }
        }
    }
}

void processString(char *string, int option)
{
    switch (option)
    {
    case 1:
        for (int i = 0; string[i] != '\0'; i++)
        {
            if (string[i] >= 'a' && string[i] <= 'z')
            {
                string[i] = string[i] - 32;
            }
        }
        break;
    case 2:
        for (int i = 0; string[i] != '\0'; i++)
        {
            if (string[i] >= 'A' && string[i] <= 'Z')
            {
                string[i] = string[i] + 32;
            }
        }
        break;
    }
}