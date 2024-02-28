/*
File: uhrzeit.c
Date: 28.02.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int stunden;
    int minuten;
    int sekunden;
} uhrzeit;

typedef struct
{
    int stunden;
    int minuten;
    int sekunden;
} differenz;

void eingabe(uhrzeit *zeit1);
int vergleiche(uhrzeit *zeit1, uhrzeit *zeit2);
differenz berechneDifferenz(uhrzeit *zeit1, uhrzeit *zeit2);

int main(int argc, char *argv[])
{
    uhrzeit zeit1, zeit2;
    printf("Eingabe für Zeit 1:\n");
    eingabe(&zeit1);
    printf("Eingabe für Zeit 2:\n");
    eingabe(&zeit2);

    int result = vergleiche(&zeit1, &zeit2);

    if (result == 1)
    {
        printf("Zeit 1 ist größer als Zeit 2\n");
    }
    else if (result == -1)
    {
        printf("Zeit 2 ist größer als Zeit 1\n");
    }
    else
    {
        printf("Zeit 1 und Zeit 2 sind gleich\n");
    }

    differenz diff = berechneDifferenz(&zeit1, &zeit2);
    printf("Differenz: %d Stunden, %d Minuten, %d Sekunden\n", diff.stunden, diff.minuten, diff.sekunden);

    return 0;
}

void eingabe(uhrzeit *zeit)
{
    printf("Gib die Stunden an: ");
    scanf("%d", &zeit->stunden);

    printf("Gib die Minuten an: ");
    scanf("%d", &zeit->minuten);

    printf("Gib die Sekunden an: ");
    scanf("%d", &zeit->sekunden);
}

int vergleiche(uhrzeit *zeit1, uhrzeit *zeit2)
{
    if (zeit1->stunden > zeit2->stunden)
        {return 1;}
    if (zeit1->stunden < zeit2->stunden)
        {return -1;}
    if (zeit1->minuten > zeit2->minuten)
        {return 1;}
    if (zeit1->minuten < zeit2->minuten)
        {return -1;}
    if (zeit1->sekunden > zeit2->sekunden)
        {return 1;}
    if (zeit1->sekunden < zeit2->sekunden)
        {return -1;}
    return 0;
}

differenz berechneDifferenz(uhrzeit *zeit1, uhrzeit *zeit2)
{
    differenz diff;
    diff.stunden = abs(zeit1->stunden - zeit2->stunden);
    diff.minuten = abs(zeit1->minuten - zeit2->minuten);
    diff.sekunden = abs(zeit1->sekunden - zeit2->sekunden);
    return diff;
}