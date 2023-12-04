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

void welcome();
void spielfeldPrint(int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate], int count);
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
    int count = 0;
    int win = 0;

    char spielfeld[xKoordinate][yKoordinate];

    welcome();

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

    while (!win)
    {
        spielfeldPrint(height, whidth, spielfeld, count);
        sleep(1);
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
        }
        else if (xKoordinate < 0 || xKoordinate >= 11 || yKoordinate < 0 || yKoordinate >= 20)
        {
            printf("\nJetz hoebn sie ihn gfassen, soll er lei no amol probieren!\n");
            xKoordinate = height - 1;
            yKoordinate = whidth / 2;
            spielfeld[xKoordinate][yKoordinate] = 'X';
            count++;
            sleep(4);
        }
        else if (!playerWin(player, xKoordinate, yKoordinate, spielfeld))
        {
            printf("\nLoter er hots gschofft!!\n");
            win = 1;
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

void spielfeldPrint(int xKoordinate, int yKoordinate, char spielfeld[xKoordinate][yKoordinate], int count)
{
    system("clear");
    printf("\nPass au, der hot GLÜÜHWEIN GSOFFEN!!\n---------------------------\n");

    for (int i = 0; i < xKoordinate; i++)
    {
        printf("||");
        for (int j = 0; j < yKoordinate; j++)
        {
            printf("%c", spielfeld[i][j]);
        }
        printf("||\n");
    }

    printf("\nVeruche: %d", count);
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