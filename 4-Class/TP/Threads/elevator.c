#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PERSONS 5
#define FLOORS 4

int queues[FLOORS] = {0, 0, 0, 0};
int elevatorPersons = 0;
int currentFloor = 0;
int direction = 1;

pthread_mutex_t lock;

int random_between(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void *populate_queues(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        for (int i = 0; i < FLOORS; i++) {
            queues[i] += random_between(0, 2);
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void *elevator_simulation(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        int personsOut = random_between(0, elevatorPersons);
        elevatorPersons -= personsOut;

        int personsIn = random_between(0, MAX_PERSONS - elevatorPersons);
        if (queues[currentFloor] >= personsIn) {
            queues[currentFloor] -= personsIn;
            elevatorPersons += personsIn;
        } else {
            elevatorPersons += queues[currentFloor];
            queues[currentFloor] = 0;
        }

        printf("----------------------------------\n");
        for (int i = FLOORS - 1; i >= 0; i--) {
            if (i == currentFloor) {
                printf("> %d. [%d] : wait: %d, out: %d, in: %d\n",
                       i + 1, elevatorPersons, queues[i], personsOut, personsIn);
            } else {
                printf("  %d. [ ] : wait: %d\n", i + 1, queues[i]);
            }
        }

        if (currentFloor == 0) {
            direction = 1;
        } else if (currentFloor == FLOORS - 1) {
            direction = -1;
        }

        currentFloor += direction;

        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t queueThread, elevatorThread;

    pthread_mutex_init(&lock, NULL);
    srand(time(NULL));

    pthread_create(&queueThread, NULL, populate_queues, NULL);
    pthread_create(&elevatorThread, NULL, elevator_simulation, NULL);

    pthread_join(queueThread, NULL);
    pthread_join(elevatorThread, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}