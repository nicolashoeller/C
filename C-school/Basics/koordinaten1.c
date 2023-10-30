/*
Autor: Nicolas Höller
Datum: 25.09.2023
*/


#include <stdio.h>

int main() {
    int x1 = 3;
    int y1 = 7;
    int x2 = 2;
    int y2 = 5;

    int x, y;
    printf("Bitte geben Sie den x-Koordinatenwert ein: ");
    scanf("%d", &x);
    printf("Bitte geben Sie den y-Koordinatenwert ein: ");
    scanf("%d", &y);

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        printf("Der Punkt (%d, %d) liegt im Rechteck.\n", x, y);
    } else {

        if (x < x1) {
            printf("Ziele das nächste Mal weiter nach Rechts\n");
        } else if (x > x2) {
            printf("Ziele das nächste Mal weiter nach Links\n");
        }

        if (y < y1) {
            printf("Ziele das nächste Mal weiter nach Unten\n");
        } else if (y > y2) {
            printf("Ziele das nächste Mal weiter nach Oben\n");
        }
    }

    return 0;
}
