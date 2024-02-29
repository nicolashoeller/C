/*
File: autoInfo.c
Date: 29.02.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    char marke[100];
    char maximalGeschwindigkeit[10];
    bool antiblockiersystem;
    int tueren;
} car;

void einspeichern(car *car_t, char* argv[]);
void printStruct(car *car_t);

int main(int argc, char* argv[])
{
    car car_t;

    if (argc != 5)
    {
        printf("Gib als Parameter die Marke, die maximale Geschwindigkeit, das Antiblockiersystem (true/false) und die Anzahl der Türen an.\n");
        return -1;
    }
    
    einspeichern(&car_t, argv);
    printStruct(&car_t);

    return 0;
}

void einspeichern(car *car_t, char* argv[]){
    strcpy(car_t->marke, argv[1]);
    strcpy(car_t->maximalGeschwindigkeit, argv[2]);
    
    if (!strcmp(argv[3], "true"))
    {car_t->antiblockiersystem = true;}
    else
    {car_t->antiblockiersystem = false;}

    car_t->tueren = atoi(argv[4]);
}

void printStruct(car *car_t)
{
    printf("\n");
    printf("Marke: %s\n", car_t->marke);
    printf("Maximale Geschwindigkeit: %s\n", car_t->maximalGeschwindigkeit);
    printf("Antiblockiersystem: %s\n", car_t->antiblockiersystem ? "true" : "false");
    printf("Türen: %d\n", car_t->tueren);
}