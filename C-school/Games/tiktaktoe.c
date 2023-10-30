/*
Autor: Nicolas Höller
File: 2-dimarray.c
Date: 26.10.2023
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int array[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    int xyAchseP1[2] = {0, 0};
    int xyAchseP2[2] = {0, 0};
    int eingabe = 0;
    int nextPlayer = 0;
    int win = 0;

    printf("\nWelcher Spieler soll beginnen? (1 oder 2)\n");
    printf("----> ");
    scanf("%d", &eingabe);

    while (win == 0)
    {

        if (eingabe == 1)
        {
            printf("\n\n\nSpieler 1, an welcher Stelle willst du O platzieren?\n\n");
            printf("     1  2  3    X-Achse\n");
            printf("-------------\n");

            for (int i = 0; i < 3; i++)
            {
                printf("%d |  ", i + 1);

                for (int j = 0; j < 3; j++)
                {
                    printf("%d  ", array[i][j]);
                }

                printf("\n");
            }

            printf("-------------\n");
            printf("Y-Achse\n");

            while (nextPlayer == 0)
            {
                printf("Gib die Y Koordinate ein\n");
                printf("----> ");
                scanf("%d", &xyAchseP1[0] - 1);
                printf("Gib die X Koordinate ein\n");
                printf("----> ");
                scanf("%d", &xyAchseP1[1] - 1);

                if (array[xyAchseP1[0]][xyAchseP1[1]] = 1)
                {
                    nextPlayer = 1;
                }
                else
                {
                    printf("Diese Feld ist schon benutzt!!!\n\n");
                }
            }
        }
        else if (eingabe == 2)
        {
            printf("\n\n\nSpieler 2, an welcher Stelle willst du X platzieren?\n\n");
            printf("     1  2  3    X-Achse\n");
            printf("-------------\n");

            for (int i = 0; i < 3; i++)
            {
                printf("%d |  ", i + 1);

                for (int j = 0; j < 3; j++)
                {
                    printf("%d  ", array[i][j]);
                }

                printf("\n");
            }

            printf("-------------\n");
            printf("Y-Achse\n");

            while (nextPlayer == 0)
            {
                printf("Gib die Y Koordinate ein\n");
                printf("----> ");
                scanf("%d", &xyAchseP2[0]);
                printf("Gib die X Koordinate ein\n");
                printf("----> ");
                scanf("%d", &xyAchseP2[1]);

                if (array[xyAchseP2[0]][xyAchseP2[1]] != 0)
                {
                    printf("Diese Feld ist schon benutzt!!!\n\n");
                }
                else
                {
                    array[xyAchseP2[0]][xyAchseP2[1]] = -1;
                    nextPlayer = 1;
                }
            }
        }
        else
        {
            printf("-----------------\n");
            printf("Gebe Spieler 1 oder 2 ein\n");
            printf("-----------------\n");
        }
    }

    return 0;
}