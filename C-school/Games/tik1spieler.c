/*
Autor: Nicolas Höller
File: tik1spielr.c
Date: 26.10.2023
*/

#include <stdio.h>
#include <stdlib.h>

char array[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

int main()
{
    int spielerAuswahl = 0;
    int frei = 0;
    int xP1 = 0;
    int yP1 = 0;
    int xP2 = 0;
    int yP2 = 0;
    int win = 0;
    int winReturn = 0;

    printf("Wilkommen zu TikTakToe!\n");
    printf("------------------------\n");
    printf("Welcher Spieler soll beginnen?\n");
    printf("----> ");
    scanf("%d", &spielerAuswahl);

    if (spielerAuswahl == 1)
    {
        while (win == 0)
        {
            while (frei == 0)
            {
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
                board();
                printf("-------------------------");
                printf("\n!!!Spieler 1 hat gewonnen!!!\n");
                printf("-------------------------\n");
                win = 1;
            }
            else if (drawCheck() == 1)
            {
                board();
                printf("-------------------------");
                printf("\n!!!UNENTSCHIEDEN!!!\n");
                printf("-------------------------\n");
                win = 1;
            }
                        
            else{
                frei = 0;
            }
            //Spieler 2
            while (frei == 0)
            {
                printf("\n--------------");
                board();
                printf("\nSpieler 2,\nin welchen Feld willst du deine Q schreiben?\n");
                printf("X-Koordinate: ");
                scanf("%d", &xP2);
                printf("Y-Koordinate: ");
                scanf("%d", &yP2);

                if (array[yP2 - 1][xP2 - 1] != ' ')
                {
                    printf("\nACHTUNG!\n");
                    printf("!!!Dieses Feld ist bereits benutzt!!!");
                }
                else
                {
                    array[yP2 - 1][xP2 - 1] = 'Q';
                    frei = 1;
                }
            }
            if (winCheckP2() == 1)
            {
                board();
                printf("-------------------------");
                printf("\n!!!Spieler 2 hat gewonnen!!!\n");
                printf("-------------------------\n");
                win = 1;
            }    
            else if (drawCheck() == 1)
            {
                board();
                printf("-------------------------");
                printf("\n!!!UNENTSCHIEDEN!!!\n");
                printf("-------------------------\n");
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
            printf("%c  ", array[i][j]);
        }

        printf("\n");
    }
}

int winCheckP1(){
    if (array[0][0] == 'X' && array[0][1] == 'X' && array[0][2] == 'X' || //Kontrolliert horizontale Felder
        array[1][0] == 'X' && array[1][1] == 'X' && array[1][2] == 'X' ||
        array[2][0] == 'X' && array[2][1] == 'X' && array[2][2] == 'X' ||

        array[0][0] == 'X' && array[1][0] == 'X' && array[2][0] == 'X' || //Kontrolliert vertikale Felder
        array[0][1] == 'X' && array[1][1] == 'X' && array[2][1] == 'X' ||
        array[0][2] == 'X' && array[1][2] == 'X' && array[2][2] == 'X' ||

        array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X' || //Kontrolliert Kreuz
        array[2][0] == 'X' && array[1][1] == 'X' && array[0][2] == 'X'
    )
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}

int winCheckP2(){
    if (array[0][0] == 'Q' && array[0][1] == 'Q' && array[0][2] == 'Q' || //Kontrolliert horizontale Felder
        array[1][0] == 'Q' && array[1][1] == 'Q' && array[1][2] == 'Q' ||
        array[2][0] == 'Q' && array[2][1] == 'Q' && array[2][2] == 'Q' ||

        array[0][0] == 'Q' && array[1][0] == 'Q' && array[2][0] == 'Q' || //Kontrolliert vertikale Felder
        array[0][1] == 'Q' && array[1][1] == 'Q' && array[2][1] == 'Q' ||
        array[0][2] == 'Q' && array[1][2] == 'Q' && array[2][2] == 'Q' ||

        array[0][0] == 'Q' && array[1][1] == 'Q' && array[2][2] == 'Q'|| //Kontrolliert Kreuz
        array[2][0] == 'Q' && array[1][1] == 'Q' && array[0][2] == 'Q'
    )
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}

int drawCheck(){
    if (array[0][0] != ' ' && array[0][1] != ' ' && array[0][2] != ' ' &&
        array[1][0] != ' ' && array[1][1] != ' ' && array[1][2] != ' ' &&
        array[2][0] != ' ' && array[2][1] != ' ' && array[2][2] != ' ' &&
        (winCheckP1() == 0 || winCheckP2() == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}