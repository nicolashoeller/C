/*
Autor: Nicolas Höller
File: tiktaktoeComp.c
Date: 26.10.2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char array[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

// Index der Funktionen

void board();
int winCheckP1();
int winCheckP2();
int drawCheck();

int main()
{
    srand(time(NULL));
    int spielerAuswahl = 0;
    int frei = 0;
    int xP1 = 0;
    int xC2 = 0;
    int yP1 = 0;
    int yC2 = 0;
    int win = 0;
    int winReturn = 0;

    system("clear");
    printf("\nWilkommen zu TikTakToe!\n");
    printf("------------------------\n");
    printf("Soll der Spieler (1) oder der Computer (2) beginnen\n");
    printf("----> ");
    scanf("%d", &spielerAuswahl);

    if (spielerAuswahl == 1)
    {
        while (win == 0)
        {
            while (frei == 0)
            {
                system("clear");
                printf("\n--------------");
                board();
                printf("\nSpieler 1,\nin welchen Feld willst du deine X schreiben?\n");
                printf("X-Koordinate: ");
                scanf("%d", &xP1);
                printf("Y-Koordinate: ");
                scanf("%d", &yP1);
                system("clear");

                if (array[yP1 - 1][xP1 - 1] != ' ')
                {
                    printf("\nACHTUNG!\n");
                    printf("!!!Dieses Feld ist bereits benutzt!!!");
                }
                else
                {
                    array[yP1 - 1][xP1 - 1] = 'X';
                    frei = 1;
                }
            }
            if (winCheckP1() == 1)
            {
                system("clear");
                board();
                printf("-------------------------");
                printf("\n!!!Spieler 1 hat gewonnen!!!\n");
                printf("-------------------------\n");
                win = 1;
            }

            else if (drawCheck() == 1)
            {
                system("clear");
                board();
                printf("-------------------------");
                printf("\n!!!UNENTSCHIEDEN!!!\n");
                printf("-------------------------\n");
                win = 1;
            }
            else
            {
                frei = 0;
            }
            // Computer 2
            if (win == 0)
            {
                while (frei == 0)
                {
                    system("clear");
                    printf("\n--------------");
                    board();
                    xC2 = rand() % 2 + 1;
                    yC2 = rand() % 2 + 1;

                    if (array[yC2][xC2] != ' ')
                    {
                        printf("\nACHTUNG!\n");
                        printf("!!!Dieses Feld ist bereits benutzt!!!");
                    }
                    else
                    {
                        array[yC2][xC2] = 'O';
                        frei = 1;
                    }
                }
                if (winCheckP2() == 1)
                {
                    system("clear");
                    board();
                    printf("-------------------------");
                    printf("\n!!!Spieler 2 hat gewonnen!!!\n");
                    printf("-------------------------\n");
                    win = 1;
                }
                else if (drawCheck() == 1)
                {
                    system("clear");
                    board();
                    printf("-------------------------");
                    printf("\n!!!UNENTSCHIEDEN!!!\n");
                    printf("-------------------------\n");
                    win = 1;
                }
                else
                {
                    frei = 0;
                }
            }
        }
    }
    else if (spielerAuswahl == 2)
    {
        while (win == 0)
        {
            while (frei == 0)
            {
                system("clear");
                printf("\n--------------");
                board();
                printf("\nSpieler 2,\nin welchen Feld willst du deine O schreiben?\n");
                printf("X-Koordinate: ");
                scanf("%d", &xC2);
                printf("Y-Koordinate: ");
                scanf("%d", &yC2);

                if (array[yC2 - 1][xC2 - 1] != ' ')
                {
                    printf("\nACHTUNG!\n");
                    printf("!!!Dieses Feld ist bereits benutzt!!!");
                }
                else
                {
                    array[yC2 - 1][xC2 - 1] = 'O';
                    frei = 1;
                }
            }
            if (winCheckP2() == 1)
            {
                system("clear");
                board();
                printf("-------------------------");
                printf("\n!!!Spieler 2 hat gewonnen!!!\n");
                printf("-------------------------\n");
                win = 1;
            }

            else if (drawCheck() == 1)
            {
                system("clear");
                board();
                printf("-------------------------");
                printf("\n!!!UNENTSCHIEDEN!!!\n");
                printf("-------------------------\n");
                win = 1;
            }
            else
            {
                frei = 0;
            }
            // Spieler 2
            if (win == 0)
            {
                while (frei == 0)
                {
                    system("clear");
                    printf("\n--------------");
                    board();
                    printf("\nSpieler 1,\nin welchen Feld willst du deine X schreiben?\n");
                    printf("X-Koordinate: ");
                    scanf("%d", &xP1);
                    printf("Y-Koordinate: ");
                    scanf("%d", &yP1);

                    if (array[yP1 - 1][xP1 - 1] != ' ')
                    {
                        printf("\nACHTUNG!\n");
                        printf("!!!Dieses Feld ist bereits benutzt!!!");
                    }
                    else
                    {
                        array[yP1 - 1][xP1 - 1] = 'X';
                        frei = 1;
                    }
                }
                if (winCheckP1() == 1)
                {
                    system("clear");
                    board();
                    printf("-------------------------");
                    printf("\n!!!Spieler 1 hat gewonnen!!!\n");
                    printf("-------------------------\n");
                    win = 1;
                }
                else if (drawCheck() == 1)
                {
                    system("clear");
                    board();
                    printf("-------------------------");
                    printf("\n!!!UNENTSCHIEDEN!!!\n");
                    printf("-------------------------\n");
                    win = 1;
                }
                else
                {
                    frei = 0;
                }
            }
        }
    }

    else
    {
        printf("Gib Spieler 1 oder 2 an");
    }

    return 0;
}

void board()
{
    printf("\n");
    printf("     1  2  3    X-Achse\n");
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d |  ", i + 1);

        for (int j = 0; j < 3; j++)
        {
            printf("%c  ", array[i][j]);
        }

        printf("\n");
    }
}

int winCheckP1()
{
    for (int i = 0; i < 3; i++)
    {
        if (array[i][0] == 'X' && array[i][1] == 'X' && array[i][2] == 'X')
        {
            return 1; // Horizontale Zeile gefunden
        }

        if (array[0][i] == 'X' && array[1][i] == 'X' && array[2][i] == 'X')
        {
            return 1; // Vertikale Spalte gefunden
        }
    }

    if (array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X')
    {
        return 1; // Diagonale von links oben nach rechts unten gefunden
    }
    if (array[2][0] == 'X' && array[1][1] == 'X' && array[0][2] == 'X')
    {
        return 1; // Diagonale von links unten nach rechts oben gefunden
    }

    return 0; // Kein Gewinner gefunden
}

int winCheckP2()
{
    for (int i = 0; i < 3; i++)
    {
        if (array[i][0] == 'O' && array[i][1] == 'O' && array[i][2] == 'O')
        {
            return 1; // Horizontale Zeile gefunden
        }

        if (array[0][i] == 'O' && array[1][i] == 'O' && array[2][i] == 'O')
        {
            return 1; // Vertikale Spalte gefunden
        }
    }

    if (array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O')
    {
        return 1; // Diagonale von links oben nach rechts unten gefunden
    }

    if (array[2][0] == 'O' && array[1][1] == 'O' && array[0][2] == 'O')
    {
        return 1; // Diagonale von links unten nach rechts oben gefunden
    }

    return 0; // Kein Gewinner gefunden
}

int drawCheck()
{

    if (array[0][0] != ' ' && array[0][1] != ' ' && array[0][2] != ' ' &&
        array[1][0] != ' ' && array[1][1] != ' ' && array[1][2] != ' ' &&
        array[2][0] != ' ' && array[2][1] != ' ' && array[2][2] != ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}