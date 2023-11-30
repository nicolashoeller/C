/*
File: primzahlen.c
Date: 30.11.2023
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdbool.h>

bool primzahlen(int);

int main() {
    int eingabe;

    printf("Geben Sie eine positive Ganzzahl ein: ");
    scanf("%d", &eingabe);

    if (eingabe < 2) {
        printf("Es gibt keine Primzahlen unterhalb von 2.\n");
        return 0;
    }

    printf("Primzahlen bis %d: ", eingabe);
    for (int i = 2; i <= eingabe; i++) {
        if (primzahlen(i)) {
            printf("%d\n", i);
        }
    }
    printf("\n");

    return 0;
}

bool primzahlen(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}