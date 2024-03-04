#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CAR_COUNT 3
#define PARAMS_PER_CAR 4
#define MARKE_LENGTH 100
#define MAX_GESCHWINDIGKEIT_LENGTH 10

typedef struct {
    char marke[MARKE_LENGTH];
    char maximalGeschwindigkeit[MAX_GESCHWINDIGKEIT_LENGTH];
    bool antiblockiersystem;
    int tueren;
} car;

void einspeichern(car *car_t, char *argv[]);
void printStruct(const car *car_t);
int berechneWert(const car *car_t);

int main(int argc, char *argv[]) {
    if (argc != (CAR_COUNT * PARAMS_PER_CAR) + 1) {
        fprintf(stderr, "Fehler: Bitte geben Sie genau %d Parameter für jedes der %d Autos ein.\n", PARAMS_PER_CAR, CAR_COUNT);
        return -1;
    }

    car cars[CAR_COUNT];

    for (int i = 0; i < CAR_COUNT; i++) {
        einspeichern(&cars[i], &argv[i * PARAMS_PER_CAR + 1]);
        printStruct(&cars[i]);
        printf("Wert des Autos: %d\n", berechneWert(&cars[i]));
    }

    return 0;
}

int berechneWert(const car *car_t) {
    int wert = atoi(car_t->maximalGeschwindigkeit) * 50;
    wert += car_t->antiblockiersystem ? 5000 : 0;
    wert *= car_t->tueren;

    if (!strcmp(car_t->marke, "Porsche")) {
        wert *= 2;
    } else if (!strcmp(car_t->marke, "Lamborghini")) {
        wert *= 20;
    }

    return wert;
}

void einspeichern(car *car_t, char **argv) {
    strncpy(car_t->marke, argv[0], MARKE_LENGTH - 1);
    car_t->marke[MARKE_LENGTH - 1] = '\0';

    strncpy(car_t->maximalGeschwindigkeit, argv[1], MAX_GESCHWINDIGKEIT_LENGTH - 1);
    car_t->maximalGeschwindigkeit[MAX_GESCHWINDIGKEIT_LENGTH - 1] = '\0';

    car_t->antiblockiersystem = strcmp(argv[2], "true") == 0;
    car_t->tueren = atoi(argv[3]);
}

void printStruct(const car *car_t) {
    printf("\nMarke: %s\n", car_t->marke);
    printf("Maximale Geschwindigkeit: %s\n", car_t->maximalGeschwindigkeit);
    printf("Antiblockiersystem: %s\n", car_t->antiblockiersystem ? "true" : "false");
    printf("Türen: %d\n", car_t->tueren);
}