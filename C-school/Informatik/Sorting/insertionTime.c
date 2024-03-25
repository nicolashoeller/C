#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LENGTH 200000

void insertion(int* array, int length);
void iniArray(int* array);

int main(int argc, char* argv[])
{
    int array[ARR_LENGTH];
    clock_t start, end;
    double time;

    iniArray(array);

    start = clock();
    insertion(array, ARR_LENGTH);
    end = clock();

    time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Ausführungszeit: %f Sekunden\n", time);

    return 0;
}

void insertion(int* array, int length) {
    int i, key, j;
    for (i = 1; i < length; i++) {
        key = array[i];
        j = i - 1;

        /* Move elements of array[0..i-1], that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void iniArray(int * array){
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        array[i] = rand() % 100;
    }
}