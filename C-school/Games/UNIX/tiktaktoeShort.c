/*
File: tiktaktoeShort.c
Date: 13.11.2023
Autor: Nicolas Höller
*/
#include <stdio.h>

void board();

char array[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

int main()
{
    int win = 0;
    char player = ' ';
    int eingabe = 0;
    int yP = 0;
    int xP = 0;
    int replaygame = 0;

    printf("Welcher Spieler soll beginnen? 1 | 2\n");
    scanf("%d", &eingabe);

    if (eingabe == 1)
    {
        player = 'X';
    }
    else if (eingabe == 2)
    {
        player = 'O';
    }
    else
    {
        printf("Gib Spieler 1 oder 2 an");
    }

    while (!win)
    {
        while (!replaygame)
        {
            board();
            printf("Spieler %c gib dein Feld ein!\n", player);
            printf("X-Koordinate: ");
            scanf("%d", &yP);
            printf("Y-Koordinate: ");
            scanf("%d", &xP);

            array[xP - 1][yP - 1] = player;
            board();
            
        }
    }
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