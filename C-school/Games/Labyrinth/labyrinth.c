/*
File: labyrinth.c
Date: 30.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

void welcome();

int main()
{
    int xKoordinate = 11;
    int yKoordinate = 20;

    char spielfeld[xKoordinate][yKoordinate];
    
    welcome();

    system("clear");

    printf("Mander saufts GLÜÜÜHWEINN!!!\n---------------------------\n");

    for (int i = 0; i < xKoordinate; i++)
    {
        for (int j = 0; j < yKoordinate; j++)
        {
            spielfeld[i][j]='#';
        }
    }

    for (int i = 0; i < xKoordinate; i++)
    {
        printf("||");
        for (int j = 0; j < yKoordinate; j++)
        {
            printf("%c", spielfeld[i][j]);
        }
        printf("||\n");
    }
    
}

void welcome(){
    printf("                 ██    ██\n");
    printf("\n");
    printf(" ██████  ██      ██    ██ ██   ██ ██     ██ ███████ ██ ███    ██ \n");
    printf("██       ██      ██    ██ ██   ██ ██     ██ ██      ██ ████   ██ \n");
    printf("██   ███ ██      ██    ██ ███████ ██  █  ██ █████   ██ ██ ██  ██ \n");
    printf("██    ██ ██      ██    ██ ██   ██ ██ ███ ██ ██      ██ ██  ██ ██\n");
    printf(" ██████  ███████  ██████  ██   ██  ███ ███  ███████ ██ ██   ████ \n");
    sleep("3");
}