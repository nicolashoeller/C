/*
File: monitor1.c
Date: 04.12.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int shared_counter;
} Monitor;

Monitor monitor;

void *thread_function(void *arg);
void iniMonitor();

int main(int argc, char *argv[])
{
    pthread_t threads[3];
    int ids[3] = {0, 1, 2};
    iniMonitor();

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, &ids[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void iniMonitor()
{
    pthread_mutex_init(&monitor.mutex, NULL);
    pthread_cond_init(&monitor.cond, NULL);
    monitor.shared_counter = 0;

    return;
}

void *thread_function(void *arg)
{
    int id = *(int *)arg;
    for (int i = 0; i < 100; i++)
    {
        pthread_mutex_lock(&monitor.mutex);

        
        /*
        if (id == 0)
        {
            pthread_mutex_lock(&monitor.mutex);

            monitor.shared_counter++;
            printf("Thread 1: %d\n", monitor.shared_counter);
            usleep(1000);

            pthread_mutex_unlock(&monitor.mutex);
        }
        else if (id == 1)
        {
            pthread_mutex_lock(&monitor.mutex);

            monitor.shared_counter++;
            printf("Thread 2: %d\n", monitor.shared_counter);
            usleep(1000);

            pthread_mutex_unlock(&monitor.mutex);
        }
        else
        {
            pthread_mutex_lock(&monitor.mutex);

            monitor.shared_counter++;
            printf("Thread 3: %d\n", monitor.shared_counter);
            usleep(1000);

            pthread_mutex_unlock(&monitor.mutex);
        }*/
    }

    return NULL;
}