/*
File: stringInString.c
Date: 08.01.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void eingabe(char*, char*);
void vergleich(char*, char*);
void removeNewline(char*, char*);

int main(int argc, char* argv[])
{
    char string1[MAX];
    char string2[MAX];

    eingabe(string1, string2);
    removeNewline(string1, string2);
    vergleich(string1, string2);
    
    return 0;
}

void eingabe(char* string1, char* string2)
{
    printf("Gib den ersten String ein: ");
    fgets(string1, MAX, stdin);
    printf("Gib den zweiten String ein: ");
    fgets(string2, MAX, stdin);
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
    if (strlen(string1) > 0 && string1[strlen(string1) - 1] == '\n') {
        string1[strlen(string1) - 1] = '\0';
    }
    
    if (strlen(string2) > 0 && string2[strlen(string2) - 1] == '\n') {
        string2[strlen(string2) - 1] = '\0';
    }
}