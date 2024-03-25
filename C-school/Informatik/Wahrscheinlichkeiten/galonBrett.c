/*
File: galonBrett.c
Date: 06.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

void iniSpielfeld(int ebenen, int spalten, char spielfeld[ebenen][spalten]);
void printSpielfeld(int ebenen, int spalten, char spielfeld[ebenen][spalten]);

int main()
{
    int kugeln = 10;
    int ebenen = 10;
    int spalten = ebenen + 1;

    char spielfeld[ebenen][spalten];

    iniSpielfeld(ebenen, spalten, spielfeld);
    printSpielfeld(ebenen, spalten, spielfeld);
    
}

void printSpielfeld(int ebenen, int spalten, char spielfeld[ebenen][spalten]){
    for (int i = 0; i < ebenen; i++)
    {
        for (int j = 0; j < spalten; j++)
        {
            printf("%c ", spielfeld[i][j]);
        }
        printf("\n");
        
    }
}

void iniSpielfeld(int ebenen, int spalten, char spielfeld[ebenen][spalten]){
    for (int i = 0; i < ebenen; i++)
    {
        for (int j = 0; j < spalten; j++)
        {
            spielfeld[i][j] = ' ';
        }
        
    }
}