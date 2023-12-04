/*
File: labyrinth.c
Date: 30.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

//Function index

void welcome();
void spielfeldPrint(int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate]);
int playerWin(char player, int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate]);
int playerDead(char player, int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate]);

int main()
{
    srand(time(NULL));
    int xKoordinate = 11;
    int yKoordinate = 20;
    char player = 'X';

    char spielfeld[xKoordinate][yKoordinate];

    //welcome();

    //Initialisiert array

    for (int i = 0; i < xKoordinate; i++)
    {
        for (int j = 0; j < yKoordinate; j++)
        {
            spielfeld[i][j] = '*';
        }
    }

    spielfeld[xKoordinate - 1][yKoordinate / 2] = 'X';

    spielfeldPrint(xKoordinate, yKoordinate, spielfeld);

    for (int i = 0; i < xKoordinate; i++)
    {
        if (playerWin(player, xKoordinate, yKoordinate, spielfeld))
        {
            printf("Er hat es geschafft");
            return 0;
        }
        if (playerDead(player, xKoordinate, yKoordinate, spielfeld))
        {
            printf("Er ist nun im Krankenhaus");
            return 0;
        }
        
    }

    return 0;
}

int playerWin(char player, int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate])
{
    for (int i = 0; i < yKoordinate; i++)
    {
        if (spielfeld[0][i] == player)
        {
            return 1;
        }
    }
    return 0;
}

int playerDead(char player, int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate])
{
    for (int i = 0; i < xKoordinate; i++)
    {
        for (int j = 0; j < yKoordinate; j++)
        {
            if (spielfeld[i][j] == player)
            {
                return 0;
            }
            
        }
        
    }
    
    return 1;
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