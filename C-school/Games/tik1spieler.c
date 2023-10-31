/*
Autor: Nicolas Höller
File: tik1spielr.c
Date: 26.10.2023
*/

#include <stdio.h>
#include <stdlib.h>

int array[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

int main()
{
    int spielerAuswahl = 0;
    int frei = 0;
    int xP1 = 0;
    int yP1 = 0;
    int win = 0;
    int winReturn = 0;

    printf("Wilkommen zu TikTakToe!\n");
    printf("------------------------\n");
    printf("Welcher Spiler soll beginnen?\n");
    printf("----> ");
    scanf("%d", &spielerAuswahl);

    if (spielerAuswahl == 1)
    {
        while (win == 0)
        {
            while (frei == 0)
            {
                printf("\n--------------\n");
                board();
                printf("In welchen Feld willst du deine 1 schreiben?\n");
                printf("X-Koordinate: ");
                scanf("%d", &xP1);
                printf("Y-Koordinate: ");
                scanf("%d", &yP1);

                if (array[yP1 - 1][xP1 - 1] != 0)
                {
                    printf("\nACHTUNG!\n");
                    printf("!!!Dieses Feld ist bereits benutzt!!!");
                }
                else
                {
                    array[yP1 - 1][xP1 - 1] = 1;
                    frei = 1;
                }
            }
            winReturn = winCheck();

            if (winReturn == 1)
            {
                printf("-------------------------");
                printf("\n!!!Spieler 1 hat gewonnen!!!\n");
                printf("-------------------------\n");
                board();
                win = 1;
            }
            else{
                frei = 0;
            }
        }
    }
    else if (spielerAuswahl == 2)
    {
        printf("d");
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
            printf("%d  ", array[i][j]);
        }

        printf("\n");
    }
}

int winCheck(){
    if (array[0][0] == 1 && array[0][1] == 1 && array[0][2] == 1 || //Kontrolliert horizontale Felder
        array[1][0] == 1 && array[1][1] == 1 && array[1][2] == 1 ||
        array[2][0] == 1 && array[2][1] == 1 && array[2][2] == 1 ||

        array[0][0] == 1 && array[1][0] == 1 && array[2][0] == 1 || //Kontrolliert vertikale Felder
        array[0][1] == 1 && array[1][1] == 1 && array[2][1] == 1 ||
        array[0][2] == 1 && array[1][2] == 1 && array[2][2] == 1 ||

        array[0][0] == 1 && array[1][1] == 1 && array[2][2] == 1 || //Kontrolliert Kreuz
        array[2][0] == 1 && array[1][1] == 1 && array[0][2] == 1
    )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
    
}