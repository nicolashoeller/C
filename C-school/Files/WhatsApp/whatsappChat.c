/*
File: whatsappChat.c
Date: 11.01.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void getUserName(char*);

int main(int argc, char* argv[])
{
    char userName[MAX];
    
    FILE* file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Beim öffnen der Datei ist ein Problem aufgetreten!");
        return -1;
    }

    getUserName(userName);
    fclose(file);
    return 0;
}

void getUserName(char* userName){
    printf("Nach welchem Namen soll gesucht werden?\n");
    printf("---->");
    fgets(userName, MAX, stdin);
}