/*
File: parkplatz_simulation.c
Date: 11.12.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/msg.h>
#include <time.h>

#define MAX_AUTOS 20

void*thread_function(void*arg);

typedef struct
{
    long long id;
    char*string;
} MsgSendAndReceive;


typedef struct
{
    int id;
    int msgQId;
} MsgStruct;


int frei = 5;

pthread_mutex_t einfahrt;
pthread_mutex_t ausfahrt;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    pthread_t autos[MAX_AUTOS];
    int ids[MAX_AUTOS];
    
    MsgStruct id_and_msgQId;

    int msgQId = msgget(IPC_PRIVATE, IPC_CREAT | 0666);

    id_and_msgQId.msgQId = msgQId;

    pthread_mutex_init(&einfahrt, NULL);
    pthread_mutex_init(&ausfahrt, NULL);

    for (int i = 0; i < MAX_AUTOS; i++)
    {
        id_and_msgQId.id = i;
        pthread_create(&autos[i], NULL, thread_function, (void*)&id_and_msgQId);
        usleep(200);
    }
    

    for (int i = 0; i < MAX_AUTOS; i++)
    {
        pthread_join(autos[i], NULL);
    }

    pthread_mutex_destroy(&einfahrt);
    pthread_mutex_destroy(&ausfahrt);

    msgctl(msgQId, IPC_RMID, NULL);
    
    return 0;
}

void*thread_function(void*arg){
    MsgStruct id_and_msgQId = *(MsgStruct*)arg;
    pthread_mutex_lock(&einfahrt);

    while (frei == 0)
    {
        sleep(1);
    }

    printf("Thread mit ID %d parkt\n", id_and_msgQId.id);

    frei--;
    sleep(1);

    pthread_mutex_unlock(&einfahrt);

    int parkdauer = rand()%5+1;

    sleep(parkdauer);

    pthread_mutex_lock(&ausfahrt);

    int zahlen = parkdauer*10;
    printf("Thread mit ID %d verlässt den Parkplatz und bezahlt %d€\n", id_and_msgQId.id, zahlen);

    frei++;
    sleep(1);

    pthread_mutex_unlock(&ausfahrt);

    return NULL;
}