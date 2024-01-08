/*
File: stringInString.c
Date: 08.01.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eingabe(char*, char*);
void vergleich(char*, char*);
void removeNewline(char*, char*);

int main(int argc, char* argv[])
{
    char string1[100];
    char string2[100];

    eingabe(string1, string2);
    removeNewline(string1, string2);
    vergleich(string1, string2);
    
    return 0;
}

void eingabe(char* string1, char* string2)
{
    printf("Gib den ersten String ein: ");
    fgets(string1, 100, stdin);
    printf("Gib den zweiten String ein: ");
    fgets(string2, 100, stdin);
}

void vergleich(char* string1, char* string2)
{
    printf("-----------------------------\n");

    if (strstr(string1, string2) != NULL)
    {
        printf("String 2 ist in String 1 enthalten\n");
    }
    else
    {
        printf("String 2 ist nicht in String 1 enthalten\n");
    }
}

void removeNewline(char* string1, char* string2)
{
    int len = strlen(string1);
    if (len > 0 && string1[len-1] == '\n') {
        string1[len-1] = '\0';
    }
    
    len = strlen(string2);
    if (len > 0 && string2[len-1] == '\n') {
        string2[len-1] = '\0';
    }
}