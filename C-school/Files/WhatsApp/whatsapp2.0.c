/*
File: whatsappChat.c
Date: 11.01.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define CHATMAX 256

void splitLines(char *, FILE *);

int main(int argc, char *argv[])
{
    char chatLine[CHATMAX];

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Beim öffnen der Datei ist ein Problem aufgetreten!");
        return -1;
    }

    splitLines(chatLine, file);
    fclose(file);
    return 0;
}

void splitLines(char *chatLine, FILE *file)
{
    int i = 0;
    while (fgets(chatLine, CHATMAX, file) != NULL) // Use the buffer size here
    {
        i++;
    }
    printf("%d", i);
}