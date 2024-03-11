/*
File: seitenFehler.c
Date: 01.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20000

void iniArray(int *, int);
void fifo(int, int, int *);
void lru(int, int, int *);
void optimal(int, int, int *);
void second_chance(int, int, int *);
int menu();

int main(int argc, char *argv[])
{
    int seiten = 0;
    int laenge = 0;
    int auswahl = 0;

    printf("Seitenanzahl: ");
    scanf("%d", &seiten);
    printf("Länge: ");
    scanf("%d", &laenge);

    if (laenge > MAX_LENGTH) {
        printf("Länge größer als erlaubt!!\n");
        return -1;
    }

    int feld[MAX_LENGTH];

    iniArray(feld, laenge);

    printf("Reihenfolge eingeben\n");
    for (int i = 0; i < laenge; i++)
    {
        printf("----> ");
        scanf("%d", &feld[i]);
    }

    auswahl = menu();
    switch (auswahl)
    {
    case 1:
        fifo(seiten, laenge, feld);
        break;
    case 2:
        lru(seiten, laenge, feld);
        break;
    case 3:
        second_chance(seiten, laenge, feld);
        break;
    default:
        break;
    }

    return 0;
}

void iniArray(int *feld, int laenge)
{
    for (int i = 0; i < laenge; i++)
    {
        feld[i] = -1;
    }
}

void fifo(int seiten, int laenge, int *feld)
{
    int i, j, k, flag = 0, count = 0;
    int frame[seiten];
    for (i = 0; i < seiten; i++){
        frame[i] = -1;
    }
    printf("Step\tFrame Contents\n");
    for (i = 0; i < laenge; i++)
    {
        flag = 0;
        for (j = 0; j < seiten; j++)
        {
            if (frame[j] == feld[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            frame[count % seiten] = feld[i];
            count++;
            printf("%d\t", i + 1);
            for (k = 0; k < seiten; k++)
                if (frame[k] == -1)
                    printf("E "); // Print 'E' for empty slots
                else
                    printf("%d ", frame[k]);
            printf("\n");
        }
    }
    printf("Page Faults in FIFO: %d\n", count);
}

void lru(int seiten, int laenge, int *feld)
{
    int i, j, k, flag = 0, count = 0, least[seiten];
    int frame[seiten];
    for (i = 0; i < seiten; i++)
        frame[i] = -1;

    printf("Step\tFrame Contents\n");
    for (i = 0; i < laenge; i++)
    {
        flag = 0;
        for (j = 0; j < seiten; j++)
        {
            if (frame[j] == feld[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            if (i < seiten)
            {
                frame[i] = feld[i];
                least[i] = i;
            }
            else
            {
                int min = least[0], pos = 0;
                for (k = 1; k < seiten; k++)
                {
                    if (least[k] < min)
                    {
                        min = least[k];
                        pos = k;
                    }
                }
                frame[pos] = feld[i];
                least[pos] = i;
            }
            count++;
            printf("%d\t", i + 1);
            for (k = 0; k < seiten; k++)
                if (frame[k] == -1)
                    printf("E "); // Print 'E' for empty slots
                else
                    printf("%d ", frame[k]);
            printf("\n");
        }
        else
        {
            least[j] = i;
        }
    }
    printf("Page Faults in LRU: %d\n", count);
}

void second_chance(int seiten, int laenge, int *feld)
{
    int i, j, flag1 = 0, flag2 = 0, count = 0, pos = 0;
    int frame[seiten], second_chance[seiten];
    for (i = 0; i < seiten; i++)
    {
        frame[i] = -1;
        second_chance[i] = 0;
    }

    printf("Step\tFrame Contents\n");
    for (i = 0; i < laenge; i++)
    {
        flag1 = 0, flag2 = 0;
        for (j = 0; j < seiten; j++)
        {
            if (frame[j] == feld[i])
            {
                flag1 = 1, flag2 = 1;
                second_chance[j] = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (j = 0; j < seiten; j++)
            {
                if (frame[j] == -1)
                {
                    count++;
                    frame[j] = feld[i];
                    second_chance[j] = 1;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            while (second_chance[pos] == 1)
            {
                second_chance[pos] = 0;
                pos = (pos + 1) % seiten;
            }
            frame[pos] = feld[i];
            second_chance[pos] = 1;
            pos = (pos + 1) % seiten;
            count++;
        }
        printf("%d\t", i + 1);
        for (j = 0; j < seiten; j++)
            if (frame[j] == -1)
                printf("E "); // Print 'E' for empty slots
            else
                printf("%d ", frame[j]);
        printf("\n");
    }
    printf("Page Faults in Second Chance: %d\n", count);
}

int menu()
{
    int auswahl = 0;
    printf("1. FIFO\n");
    printf("2. LRU\n");
    printf("3. Second chance\n");
    printf("Wählen Sie einen Algorithmus: ");
    scanf("%d", &auswahl);
    return auswahl;
}