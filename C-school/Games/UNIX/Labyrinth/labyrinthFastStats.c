/*
File: labyrinth.c
Date: 30.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function index

int playerWin(char player, int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate]);

int main()
{
    srand(time(NULL));
    int xKoordinate = 11;
    int yKoordinate = 20;
    int height = xKoordinate;
    int whidth = yKoordinate;
    int zufZahl = 0;
    char player = 'X';
    int versuche = 0;
    int gewonnen = 0;

    char spielfeld[xKoordinate][yKoordinate];

    // Initialisiert array

    for (int i = 0; i < xKoordinate; i++)
    {
        for (int j = 0; j < yKoordinate; j++)
        {
            spielfeld[i][j] = '*';
        }
    }

    xKoordinate--;
    yKoordinate /= 2;

    spielfeld[xKoordinate][yKoordinate] = 'X';

    while (versuche < 10000001)
    {
        spielfeld[xKoordinate][yKoordinate] = '*';
        zufZahl = rand() % 8;
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
            if (playerWin(player, height, whidth, spielfeld))
            {
                spielfeld[xKoordinate - 1][yKoordinate] = player;
                gewonnen++;
            }
        }
        else if (xKoordinate < 0 || xKoordinate >= 11 || yKoordinate < 0 || yKoordinate >= 20)
        {
            xKoordinate = height - 1;
            yKoordinate = whidth / 2;
            spielfeld[xKoordinate][yKoordinate] = 'X';
            versuche++;
        }
    }
    printf("\nEs Verhältnis, dass der bsoffene durchkimmt liegt pa ca. ba %d/100", gewonnen/100000);

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