/*
File: betrag.c
Date: 27.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

int betrag(int);

int main()
{
    int eingabe = 0;
    printf("Gib deine Zahl ein: ");
    scanf("%d", &eingabe);
    printf("%d", betrag(eingabe));
}

int betrag(int eingabe){
    if (eingabe >= 0)
    {
        return eingabe;
    }
    else
    {
        return -eingabe;
    }
}