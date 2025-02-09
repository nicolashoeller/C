#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 10

int produzierteProdukte = 0;
int kontrollierteProdukte = 0;
int verpackteProdukte = 0;

pthread_mutex_t mutex;
pthread_cond_t condition_produced;
pthread_cond_t condition_checked;

sem_t semaphore_packaging;

void* producer(void* arg);
void* controller(void* arg);
void* packer(void* arg);

int main() {
    pthread_t producerThread, controllerThread, packerThread;

    sem_init(&semaphore_packaging, 0, 0);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&controllerThread, NULL, controller, NULL);
    pthread_create(&packerThread, NULL, packer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(controllerThread, NULL);
    pthread_join(packerThread, NULL);

    sem_destroy(&semaphore_packaging);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition_produced);
    pthread_cond_destroy(&condition_checked);

    printf("Alle Produkte wurden produziert, kontrolliert und verpackt.\n");
    return 0;
}

void* producer(void* arg) {
    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(&mutex);

        produzierteProdukte++;
        printf("Produkt %d hergestellt.\n", produzierteProdukte);

        pthread_cond_signal(&condition_produced);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* controller(void* arg) {
    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(&mutex);

        while (produzierteProdukte <= kontrollierteProdukte) {
            pthread_cond_wait(&condition_produced, &mutex);
        }

        kontrollierteProdukte++;
        printf("Produkt %d kontrolliert.\n", kontrollierteProdukte);

        pthread_cond_signal(&condition_checked);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* packer(void* arg) {
    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(&mutex);

        while (kontrollierteProdukte <= verpackteProdukte) {
            pthread_cond_wait(&condition_checked, &mutex);
        }

        verpackteProdukte++;
        printf("Produkt %d verpackt.\n", verpackteProdukte);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}
