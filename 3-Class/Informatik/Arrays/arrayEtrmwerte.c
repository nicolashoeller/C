#include <stdio.h>

int main() {
    int zahlen[100];
    int eingabe, anzahl = 0;
    int maximum, minimum;
    float summe = 0.0;
    float durchschnitt = 0;

    printf("Geben Sie positive ganze Zahlen ein (Negative Zahl zum Beenden):\n");

    while (1) {
        scanf("%d", &eingabe);

        if (eingabe < 0) {
            break;                      // Die Schleife beenden, wenn eine negative Zahl eingegeben wird
        }

        if (anzahl == 0) {
            maximum = eingabe;
            minimum = eingabe;
        } 
        else 
        {
            if (eingabe > maximum) {
                maximum = eingabe;
            }
            if (eingabe < minimum) {
                minimum = eingabe;
            }
        }

        summe += eingabe;
        zahlen[anzahl] = eingabe;
        anzahl++;
    }

    printf("Größte Zahl: %d\n", maximum);
    printf("Kleinste Zahl: %d\n", minimum);
    printf("Durchschnitt: %.2f\n", summe/anzahl);


    return 0;
}
