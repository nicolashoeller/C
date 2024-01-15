/*
File: whatsappChat.c
Date: 11.01.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(int argc, char* argv[])
{
    char* fileName = argv[1];
    char userName[MAX];
    
    FILE* file = fopen(fileName, "r");

    if (file == NULL)
    {
        printf("Beim öffnen der Datei ist ein Problem aufgetreten!");
        return -1;
    }

    fclose(file);
    return 0;
}