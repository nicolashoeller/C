/*
File: palindrom.c
Date: 14.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void eingabe(char* palindrom);
void lowerChar(char* palindrom);
int checkPalindrom(char* palindrom, int i, int n);

int main(int argc, char* argv[])
{
    char palindrom[MAX];

    eingabe(palindrom);

    lowerChar(palindrom);

    int n = strlen(palindrom);
    int i = 0;

    if (checkPalindrom(palindrom, i, n - 1)){
        printf("Dein String ist ein Palindrom\n");
    }
    else
    {
        printf("Dein String ist kein Palindrom\n");
    }
    

    return 0;
}

void eingabe(char* palindrom){
    printf("Gib deinen Namen ein: ");
    scanf("%s", palindrom);
}

void lowerChar(char* palindrom){
    for(int i = 0; i < strlen(palindrom); i++){
        palindrom[i] = tolower(palindrom[i]);
    }
}

int checkPalindrom(char* palindrom, int i, int n){
    if (i >= n)
    {
        return 1;
    }
    else if (palindrom[i] != palindrom[n])
    {
        return 0;
    }
    else
    {
        return checkPalindrom(palindrom, i+1, n-1);
    }
}