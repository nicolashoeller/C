/*
File: gameOfLife.c
Date: 07.12.2023
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

//Function index

int zeilenAngabe();
int spaltenAngabe();
int zellenAngabe(int zeilen, int spalten);
void boardInitialisieren(int zeilen, int spalten, char welt[zeilen][spalten]);
void boardPrint(int zeilen, int spalten, char welt[zeilen][spalten]);
void fillUp(int zeilen, int spalten, char welt[zeilen][spalten], int lifeZellen, char player);
int checkFields(int zeilen, int spalten, char welt[zeilen][spalten], char player);
char getch();

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int zeilen = zeilenAngabe();
    int spalten = spaltenAngabe();
    int lifeZellen = zellenAngabe(zeilen, spalten);
    char player = 'X';

    system("clear");

    char welt[zeilen][spalten];
    boardInitialisieren(zeilen, spalten, welt);
    fillUp(zeilen, spalten, welt, lifeZellen, player);
    while (1)
    {
        checkFields(zeilen, spalten, welt, player);
    }
    
    
    
}

//----------------------------------------------------------------------------------------------------

int checkFields(int zeilen, int spalten, char welt[zeilen][spalten], char player){
    int neighbors = 0;
    for (int i = 0; i < zeilen; i++)
    {
        for (int j = 0; j < spalten; j++)
        {
            if (welt[(i + 1 + zeilen)%zeilen][(j + 1 + spalten) % spalten] == player)
            {
                neighbors++;
            }
            if (welt[(i - 1 + zeilen)%zeilen][(j - 1 + spalten) % spalten] == player)
            {
                neighbors++;
            }
        }
        
    }
    printf("%d", neighbors);
    boardPrint(zeilen, spalten, welt);
    getch();
    
}

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

void fillUp(int zeilen, int spalten, char welt[zeilen][spalten], int lifeZellen, char player){

    for (int i = 0; i < lifeZellen; i++)
    {
        welt[rand()%zeilen][rand()%spalten] = player;
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
    system("clear");
    for (int i = 0; i < zeilen; i++)
    {
        for (int j = 0; j < spalten; j++)
        {
            printf("%c", welt[i][j]);
        }
        printf("\n");
    }
    
}

char getch()
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}