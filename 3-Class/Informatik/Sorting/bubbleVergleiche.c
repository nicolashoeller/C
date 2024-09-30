#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 100000

void bubble(int* array, int length, unsigned long long* count);
void iniArray(int* array);

int main(int argc, char* argv[])
{
    int array[ARR_LENGTH];
    unsigned long long count = 0;

    iniArray(array);

    bubble(array, ARR_LENGTH, &count);

    printf("Anzahl der Vergleiche: %llu\n", count);

    return 0;
}

void bubble(int* array, int length, unsigned long long* count) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < length - 1; i++) {
        swapped = 0;
        for (j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
            (*count)++;
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