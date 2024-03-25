#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LENGTH 200000

void selection(int* array, int length);
void iniArray(int* array);

int main(int argc, char* argv[])
{
    int array[ARR_LENGTH];
    clock_t start, end;
    double time;

    iniArray(array);

    start = clock();
    selection(array, ARR_LENGTH);
    end = clock();

    time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Ausführungszeit: %f Sekunden\n", time);

    return 0;
}

void selection(int* array, int length) {
    int i, j, min_idx, temp;
    for (i = 0; i < length-1; i++) {
        min_idx = i;
        for (j = i+1; j < length; j++)
            if (array[j] < array[min_idx])
                min_idx = j;
        temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

void iniArray(int * array){
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        array[i] = rand() % 100;
    }
}