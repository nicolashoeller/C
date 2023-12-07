/*
File: gameOfLife.c
Date: 07.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function index

void boardInitialisieren(int zeilen, int spalten, char welt[zeilen][spalten]);
void boardPrint(int zeilen, int spalten, char welt[zeilen][spalten]);
int correctInput(int zeilen, int spalten);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int zeilen = 0;
    int spalten = 0;

    printf("Gib die Zeilen der Welt ein: ");
    scanf("%d", &zeilen);
    printf("Gib die Spalten der Welt ein: ");
    scanf("%d", &spalten);

    char welt[zeilen][spalten];
    if (correctInput(zeilen, spalten))
    {
        boardInitialisieren(zeilen, spalten, welt);
        boardPrint(zeilen, spalten, welt);
    }
    else
    {
        printf("Deine Eingabe ist nicht korrekt!\n");
    }
    
}

//----------------------------------------------------------------------------------------------------

int correctInput(int zeilen, int spalten){
    if (zeilen >= 10 && spalten >= 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void boardInitialisieren(int zeilen, int spalten, char welt[zeilen][spalten]){
    for (int i = 0; i < zeilen; i++)
    {
        for (int j = 0; j < spalten; j++)
        {
            welt[i][j] = '-';
        }
        
    }
    
}

void boardPrint(int zeilen, int spalten, char welt[zeilen][spalten]){
    for (int i = 0; i < zeilen; i++)
    {
        for (int j = 0; j < spalten; j++)
        {
            printf("%c", welt[i][j]);
        }
        printf("\n");
    }
    
}

