/*
File: threads1.c
Date: 11.11.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int var = 0;

void *thread_function(void *arg);

int main(int argc, char* argv[])
{
    pthread_t pthread[10];

    for (int i = 0; i < 10; i++)
    {
        int *arg = malloc(sizeof(int));
        *arg = i;
        if (pthread_create(&pthread[i], NULL, thread_function, arg))
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }

        if ((pthread_join(pthread[i], NULL)) != 0){
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
        usleep(100);
    }

    printf("All threads joined!\n");

    return 0;
}

void *thread_function(void *arg) {
    int *nummer = (int*)arg;
    printf("Hello I'm the %d thread! I have the var %d\n", *nummer, var);
    var++;
    pthread_exit(NULL);
    free(arg);
}