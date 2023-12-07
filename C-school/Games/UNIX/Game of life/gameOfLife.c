/*
File: gameOfLife.c
Date: 07.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function index

int zeilenAngabe();
int spaltenAngabe();
int zellenAngabe(int zeilen, int spalten);
void boardInitialisieren(int zeilen, int spalten, char welt[zeilen][spalten]);
void boardPrint(int zeilen, int spalten, char welt[zeilen][spalten]);
int correctInput(int zeilen, int spalten);
void fillUp(int zeilen, int spalten, char welt[zeilen][spalten], int lifeZellen);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int zeilen = zeilenAngabe();
    int spalten = spaltenAngabe();
    int lifeZellen= zellenAngabe(zeilen, spalten);

    char welt[zeilen][spalten];
    boardInitialisieren(zeilen, spalten, welt);
    fillUp(zeilen, spalten, welt, lifeZellen);
    boardPrint(zeilen, spalten, welt);
    
}

//----------------------------------------------------------------------------------------------------

int zeilenAngabe(){
    int eingabe = 0;
    int zeilen = 0;
    while (!eingabe)
    {
        printf("Gib die Anzahl der Zeilen an: ");
        scanf("%d", &zeilen);
        if (zeilen < 10 )
        {
            printf("Die kleinste Größe der Spalten ist 10\n");
        }
        else
        {
            return zeilen;
        }
        
    }

}

int spaltenAngabe(){
    int eingabe = 0;
    int spalten = 0;
    while (!eingabe)
    {
        printf("Gib die Anzahl der Spalten an: ");
        scanf("%d", &spalten);
        if (spalten < 10 )
        {
            printf("Die kleinste Größe der Spalten ist 10\n");
        }
        else
        {
            return spalten;
        }
        
    }
}

int zellenAngabe(int zeilen, int spalten){
    int eingabe = 0;
    int zellen = 0;
    while (!eingabe)
    {
        printf("Gib die Anzahl der lebendigen Zellen an: ");
        scanf("%d", &zellen);
        if (zellen > (zeilen*spalten))
        {
            printf("Die maximale Anzahl an Zellen ist %d\n", zeilen*spalten);
        }
        else
        {
            return zellen;
        }
        
    }
}

void fillUp(int zeilen, int spalten, char welt[zeilen][spalten], int lifeZellen){
    for (int i = 0; i < lifeZellen; i++)
    {
        welt[rand()%zeilen][rand()%spalten] = '*';
    }
}

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

