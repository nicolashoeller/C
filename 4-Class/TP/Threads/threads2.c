/*
File: threads2.c
Date: 11.11.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *thread_function(void*arg);

int main(int argc, char* argv[])
{
    sem_init(&semaphore, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&semaphore);
}

void *thread_function(void*arg){
    printf("Thread gestartet.\n");

    sem_wait(&semaphore);

    printf("Thread im kritischen Zustand.\n");

    sem_post(&semaphore);
    printf("Thread beendet.\n\n");
    pthread_exit(NULL);
}