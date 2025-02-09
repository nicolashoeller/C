/*
File: threads_bubble_sort.c
Date: 02.12.2024
Author: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ARRAY_SIZE 100
#define THREADS_NUMBER 3
#define RANDOM 999

int array[ARRAY_SIZE];
int positions[THREADS_NUMBER][2];

void* bubble_sort(void* arg);

int main()
{
    srand(time(NULL));
    pthread_t threads[THREADS_NUMBER];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % RANDOM;
    }

    printf("Original Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int segment_size = (ARRAY_SIZE + THREADS_NUMBER - 1) / THREADS_NUMBER;

    float a;
    clock_t time_req;
 
    time_req = clock();

    for (int i = 0; i < THREADS_NUMBER; i++) {
        positions[i][0] = i * segment_size;
        positions[i][1] = (i + 1) * segment_size;
        if (positions[i][1] > ARRAY_SIZE) {
            positions[i][1] = ARRAY_SIZE;
        }

        pthread_create(&threads[i], NULL, bubble_sort, &positions[i]);
    }

    for (int i = 0; i < THREADS_NUMBER; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    time_req = clock() - time_req;
    printf("\nTime taken: %f "
           "seconds\n",
           (float)time_req / CLOCKS_PER_SEC);

    return 0;
}

void* bubble_sort(void* arg)
{
    int* range = (int*)arg;
    int start = range[0];
    int end = range[1];

    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start) - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    return NULL;
}
