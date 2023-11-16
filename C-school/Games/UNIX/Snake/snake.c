/*
File: snake.c
Date: 16.11.2023
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int playerSnake();
int printBoard();
int welcomeScreen();

int main()
{
    system("clear");
    int xPosition = 25;
    int yPosition = 20;

    char spielfeld[xPosition][yPosition];

    //welcomeScreen();
    

    for (int i = 0; i < xPosition; i++)
    {
        for (int j = 0; j < yPosition; j++)
        {
            spielfeld[i][j] = '*';
        }
    }
    printBoard(spielfeld, xPosition, yPosition);
    
}

int welcomeScreen(){
    printf(" __          ________ _      _____ ____  __  __ ______ \n");
    printf(" \\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____\n");
    printf("  \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__  \n");
    printf("   \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __| \n");
    printf("    \\  /\\  /  | |____| |___| |___| |__| | |  | | |____\n");
    printf("     \\/  \\/   |______|______\\_____\\____/|_|  |_|______\n");
    sleep(1);
    system("clear");
    printf("  _______ ____  \n");
    printf(" |__   __/ __ \\ \n");
    printf("    | | | |  | |\n");
    printf("    | | | |  | |\n");
    printf("    | | | |__| |\n");
    printf("    |_|  \\____/ \n");
    sleep(1);
    system("clear");
    printf("   _____ _   _          _  ________ \n");
    printf("  / ____| \\ | |   /\\   | |/ /  ____|\n");
    printf(" | (___ |  \\| |  /  \\  | ' /| |__   \n");
    printf("  \\___ \\| . ` | / /\\ \\ |  < |  __|  \n");
    printf("  ____) | |\\  |/ ____ \\| . \\| |____ \n");
    printf(" |_____/|_| \\_/_/    \\_\\_|\\_\\______|\n");
    sleep(1);
}

int printBoard(char spielfeld[][5], int xPosition, int yPosition){
    for (int i = 0; i < xPosition; i++)
    {
        for (int j = 0; j < yPosition; j++)
        {
            printf("| %c ", spielfeld[i][j]);
        }
        printf("|\n");
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