/*
File: statistiktempn.c
Date: 15.01.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

void printArray(int[]);
void ueberpruefung(int[], FILE *);

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    int array[26] = {0};

    if (file == NULL)
    {
        printf("Beim öffnen der Datei ist ein Fehler aufgetreten");
        return -1;
    }

    ueberpruefung(array, file);
    printArray(array);

    fclose(file);
}

void ueberpruefung(int array[], FILE *file){
    int temp = 0;
    int index = 0;
    while ((temp = fgetc(file)) != EOF)
    {
        if (temp >= 'A' && temp <= 'Z')
        {
            index = temp - 'A';
            array[index]++;
        }
        else if (temp >= 'a' && temp <= 'z')
        {
            index = temp - 'a';
            array[index]++;
        }
    }
}

void printArray(int array[])
{
    for (int i = 0; i < 26; i++)
    {
        printf("%c: %d\n", i + 97, array[i]);
    }
}