/*
File: einfachesSpiel.c
Date: 13.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int gr1 = 0, gr2 = 0;
    int rdm1 = 0, rdm2 = 0;
    int x = 0, y = 0;
    int score = 0;
    int leben = 3;
    char spieler = 'X';
    char input = 0;

    printf("Gebe die Größe des Spielfels ein\n");
    printf("Spalten: ");
    scanf("%d", &gr1);
    printf("Zeilen: ");
    scanf("%d", &gr2);

    char spielfeld[gr1][gr2];

    x = gr1 / 2;
    y = gr2 / 2;

    // Feld füllen
    for (int i = 0; i < gr1; i++)
    {
        for (int j = 0; j < gr2; j++)
        {
            spielfeld[i][j] = '-';
        }
    }

    // Feld mit Z und O füllen
    for (int i = 0; i < 3; i++)
    {
        spielfeld[rand() % gr1][rand() % gr2] = 'Z';
    }
    for (int i = 0; i < 4; i++)
    {
        spielfeld[rand() % gr1][rand() % gr2] = 'O';
    }
    spielfeld[x][y] = spieler;
    while (leben > 0)
    {
        rdm1 = rand() % gr1;
        rdm2 = rand() % gr1;
        if (spielfeld[rdm1][rdm2] == '-')
        {
            spielfeld[rand() % gr1][rand() % gr2] = 'Z';
        }
        rdm1 = rand() % gr1;
        rdm2 = rand() % gr1;
        if (spielfeld[rdm1][rdm2] == '-')
        {
            spielfeld[rand() % gr1][rand() % gr2] = 'O';
        }
        fflush(stdin);
        input = getchar();
        system("clear");
        for (int i = 0; i < gr1; i++)
        {
            for (int j = 0; j < gr2; j++)
            {
                printf("| %c ", spielfeld[i][j]);
            }
            printf("|\n");
        }
        printf("\nScore: %d", score);
        printf("\nLeben: %d\n", leben);

        if (input == 'w')
        {
            spielfeld[x][y] = '-';
            x = (x - 1 + gr1) % gr1;
            if (spielfeld[x][y] == 'Z')
            {
                leben--;
            }
            if (spielfeld[x][y] == 'O')
            {
                score += 10;
            }

            spielfeld[x][y] = 'X';
        }
        else if (input == 'a')
        {
            spielfeld[x][y] = '-';
            y = (y - 1 + gr2) % gr2;
            if (spielfeld[x][y] == 'Z')
            {
                leben--;
            }
            if (spielfeld[x][y] == 'O')
            {
                score += 10;
            }

            spielfeld[x][y] = 'X';
        }
        else if (input == 's')
        {
            spielfeld[x][y] = '-';
            x = (x + 1) % gr1;
            if (spielfeld[x][y] == 'Z')
            {
                leben--;
            }
            if (spielfeld[x][y] == 'O')
            {
                score += 10;
            }

            spielfeld[x][y] = 'X';
        }
        else if (input == 'd')
        {
            spielfeld[x][y] = '-';
            y = (y + 1) % gr2;
            if (spielfeld[x][y] == 'Z')
            {

                leben--;
            }
            if (spielfeld[x][y] == 'O')
            {
                score += 10;
            }

            spielfeld[x][y] = 'X';
        }

        else if (input == 'x')
        {
            printf("\n-----------------------------\nDas Spiel wurde beendet!!");
            leben = 0;
        }

        else
        {
            printf("Steuerung mit w, a, s, d");
        }
    }
    printf("\n-----------------------------\nDu hasch verloren klein Pisser!!");
}