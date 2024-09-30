/*
File: speicherverwaltung.c
Date: 07.02.2024
Autor: Nicolas Höller
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int eingabe();
void iniArray(char *);
void firstFit(char *);
void nextFit(char *);
void bestFit(char *);
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
    case 2:
        nextFit(array);
        break;
    case 3:
        bestFit(array);
        break;
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

    printf("-----> ");

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

void nextFit(char *array)
{
    int laenge;
    int auswahl;
    char buchstabe;
    int last = 0;

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

            for (int i = last; i < MAX;)
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
                        last = i;
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

void bestFit(char *array)
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

            int bestIndex = -1;
            int bestSize = MAX + 1; // Größer als jeder mögliche Block

            for (int i = 0; i < MAX;)
            {
                if (array[i] == '0')
                {
                    int start = i;
                    int size = 0;
                    while (i < MAX && array[i] == '0')
                    {
                        size++;
                        i++;
                    }

                    if (size >= laenge && size < bestSize)
                    {
                        bestSize = size;
                        bestIndex = start;
                    }
                }
                else
                {
                    i++;
                }
            }

            if (bestIndex != -1)
            {
                for (int i = 0; i < laenge; i++)
                {
                    array[bestIndex + i] = buchstabe;
                }
            }
            else
            {
                printf("Kein ausreichend großer freier Block gefunden.\n");
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
            printf("Falsche Eingabe\n");
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