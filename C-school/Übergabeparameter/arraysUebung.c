/*
File: arraysUebung.c
Date: 13.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int berechnung();
void initialisieren(int groesse);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int groesse = 100;

    int array[grosse] = {0};

    initialisieren(groesse);

    return 0;
}

void initialisieren(int groesse){
    for (int i = 0; i < groesse; i++)
    {
        array[groesse] = rand() % 20;
    }
}

int berechnung(){
    
}