/*
File: stringEingabe.c
Date: 20.12.2023
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

void processString(char string[], int option)
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
            printf("%s", string);
            break;
        case 2: 
            for (int i = 0; string[i] != '\0'; i++)
            {
                if (string[i] >= 'A' && string[i] <= 'Z')
                {
                    string[i] = string[i] + 32;
                }
            }
            printf("%s", string);
            break;
    }
}

int main(int argc, char* argv[])
{
    char string[50];
    int option;

    printf("Bitte geben Sie einen String ein: ");
    scanf("%s", string);

    printf("Soll der String in Großbuchstaben (1) oder in Kleinbuchstaben (2) ausgegeben werden?\n", string);
    scanf("%d", &option);

    processString(string, option);

    return 0;
}