/*
File: ceasarVerschluesselung.c
Date: 01.01.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *str, int key);
void decrypt(char *str);

int main(int argc, char* argv[])
{
    char string[100];
    int key = 0;
    int auswahl = 0;

    printf("Bitte geben Sie einen String ein: ");
    fgets(string, sizeof(string), stdin);

    printf("Verschlüsselung (1)\nEntschlüsselung (2)\n");
    printf("----> ");
    scanf("%d", &auswahl);

    switch (auswahl)
    {
    case 1:
        printf("Bitte geben Sie einen Schlüssel ein: ");
        scanf("%d", &key);
        encrypt(string, key);
        break;
    case 2:
        decrypt(string);
        break;
    default:
        printf("Ungültige Eingabe!\n");
        break;
    }
}

void encrypt(char *str, int key) {
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' + key) % 26) + 'a';
        }
    }
    printf("%s", str);
}

void decrypt(char *str){
    for (int i = 0; i < 26; i++)
    {
        printf("Entschlüsselter String mit Schlüssel %d: ", i);
        encrypt(str, i);
    }
}