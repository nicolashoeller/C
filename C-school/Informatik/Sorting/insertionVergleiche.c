#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 100000

void insertion(int* array, int length, unsigned long long* count);
void iniArray(int* array);

int main(int argc, char* argv[])
{
    int array[ARR_LENGTH];
    unsigned long long count = 0;

    iniArray(array);

    insertion(array, ARR_LENGTH, &count);

    printf("Anzahl der Vergleiche: %d\n", count);

    return 0;
}

void insertion(int* array, int length, unsigned long long* count) {
    int i, key, j;
    for (i = 1; i < length; i++) {
        key = array[i];
        j = i - 1;

        /* Move elements of array[0..i-1], that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            (*count)++;
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