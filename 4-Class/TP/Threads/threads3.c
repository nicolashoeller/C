/*
File: threads3.c
Date: 11.11.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define COUNT 10

sem_t sem_a, sem_b, sem_c;

void* thread_functionA(void*arg);
void* thread_functionB(void*arg);
void* thread_functionC(void*arg);

int main(int argc, char* argv[])
{
    pthread_t threads[3];

    sem_init(&sem_a, 0, 1);
    sem_init(&sem_b, 0, 0);
    sem_init(&sem_c, 0, 0);
    
    pthread_create(&threads[0], NULL, thread_functionA, NULL);
    pthread_create(&threads[1], NULL, thread_functionB, NULL);
    pthread_create(&threads[2], NULL, thread_functionC, NULL);

    for (int i = 0; i < 3; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem_a);
    sem_destroy(&sem_b);
    sem_destroy(&sem_c);
    return 0;
}

void* thread_functionA(void*arg){
    for (int i = 0; i < COUNT; i++)
    {
        sem_wait(&sem_a);
        printf("a");
        sem_post(&sem_b);
    }
    pthread_exit(NULL);
}

void* thread_functionB(void*arg){
    for (int i = 0; i < COUNT; i++)
    {
        sem_wait(&sem_b);
        printf("b");
        sem_post(&sem_c);
    }
    pthread_exit(NULL);
}

void* thread_functionC(void*arg){
    for (int i = 0; i < COUNT; i++)
    {
        sem_wait(&sem_c);
        printf("c ");
        sem_post(&sem_a);
    }
    pthread_exit(NULL);
}