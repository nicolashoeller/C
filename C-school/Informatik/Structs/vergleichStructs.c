/*
File: vergleichStructs.c
Date: 28.02.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char stadt[100];
    char postleitzahl[10];
    char strasse[100];
    char hausnummer[10];
} Adresse;

void eingabe(Adresse *adresse) {
    printf("Gib deine Stadt an: ");
    scanf("%s", adresse->stadt);

    printf("Gib deine Postleitzahl an: ");
    scanf("%s", adresse->postleitzahl);

    printf("Gib deine Straße an: ");
    scanf("%s", adresse->strasse);

    printf("Gib deine Hausnummer an: ");
    scanf("%s", adresse->hausnummer);
}

void printAdresse(Adresse *adresse) {
    printf("Stadt: %s\n", adresse->stadt);
    printf("Postleitzahl: %s\n", adresse->postleitzahl);
    printf("Strasse: %s\n", adresse->strasse);
    printf("Hausnummer: %s\n", adresse->hausnummer);
}

int compareAdressen(Adresse *adresse1, Adresse *adresse2) {
    if (strcmp(adresse1->stadt, adresse2->stadt) != 0) return 0;
    if (strcmp(adresse1->postleitzahl, adresse2->postleitzahl) != 0) return 0;
    if (strcmp(adresse1->strasse, adresse2->strasse) != 0) return 0;
    if (strcmp(adresse1->hausnummer, adresse2->hausnummer) != 0) return 0;
    return 1; // Adressen sind gleich
}

int main() {
    Adresse philipp, nicolas;

    printf("Eingabe für Philipp:\n");
    eingabe(&philipp);

    printf("Eingabe für Nicolas:\n");
    eingabe(&nicolas);

    printf("\nAdresse von Philipp:\n");
    printAdresse(&philipp);

    printf("\nAdresse von Nicolas:\n");
    printAdresse(&nicolas);

    if (compareAdressen(&philipp, &nicolas)) {
        printf("\nDie Adressen sind gleich.\n");
    } else {
        printf("\nDie Adressen sind nicht gleich.\n");
    }

    return 0;
}