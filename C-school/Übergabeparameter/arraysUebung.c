/*
File: arraysUebung.c
Date: 13.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int berechnung(int groesse, int array[groesse]);
void initialisieren(int groesse, int array[groesse]);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int groesse = 100;
    int kleinsteZahl = 0;

    int array[groesse];

    initialisieren(groesse, array);
    kleinsteZahl = berechnung(groesse, array);
    printf("%d", kleinsteZahl);

    return 0;
}

void initialisieren(int groesse, int array[groesse]){
    for (int i = 0; i < groesse; i++)
    {
        array[i] = rand() % 10+1;
    }
}

int berechnung(int groesse, int array[groesse]){
    int kleinsteZahl = array[0];

    for (int i = 1; i < groesse; i++)
    {
        if (array[i] < kleinsteZahl)
        {
            kleinsteZahl = array[i];
        }
    }

    return kleinsteZahl;
    
}