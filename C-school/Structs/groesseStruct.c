/*
File: groesseStruct.c
Date: 28.02.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

struct adresse
{
    char strasse[51];
    int nummer;
    long plz;
    char ort[53];
};

struct adresse2
{
    char strasse[51];
    char ort[53];
    int nummer;
    long plz;
};

int main(int argc, char *argv[])
{
    printf("Größe von struct adresse: %d\n", sizeof(struct adresse));
    printf("Größe von struct adresse2: %d\n", sizeof(struct adresse2));
}