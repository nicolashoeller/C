#include <stdio.h>
#include <stdlib.h>

void eingabe(int** array, int* size, int* count);

int main(int argc, char* argv[])
{
    int* array = malloc(10 * sizeof(int));
    int size = 10;
    int count = 0;

    eingabe(&array, &size, &count);
    free(array);

    return 0;
}

void eingabe(int** array, int* size, int* count){
    while (1)
    {
        if (*count == *size) {
            *size += 10;
            *array = realloc(*array, *size * sizeof(int));
        }

        printf("Enter an integer: ");
        scanf("%d", &(*array)[*count]);
        (*count)++;
    }
}