#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void sieveOfEratosthenes(int limit, bool isPrime[]) {
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int upperLimit;

    printf("Geben Sie die Obergrenze für die Primzahlen ein: ");
    scanf("%d", &upperLimit);

    // Initialisiere ein Array, um zu verfolgen, ob eine Zahl eine Primzahl ist
    bool *isPrime = (bool *)malloc((upperLimit + 1) * sizeof(bool));
    for (int i = 0; i <= upperLimit; i++) {
        isPrime[i] = true;
    }

    // Starte die Zeitmessung
    clock_t start = clock();

    sieveOfEratosthenes(upperLimit, isPrime);

    // Stoppe die Zeitmessung
    clock_t end = clock();

    // Zähle die Primzahlen und gib sie aus
    int count = 0;
    for (int i = 2; i <= upperLimit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
            count++;
        }
    }

    // Gib die Zeit für die Berechnung aus
    printf("\nEs wurden %d Primzahlen gefunden.\n", count);
    printf("Die Berechnung dauerte %f Sekunden.\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Freigabe des Speichers
    free(isPrime);

    return 0;
}
