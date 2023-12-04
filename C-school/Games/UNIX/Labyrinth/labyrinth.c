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
    int height = xKoordinate;
    int whidth = yKoordinate;
    int zufZahl = 0;
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

    xKoordinate--;
    yKoordinate/=2;

    spielfeld[xKoordinate][yKoordinate] = 'X';

    while (!playerWin(player, height, whidth, spielfeld) && !playerDead(player, height, whidth, spielfeld))
    {
        spielfeldPrint(height, whidth, spielfeld);
        sleep(1);
        spielfeld[xKoordinate][yKoordinate] = '*';
        zufZahl = rand()%8;
        switch (zufZahl)
        {
        case 0:
            xKoordinate--;
            break;
        case 1:
            xKoordinate++;
            break;
        case 2:
            yKoordinate--;
            break;
        case 3:
            yKoordinate++;
            break;
        case 4:
            xKoordinate++;
            yKoordinate++;
            break;
        case 5:
            xKoordinate--;
            yKoordinate++;
            break;
        case 6:
            xKoordinate++;
            yKoordinate--;
            break;
        case 7:
            xKoordinate--;
            yKoordinate--;
            break;
        default:
            break;
        }
        if (xKoordinate >= 0 && xKoordinate < 11 && yKoordinate >= 0 && yKoordinate < 20)
        {
            spielfeld[xKoordinate][yKoordinate] = player;
        }
    }
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

//-----------------------------------------------------------------------------------------------------

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