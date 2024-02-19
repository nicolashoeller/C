/*
File: whatsapp1.1.c
Date: 01.02.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 100
#define MAX_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1024

int people_count = 0;
char names[MAX_PEOPLE][MAX_NAME_LENGTH];
int message_count[MAX_PEOPLE];

void addOrUpdatePerson(char *);
void analyzeMessages(FILE *);
int analyzeAllSymbols(FILE *);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("FALSCHE EINGABE\n");
        return -1;
    }

    FILE *fp = fopen(argv[2], "r");

    if (!fp)
    {
        printf("Fehler beim Öffnen der Datei\n");
        return -1;
    }

    analyzeMessages(fp);

    if (!strcmp(argv[1], "-d"))
    {
        fseek(fp, 0, SEEK_SET);
        int count = analyzeAllSymbols(fp);
        printf("Anzahl aller Zeichen: %d\n\n", count);
        printf("-------------------\n\n");
    }

    fclose(fp);

    for (int i = 0; i < people_count; i++)
    {
        printf("---> %s: %d Nachricht*en\n", names[i], message_count[i]);
    }
    return 0;
}

void addOrUpdatePerson(char *name)
{
    int i;
    for (i = 0; i < people_count; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            message_count[i]++;
            return;
        }
    }
    if (people_count < MAX_PEOPLE - 1)
    {
        strcpy(names[people_count], name);
        message_count[people_count] = 1;
        people_count++;
    }
}

int analyzeAllSymbols(FILE *fp)
{
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        for (int i = 0; i < strlen(line); i++)
        {
            count++;
        }
    }

    return count;
}

void analyzeMessages(FILE *fp)
{
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *start = strchr(line, ']');
        if (start && strlen(start) > 2)
        {
            start += 2;
            char *end = strchr(start, ':');
            if (end)
            {
                int name_length = end - start;
                char name[MAX_NAME_LENGTH];
                strncpy(name, start, name_length);
                name[name_length] = '\0';
                addOrUpdatePerson(name);
            }
        }
    }
}