/*
File: quersumme.c
Date: 11.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

int berechneQuersumme(int zahl);

int main(int argc, char* argv[])
{
    int zahl = 0;
    int quersumme = 0;

    printf("Zahl: ");
    scanf("%d", &zahl);

    quersumme = berechneQuersumme(zahl);
    printf("Quersumme: %d\n", quersumme);

    return 0;
}

int berechneQuersumme(int zahl)
{
    if (zahl < 10)
    {
        return zahl;
    }
    else
    {
        return zahl % 10 + berechneQuersumme(zahl / 10);
    }
}