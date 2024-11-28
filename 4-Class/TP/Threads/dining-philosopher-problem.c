/*
File: dining-philosopher-problem.c
Date: 20.11.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* philosoph(void*arg);
void stuckARuck();

pthread_cond_t conditions[5];
pthread_mutex_t mutex;

int threadIsActive = 0;

int philosophen_essen[5] = {0,1,0,1,0};
int seinSeToad[5] = {0,0,0,0,0};

int main(int argc, char* argv[])
{
    pthread_t philosophen[5];

    int id[5] = {0,1,2,3,4};

    for (int i = 0; i < 5; i++)
    {
        pthread_cond_init(&conditions[i], NULL);
    }

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&philosophen[i], NULL, philosoph, &id[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        pthread_join(philosophen[i], NULL);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_cond_destroy(&conditions[i]);
    }

    pthread_mutex_destroy(&mutex);
    
    return 0;
}

void* philosoph(void*arg){
    int id = *(int*)arg;

    for (int i = 0; i < 50; i++)
    {
        pthread_mutex_lock(&mutex);

        while (threadIsActive != id)
        {
            pthread_cond_wait(&conditions[id], &mutex);
        }
        
        if (philosophen_essen[id] == 1)
        {
            printf("Philosoph %d: Philosophen mampfn!\n", id+1);
            seinSeToad[id] = 0;
        } else
        {
            seinSeToad[id]++;
            printf("Philosoph %d: Wo geht der Rote Punkt?\n", id+1);
        }

        if (id == 4)
        {
            printf("\n");
        }

        if (seinSeToad[id] > 3)
        {
            printf("Philosoph %d: AHHHHHH ICH STERBEEEEEEEE!!!\n", id);
            pthread_exit(0);
        }

        if (id == 4)
        {
            stuckARuck();
        }

        threadIsActive = (threadIsActive + 1) % 5;

        usleep(100000);
        
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&conditions[threadIsActive]);
        
    }
    
}

void stuckARuck(){
    int last = philosophen_essen[4];
    for (int i = 4; i > 0; i--) {
        philosophen_essen[i] = philosophen_essen[i - 1];
    }
    philosophen_essen[0] = last;
}