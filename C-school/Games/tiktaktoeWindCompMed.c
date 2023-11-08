/*
File: taktaktoeWindCompMed.c
Date: 08.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
int minimax();

int main()
{
    srand(time(NULL));
    int spielerAuswahl = 0;
    int frei = 0;
    int yP1 = 0;
    int xC2 = 0;
    int xP1 = 0;
    int yC2 = 0;
    int win = 0;
    int winReturn = 0;
    int moveCount = 0;

    system("cls");
    printf("\nWilkommen zu Tik Tak Toe!\n");
    printf("------------------------\n");
    printf("Soll der Spieler (1) oder der Computer (2) beginnen\n");
    printf("----> ");
    scanf("%d", &spielerAuswahl);

    if (spielerAuswahl == 1)
    {
        while (!win)
        {
            while (!frei)
            {
                system("cls");
                printf("\n--------------");
                board();
                printf("\nSpieler,\nin welchen Feld willst du deine X schreiben?\n");
                printf("X-Koordinate: ");
                scanf("%d", &yP1);
                printf("Y-Koordinate: ");
                scanf("%d", &xP1);
                system("cls");

                if (array[xP1 - 1][yP1 - 1] != ' ')
                {
                    printf("\n\n");
                    printf("!!!Diese Eingabe ist nicht erlaubt!!!");
                }
                else
                {
                    array[xP1 - 1][yP1 - 1] = 'X';
                    frei = 1;
                }
            }
            if (winCheckP1())
            {
                system("cls");
                board();
                printf("-------------------------");
                printf("\n!!!Der Spieler hat gewonnen!!!\n");
                printf("-------------------------\n");
                win = 1;
            }

            else if (drawCheck())
            {
                system("cls");
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
            // Computer
            if (!win)
            {
                while (!frei)
                {
                    system("cls");
                    printf("\n--------------");
                    board();
                    sleep(1);

                    if (minimax())
                    {
                        frei = 1;
                    }
                    else
                    {
                        xC2 = rand() % 3;
                        yC2 = rand() % 3;

                        if (array[yC2][xC2] != ' ')
                        {
                            continue;
                        }
                        else
                        {
                            array[yC2][xC2] = 'O';
                            frei = 1;
                        }
                    }
                }
                if (winCheckP2())
                {
                    system("cls");
                    board();
                    printf("-------------------------");
                    printf("\n!!!Der Computer hat gewonnen!!!\n");
                    printf("-------------------------\n");
                    win = 1;
                }
                else if (drawCheck())
                {
                    system("cls");
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
        while (!win)
        {
            while (!frei)
            {
                system("cls");
                printf("\n--------------");
                board();
                sleep(1);
                
                if (minimax())
                {
                    frei = 1;
                }
                else
                {
                    xC2 = rand() % 3;
                    yC2 = rand() % 3;

                    if (array[yC2][xC2] != ' ')
                    {
                        continue;
                    }
                    else
                    {
                        array[yC2][xC2] = 'O';
                        frei = 1;
                    }
                }
            }
            if (winCheckP2())
            {
                system("cls");
                board();
                printf("-------------------------");
                printf("\n!!!Der Computer hat gewonnen!!!\n");
                printf("-------------------------\n");
                win = 1;
            }

            else if (drawCheck())
            {
                system("cls");
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
            // Spieler 1
            if (!win)
            {
                while (!frei)
                {
                    system("cls");
                    printf("\n--------------");
                    board();
                    printf("\nSpieler,\nin welchen Feld willst du deine X schreiben?\n");
                    printf("X-Koordinate: ");
                    scanf("%d", &yP1);
                    printf("Y-Koordinate: ");
                    scanf("%d", &xP1);

                    if (array[xP1 - 1][yP1 - 1] != ' ')
                    {
                        printf("\n\n");
                        printf("!!!Diese Eingabe ist nicht erlaubt!!!");
                    }
                    else
                    {
                        array[xP1 - 1][yP1 - 1] = 'X';
                        frei = 1;
                    }
                }
                if (winCheckP1())
                {
                    system("cls");
                    board();
                    printf("-------------------------");
                    printf("\n!!!Der Spieler hat gewonnen!!!\n");
                    printf("-------------------------\n");
                    win = 1;
                }
                else if (drawCheck())
                {
                    system("cls");
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
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[i][j] == ' ')
            {
                return 0;
            }
        }
    }

    return 1;
}

int minimax() // Züge vorhersagen
{
    for (int i = 0; i < 3; i++)
    {
        // Horizontale Spalten
        if (array[i][0] == ' ' && array[i][1] == 'O' && array[i][2] == 'O')
        {
            array[i][0] = 'O';
            return 1;
        }
        if (array[i][0] == 'O' && array[i][1] == ' ' && array[i][2] == 'O')
        {
            array[i][1] = 'O';
            return 1;
        }
        if (array[i][0] == 'O' && array[i][1] == 'O' && array[i][2] == ' ')
        {
            array[i][2] = 'O';
            return 1;
        }
        // Vertikale Spalten
        if (array[0][i] == ' ' && array[1][i] == 'O' && array[2][i] == 'O')
        {
            array[0][i] = 'O';
            return 1; // Vertikale Spalte gefunden
        }
        if (array[0][i] == 'O' && array[1][i] == ' ' && array[2][i] == 'O')
        {
            array[1][i] = 'O';
            return 1; // Vertikale Spalte gefunden
        }
        if (array[0][i] == 'O' && array[1][i] == 'O' && array[2][i] == ' ')
        {
            array[2][i] = 'O';
            return 1; // Vertikale Spalte gefunden
        }
    }
    // Diagonale von links oben nach rechts unten gefunden
    if (array[0][0] == ' ' && array[1][1] == 'O' && array[2][2] == 'O')
    {
        array[0][0] = 'O';
        return 1;
    }
    if (array[0][0] == 'O' && array[1][1] == ' ' && array[2][2] == 'O')
    {
        array[1][1] = 'O';
        return 1;
    }
    if (array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == ' ')
    {
        array[2][2] = 'O';
        return 1;
    }
    // Diagonale von links unten nach rechts oben gefunden
    if (array[2][0] == ' ' && array[1][1] == 'O' && array[0][2] == 'O')
    {
        array[2][0] = 'O';
        return 1;
    }
    if (array[2][0] == 'O' && array[1][1] == ' ' && array[0][2] == 'O')
    {
        array[1][1] = 'O';
        return 1; // Diagonale von links unten nach rechts oben gefunden
    }
    if (array[2][0] == 'O' && array[1][1] == 'O' && array[0][2] == ' ')
    {
        array[0][2] = 'O';
        return 1; // Diagonale von links unten nach rechts oben gefunden
    }
    //Win von Player blockieren
    for (int i = 0; i < 3; i++)
    {
        // Horizontale Spalten
        if (array[i][0] == ' ' && array[i][1] == 'X' && array[i][2] == 'X')
        {
            array[i][0] = 'O';
            return 1;
        }
        if (array[i][0] == 'X' && array[i][1] == ' ' && array[i][2] == 'X')
        {
            array[i][1] = 'O';
            return 1;
        }
        if (array[i][0] == 'X' && array[i][1] == 'X' && array[i][2] == ' ')
        {
            array[i][2] = 'O';
            return 1;
        }
        // Vertikale Spalten
        if (array[0][i] == ' ' && array[1][i] == 'X' && array[2][i] == 'X')
        {
            array[0][i] = 'O';
            return 1; // Vertikale Spalte gefunden
        }
        if (array[0][i] == 'X' && array[1][i] == ' ' && array[2][i] == 'X')
        {
            array[1][i] = 'O';
            return 1; // Vertikale Spalte gefunden
        }
        if (array[0][i] == 'X' && array[1][i] == 'X' && array[2][i] == ' ')
        {
            array[2][i] = 'O';
            return 1; // Vertikale Spalte gefunden
        }
    }
    // Diagonale von links oben nach rechts unten gefunden
    if (array[0][0] == ' ' && array[1][1] == 'X' && array[2][2] == 'X')
    {
        array[0][0] = 'O';
        return 1;
    }
    if (array[0][0] == 'X' && array[1][1] == ' ' && array[2][2] == 'X')
    {
        array[1][1] = 'O';
        return 1;
    }
    if (array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == ' ')
    {
        array[2][2] = 'O';
        return 1;
    }
    // Diagonale von links unten nach rechts oben gefunden
    if (array[2][0] == ' ' && array[1][1] == 'X' && array[0][2] == 'X')
    {
        array[2][0] = 'O';
        return 1;
    }
    if (array[2][0] == 'X' && array[1][1] == ' ' && array[0][2] == 'X')
    {
        array[1][1] = 'O';
        return 1; // Diagonale von links unten nach rechts oben gefunden
    }
    if (array[2][0] == 'X' && array[1][1] == 'X' && array[0][2] == ' ')
    {
        array[0][2] = 'O';
        return 1; // Diagonale von links unten nach rechts oben gefunden
    }

    return 0;
}