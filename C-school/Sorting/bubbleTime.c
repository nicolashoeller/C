#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LENGTH 200000

void iniArray(int* array);
void bubble(int* array);

int main(int argc, char* argv[])
{
    int array[ARR_LENGTH];
    clock_t start, end;
    double time;

    iniArray(array);

    start = clock();
    bubble(array);
    end = clock();

    time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Ausführungszeit: %f Sekunden\n", time);

    return 0;
}

void bubble(int* array) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < ARR_LENGTH - 1; i++) {
        swapped = 0;
        for (j = 0; j < ARR_LENGTH - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        // Wenn keine zwei Elemente vertauscht wurden, bricht die Schleife ab
        if (swapped == 0)
            break;
    }
}

void iniArray(int * array){
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        array[i] = rand() % 100;
    }
}