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

    // Initialisierung des Rahmen-Arrays mit -1, um leere Slots zu markieren
    for (i = 0; i < seiten; i++) {
        frame[i] = -1;
    }

    printf("Step\tFrame Contents\n");

    // Schleife durchläuft die Seitenreferenzen
    for (i = 0; i < laenge; i++)
    {
        flag = 0;

        // Überprüfung, ob die Seite bereits im Hauptspeicher vorhanden ist
        for (j = 0; j < seiten; j++)
        {
            if (frame[j] == feld[i])
            {
                flag = 1; // Seite bereits im Hauptspeicher gefunden
                break;
            }
        }

        // Seitenersetzungslogik bei Seitenfehler
        if (flag == 0)
        {
            frame[count % seiten] = feld[i]; // Austausch der ältesten Seite im Hauptspeicher
            count++;

            // Ausgabe des aktuellen Schritts und des Hauptspeicherinhalts
            printf("%d\t", i + 1);
            for (k = 0; k < seiten; k++)
                if (frame[k] == -1)
                    printf("E "); // Ausgabe 'E' für leere Slots
                else
                    printf("%d ", frame[k]);
            printf("\n");
        }
    }

    // Ausgabe der Gesamtanzahl der Seitenfehler im FIFO-Algorithmus
    printf("Page Faults in FIFO: %d\n", count);
}

void lru(int seiten, int laenge, int *feld)
{
    int i, j, k, flag = 0, count = 0, least[seiten];
    int frame[seiten];

    // Initialisierung des Rahmen-Arrays und least-Arrays mit -1 bzw. 0
    for (i = 0; i < seiten; i++) {
        frame[i] = -1;
        least[i] = 0;
    }

    printf("Step\tFrame Contents\n");

    // Schleife durchläuft die Seitenreferenzen
    for (i = 0; i < laenge; i++)
    {
        flag = 0;

        // Überprüfung, ob die Seite bereits im Hauptspeicher vorhanden ist
        for (j = 0; j < seiten; j++)
        {
            if (frame[j] == feld[i])
            {
                flag = 1; // Seite bereits im Hauptspeicher gefunden
                break;
            }
        }

        // Seitenersetzungslogik bei Seitenfehler
        if (flag == 0)
        {
            if (i < seiten)
            {
                frame[i] = feld[i];
                least[i] = i; // Aktualisierung des zuletzt benutzten Zeitpunkts
            }
            else
            {
                int min = least[0], pos = 0;

                // Suche nach der Seite mit dem ältesten Zeitpunkt
                for (k = 1; k < seiten; k++)
                {
                    if (least[k] < min)
                    {
                        min = least[k];
                        pos = k;
                    }
                }

                // Austausch der Seite mit dem ältesten Zeitpunkt
                frame[pos] = feld[i];
                least[pos] = i; // Aktualisierung des zuletzt benutzten Zeitpunkts
            }

            count++;

            // Ausgabe des aktuellen Schritts und des Hauptspeicherinhalts
            printf("%d\t", i + 1);
            for (k = 0; k < seiten; k++)
                if (frame[k] == -1)
                    printf("E "); // Ausgabe 'E' für leere Slots
                else
                    printf("%d ", frame[k]);
            printf("\n");
        }
        else
        {
            least[j] = i; // Aktualisierung des zuletzt benutzten Zeitpunkts
        }
    }

    // Ausgabe der Gesamtanzahl der Seitenfehler im LRU-Algorithmus
    printf("Page Faults in LRU: %d\n", count);
}

void second_chance(int seiten, int laenge, int *feld)
{
    int i, j, flag1 = 0, flag2 = 0, count = 0, pos = 0;
    int frame[seiten], second_chance[seiten];

    // Initialisierung des Rahmen-Arrays und second_chance-Arrays mit -1 bzw. 0
    for (i = 0; i < seiten; i++) {
        frame[i] = -1;
        second_chance[i] = 0;
    }

    printf("Step\tFrame Contents\n");

    // Schleife durchläuft die Seitenreferenzen
    for (i = 0; i < laenge; i++)
    {
        flag1 = 0, flag2 = 0;

        // Überprüfung, ob die Seite bereits im Hauptspeicher vorhanden ist
        for (j = 0; j < seiten; j++)
        {
            if (frame[j] == feld[i])
            {
                flag1 = 1, flag2 = 1;
                second_chance[j] = 1; // Markierung der Seite mit "zweiter Chance"
                break;
            }
        }

        // Seitenersetzungslogik bei Seitenfehler
        if (flag1 == 0)
        {
            for (j = 0; j < seiten; j++)
            {
                if (frame[j] == -1)
                {
                    count++;
                    frame[j] = feld[i];
                    second_chance[j] = 1; // Markierung der Seite mit "zweiter Chance"
                    flag2 = 1;
                    break;
                }
            }
        }

        // Weitere Seitenersetzungslogik, wenn keine leeren Slots vorhanden sind
        if (flag2 == 0)
        {
            while (second_chance[pos] == 1)
            {
                second_chance[pos] = 0;
                pos = (pos + 1) % seiten;
            }

            // Austausch der Seite mit "zweiter Chance"
            frame[pos] = feld[i];
            second_chance[pos] = 1; // Markierung der Seite mit "zweiter Chance"
            pos = (pos + 1) % seiten;
            count++;
        }

        // Ausgabe des aktuellen Schritts und des Hauptspeicherinhalts
        printf("%d\t", i + 1);
        for (j = 0; j < seiten; j++)
            if (frame[j] == -1)
                printf("E "); // Ausgabe 'E' für leere Slots
            else
                printf("%d ", frame[j]);
        printf("\n");
    }

    // Ausgabe der Gesamtanzahl der Seitenfehler im Second Chance-Algorithmus
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