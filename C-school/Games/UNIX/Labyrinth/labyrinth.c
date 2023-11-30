/*
File: labyrinth.c
Date: 30.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void welcome();
void spielfeldPrint();

int main()
{
    int xKoordinate = 11;
    int yKoordinate = 20;

    char spielfeld[xKoordinate][yKoordinate];

    welcome();
    
    for (int i = 0; i < xKoordinate; i++)
    {
        for (int j = 0; j < yKoordinate; j++)
        {
            spielfeld[i][j] = '#';
        }
    }

    spielfeldPrint(xKoordinate, yKoordinate, spielfeld);
}

void spielfeldPrint(int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate])
{
    system("clear");
    printf("Pass au, der hot GLÜÜHWEIN GSOFFEN!!\n---------------------------\n");

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

void welcome()
{
    system("clear");
    printf("\n\n");
    printf("██      ███████ ████████ ███████ \n");
    printf("██      ██         ██    ██      \n");
    printf("██      █████      ██    ███████ \n");
    printf("██      ██         ██         ██ \n");
    printf("███████ ███████    ██    ███████ \n");
    sleep(1);
    system("clear");
    printf("\n\n");
    printf("███████  █████  ██    ██ ███████ \n");
    printf("██      ██   ██ ██    ██ ██      \n");
    printf("███████ ███████ ██    ██ █████   \n");
    printf("     ██ ██   ██ ██    ██ ██      \n");
    printf("███████ ██   ██  ██████  ██      \n");
    sleep(1);
    system("clear");
    printf("                 ██    ██\n");
    printf("\n");
    printf(" ██████  ██      ██    ██ ██   ██ ██     ██ ███████ ██ ███    ██ \n");
    printf("██       ██      ██    ██ ██   ██ ██     ██ ██      ██ ████   ██ \n");
    printf("██   ███ ██      ██    ██ ███████ ██  █  ██ █████   ██ ██ ██  ██ \n");
    printf("██    ██ ██      ██    ██ ██   ██ ██ ███ ██ ██      ██ ██  ██ ██\n");
    printf(" ██████  ███████  ██████  ██   ██  ███ ███  ███████ ██ ██   ████ \n");
    sleep(1);
}