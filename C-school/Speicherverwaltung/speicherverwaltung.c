/*
File: speicherverwaltung.c
Date: 07.02.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void iniArray(char *);
int eingabe();
void firstFit(char *);
void arrayPrint(char *);

int main(int argc, char *argv[])
{
    char array[MAX];
    int temp;

    iniArray(array);

    temp = eingabe();

    switch (temp)
    {
    case 1:
        firstFit(array);
        break;
    /*case 2:
        nextFit(array, MAX);
        break;
    case 3:
        bestFit(array, MAX);
        break;*/
    default:
        printf("Falsche Eingabe!");
        return -1;
        break;
    }

    return 0;
}

void iniArray(char *array)
{
    for (int i = 0; i < MAX; i++)
    {
        array[i] = '0';
    }
}

int eingabe()
{
    int eingabe;
    printf("Bitte gib den bevorzugten Algorithmus ein: \n");
    printf("1: First Fit\n");
    printf("2: Next Fit\n");
    printf("3: Best Fit\n");

    scanf("%d", &eingabe);
    return eingabe;
}

void firstFit(char *array)
{
    int laenge;
    int auswahl;
    char buchstabe;

    while (1)
    {
        printf("Hinzufügen (1), löschen (2): ");
        scanf("%d", &auswahl);
        switch (auswahl)
        {
        case 1:
            printf("Bitte gib den Buchstaben ein: ");
            scanf(" %c", &buchstabe);
            printf("Bitte gib die Größe des Speicherblocks ein: ");
            scanf("%d", &laenge);

            for (int i = 0; i < MAX;)
            {
                if (array[i] == '0' && i + laenge <= MAX)
                {
                    int count = 0;
                    while (array[i] == '0' && count < laenge)
                    {
                        count++;
                        i++;
                    }
                    if (count == laenge)
                    {
                        for (int j = 0; j < laenge; j++)
                        {
                            array[i - laenge + j] = buchstabe;
                        }
                        break; // break out of the for loop when enough space is found
                    }
                }
                else
                {
                    i++;
                }
            }
            arrayPrint(array);
            break;
        case 2:
            printf("Bitte gib den Buchstaben ein: ");
            scanf(" %c", &buchstabe);

            for (int i = 0; i < MAX; i++)
            {
                if (array[i] == buchstabe)
                {
                    array[i] = '0';
                }
            }
            arrayPrint(array);
            break;
        default:
            printf("Falsche Eingabe");
            break;
        }
    }
}

void arrayPrint(char *array)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%c", array[i]);
    }
    printf("\n\n");
}