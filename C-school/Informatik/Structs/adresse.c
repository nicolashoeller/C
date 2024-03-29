/*
File: adresse.c
Date: 26.02.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eingabe(struct adresse *nicolas);
void printStruct(struct adresse *nicolas);

struct adresse
{
    char stadt[100];
    char postleitzahl[10];
    char strasse[100];
    char hausnummer[100];
};

int main(int argc, char *argv[])
{
    struct adresse nicolas;
    eingabe(&nicolas);
    printStruct(&nicolas);
    
    return 0;
}

void eingabe(struct adresse *nicolas)
{
    printf("Gib deine stadt an: ");
    scanf("%s", nicolas->stadt);

    printf("Gib deine Postleitzahl an: ");
    scanf("%s", nicolas->postleitzahl);

    printf("Gib deine Straße an: ");
    scanf("%s", nicolas->strasse);

    printf("Gib deine Hausnummer an: ");
    scanf("%s", nicolas->hausnummer);
}

void printStruct(struct adresse *nicolas)
{
    printf("\n");
    printf("Stadt: %s\n", nicolas->stadt);
    printf("Postleitzahl: %s\n", nicolas->postleitzahl);
    printf("Strasse: %s\n", nicolas->strasse);
    printf("Hausnummer: %s\n", nicolas->hausnummer);
}