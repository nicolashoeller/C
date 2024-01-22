/*
File: whatsappChat.c
Date: 11.01.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define CHATMAX 10000

void splitLines(char*, FILE*, char*, int, int);
void getUserName(char*);
void quantityOfMessages(char*, FILE*, char*, int, int);

int main(int argc, char* argv[])
{
    char userName[MAX];
    char chatLine[CHATMAX];
    
    FILE* file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Beim öffnen der Datei ist ein Problem aufgetreten!");
        return -1;
    }

    getUserName(userName);
    int temp;
    int tempQuantity;
    splitLines(chatLine, file, userName, temp, tempQuantity);
    fclose(file);
    return 0;
}

void getUserName(char* userName){
    printf("Nach welchem Namen soll gesucht werden?\n");
    printf("----> ");
    fgets(userName, MAX, stdin);
}

void splitLines(char* chatLine, FILE* file, char* userName, int temp, int tempQuantity){
    while ((temp = fgetc(file)) != EOF)
    {
        if (fgets(chatLine, strlen(file), file) != NULL)
        {
            quantityOfMessages(chatLine, file, userName, temp, tempQuantity);
        }
        
    }
    printf("%d", tempQuantity);
    
}

void quantityOfMessages(char* chatLine, FILE* file, char* userName, int temp, int count){
    char *posPtr = strstr(userName, chatLine);
    while (posPtr != NULL)
    {
        count++;
        posPtr = strstr(posPtr + 1, chatLine);
    }
    splitLines(chatLine, file, userName, temp, count);
}