#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 200000

void selection(int* array, int length, long long* count);
void iniArray(int* array);

int main(int argc, char* argv[])
{
    int array[ARR_LENGTH];
    unsigned long long count = 0;

    iniArray(array);

    selection(array, ARR_LENGTH, &count);

    printf("Anzahl der Vergleiche: %lld\n", count);

    return 0;
}

void selection(int* array, int length, long long* count) {
    int i, j, min_idx, temp;
    for (i = 0; i < length-1; i++) {
        min_idx = i;
        for (j = i+1; j < length; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
            (*count)++;
        }
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