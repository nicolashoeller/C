/*
File: threads5.c
Date: 20.11.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define MAX_ITEMS 100

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int producer_count = 0;
int consumer_count = 0;

pthread_mutex_t mutex;
pthread_cond_t condition1;
pthread_cond_t condition2;

void* producer(void* arg);
void* consumer1(void* arg);
void* consumer2(void* arg);

int main() {
    pthread_t producer_thread, consumer1_thread, consumer2_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition1, NULL);
    pthread_cond_init(&condition2, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer1_thread, NULL, consumer1, NULL);
    pthread_create(&consumer2_thread, NULL, consumer2, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer1_thread, NULL);
    pthread_join(consumer2_thread, NULL);

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%d\n", buffer[i]);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition1);
    pthread_cond_destroy(&condition2);

    return 0;
}

void* producer(void* arg) {
    printf("Producer letz Fetz!\n");
    while (producer_count < MAX_ITEMS) {
        pthread_mutex_lock(&mutex);

        while ((in + 1) % BUFFER_SIZE == out) {
            pthread_cond_wait(&condition2, &mutex);
        }

        buffer[in] = producer_count + 1;
        printf("Producer: %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE;
        producer_count++;

        pthread_cond_signal(&condition1);
        pthread_mutex_unlock(&mutex);

        usleep(100000);
    }
    printf("Producer ende Gelände\n");
}

void* consumer1(void* arg) {
    printf("Consumer 1 auf die uans!\n");
    while (consumer_count < MAX_ITEMS) {
        pthread_mutex_lock(&mutex);
        while (in == out) {
            pthread_cond_wait(&condition1, &mutex);
        }

        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        consumer_count++;

        item = -1;
        printf("Consumer 1: %d\n", item);
        buffer[in] = item;

        pthread_cond_signal(&condition2);
        pthread_mutex_unlock(&mutex);

        usleep(150000);
    }
    printf("Consumer 1 ende Gelände!\n");
}

void* consumer2(void* arg) {
    printf("Consumer 2 auf die zwoaa!\n");
    while (consumer_count < MAX_ITEMS) {
        pthread_mutex_lock(&mutex);

        while (in == out) {
            pthread_cond_wait(&condition1, &mutex);
        }

        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        consumer_count++;

        item *= -1;
        printf("Consumer 2: %d\n", item);
        buffer[in] = item;

        pthread_cond_signal(&condition2);
        pthread_mutex_unlock(&mutex);

        usleep(150000);
    }
    printf("Consumer 2 ende Gelände!\n");
}