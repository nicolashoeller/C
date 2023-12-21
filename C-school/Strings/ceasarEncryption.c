/*
File: ceasarEncryption.c
Date: 21.12.2023
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                      'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                      'u', 'v', 'w', 'x', 'y', 'z'};

    char stringEingabe[100];

    printf("Bitte geben Sie einen String ein: ");
    fgets(stringEingabe, 100, stdin);
}