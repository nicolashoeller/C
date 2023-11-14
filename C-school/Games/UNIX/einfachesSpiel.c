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

    int gr1 = 0;
    int gr2 = 0;
    int x = 0;
    int y = 0;
    int forCountZ = 0;
    char spieler = 'X';
    char input = 0;
    int dead = 0;

    printf("Gebe die Größe des Spielfels ein\n");
    printf("Spalten: ");
    scanf("%d", &gr1);
    printf("Zeilen: ");
    scanf("%d", &gr2);

    char spielfeld[gr1][gr2];

    x = gr1 / 2;
    y = gr2 / 2;

    for (int i = 0; i < gr1; i++)
    {
        for (int j = 0; j < gr2; j++)
        {
            spielfeld[i][j] = '-';
        }
    }

    if (x < 2 || y < 2){
        forCountZ = 2;
    }
    else
    {
        forCountZ = 5;
    }

    for (int i = 0; i < forCountZ; i++)
    {
        spielfeld[rand()%gr1][rand()%gr2] = 'Z';
    }

    for (int i = 0; i < forCountZ*1.5; i++)
    {
        spielfeld[rand()%gr1][rand()%gr2] = 'O';
    }
    
    spielfeld[x][y] = spieler;

    for (int i = 0; i < gr1; i++)
    {
        for (int j = 0; j < gr2; j++)
        {
            printf("| %c ", spielfeld[i][j]);
        }
        printf("|\n");
    }

    while (!dead)
    {
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

        if (input == 'w')
        {
            spielfeld[x][y] = '-';
            x--;
            spielfeld[x][y] = 'X';
        }
        else if (input == 'a')
        {
            spielfeld[x][y] = '-';
            y--;
            spielfeld[x][y] = 'X';
        }
        else if (input == 's')
        {
            spielfeld[x][y] = '-';
            x++;
            spielfeld[x][y] = 'X';
        }
        else if (input == 'd')
        {
            spielfeld[x][y] = '-';
            y++;
            spielfeld[x][y] = 'X';
        }
        else
        {
            printf("Steuerung mit w, a, s, d");
        }
    }
}