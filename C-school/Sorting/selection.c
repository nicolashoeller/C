/*
File: selection.c
Date: 13.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void selection_sort(int *, int);

int main()
{
    int arr[ARRAY_SIZE];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(NULL));
    printf("Unsorted array: \n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    printf("\n");

    selection_sort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void selection_sort(int *arr, int n)
{
    int min_idx, temp;

    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}