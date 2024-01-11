/*
File: stringInStringQuantity.c
Date: 11.01.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eingabe(char*, char*);
void vergleichStrings(char*, char*);
int position(char*, char*);
void removeNewline(char*, char*);

int main(int argc, char* argv[])
{
    char string1[100];
    char string2[100];

    
    eingabe(string1, string2);
    removeNewline(string1, string2);
    vergleichStrings(string1, string2);
    int pos = position(string1, string2);
    printf("Der zweite String beginnt an der Position %d im ersten String\n", pos+1);

    return 0;
}

void eingabe(char* string1, char* string2)
{
    printf("Gib den ersten String ein: ");
    fgets(string1, 100, stdin);
    printf("Gib den zweiten String ein: ");
    fgets(string2, 100, stdin);
}

void vergleichStrings(char* string1, char* string2)
{
    printf("-----------------------------\n");

    if (strstr(string1, string2) != NULL)
    {
        printf("String 2 ist in String 1 enthalten\n");
    }
    else
    {
        printf("String 2 ist nicht in String 1 enthalten\n");
        return;
    }
}

int position(char* string1, char* string2)
{
    char *posPtr = strstr(string1, string2);
    if (posPtr != NULL)
    {
        int pos = posPtr - string1;
        return pos;
    }
    else
    {
        return -1;
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