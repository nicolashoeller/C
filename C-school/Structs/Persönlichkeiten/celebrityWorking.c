/*
File: celebrityWorking.c
Date: 11.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define ARRAY_SIZE 26000

// Unterstruktur für das Geburtsdatum
typedef struct {
    int day;
    int month;
    int year;
} Birthdate;

// Hauptstruktur für eine Person
typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    Birthdate birthdate;
} Person;

// Globales Array für Personen
Person persons[ARRAY_SIZE];

Birthdate parse_birthdate(char* dateStr);
int read_persons(char* filename);


int main() {
    int personCount = read_persons("celebrity.txt");

    // Beispiel: Suche nach einer Person
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int found = 0;

    printf("Gib den Voramen ein (MAX 1 NAME): ");
    scanf("%s", firstName);
    printf("Gib den Nachnamen ein (FALLS MEHRERE NAMEN MIT ';' ABSPALTEN): ");
    scanf("%s", lastName);

    for (int i = 0; i < personCount; i++) {
        if (!strcmp(persons[i].firstName, firstName) && !strcmp(persons[i].lastName, lastName)) {
            printf("Gefunden: %s %s, Geburtstag: %d/%d/%d\n",
                   persons[i].firstName, persons[i].lastName,
                   persons[i].birthdate.month, persons[i].birthdate.day, persons[i].birthdate.year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Person nicht gefunden.\n");
    }

    return 0;
}

// Funktion zum Umwandeln eines Datumsstrings in ein Birthdate-Struct
Birthdate parse_birthdate(char* dateStr) {
    Birthdate bd;
    sscanf(dateStr, "%d/%d/%d", &bd.month, &bd.day, &bd.year);
    return bd;
}

// Funktion zum Einlesen der Personen aus einer Datei
int read_persons(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Die Datei konnte nicht geöffnet werden.\n");
        return 0;
    }

    char line[200];
    char* token;
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < ARRAY_SIZE) {
        token = strtok(line, ";");
        if (token) {
            strncpy(persons[count].firstName, token, MAX_NAME_LENGTH - 1);
            persons[count].firstName[MAX_NAME_LENGTH - 1] = '\0';
        }

        token = strtok(NULL, " ");
        if (token) {
            strncpy(persons[count].lastName, token, MAX_NAME_LENGTH - 1);
            persons[count].lastName[MAX_NAME_LENGTH - 1] = '\0';
        }

        token = strtok(NULL, "\n");
        if (token) {
            persons[count].birthdate = parse_birthdate(token);
        }

        count++;
    }

    fclose(file);
    return count;
}