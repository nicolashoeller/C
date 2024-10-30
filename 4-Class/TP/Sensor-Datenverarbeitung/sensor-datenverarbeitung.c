/*
File: sensor-datenverarbeitung.c
Date: 30.10.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/msg.h>

typedef struct msg_buffer {
    long type;
    int message;
} message;

int kill_child = 0;

void write_data_server(int* shm_address, int msgQId);
void read_data_server(int* shm_address, int msgQId, int pid, int shmid);

void handle_signal(int sig){kill_child = 1;}    //  :)

int main(int argc, char* argv[])
{
    key_t key = ftok("sensor.txt", 50);
    int msgQId;
    int shmid;
    int* shm_address;

    srand(time(NULL));

    signal(SIGINT, handle_signal);

    if ((shmid = shmget(key, sizeof(int), IPC_CREAT | 0666)) == -1){
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    if ((shm_address = (int*)shmat(shmid, NULL, 0)) == (int*)-1){
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    if ((msgQId = msgget(IPC_PRIVATE, IPC_CREAT | 0666)) == -1){
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    
    int pid = fork();

    if (pid == -1){
        perror("fork");
        exit(0);
    }

    if (pid == 0)
    {
        write_data_server(shm_address, msgQId);
    }
    else 
    {
        read_data_server(shm_address, msgQId, pid, shmid);
    }
    
}

void write_data_server(int* shm_address, int msgQId){
    message send_buffer;
    send_buffer.message = 1;
    send_buffer.type = 1;
    while (1)
    {
        int current_time = time(NULL);
        while (time(NULL) - current_time != 2);
        *shm_address = rand() % 100;
        send_buffer.message = 1;
        if (msgsnd(msgQId, &send_buffer, sizeof(send_buffer.message), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
    }
}

void read_data_server(int* shm_address, int msgQId, int pid, int shmid){
    message receive_buffer;
    while (1)
    {
        if (msgrcv(msgQId, &receive_buffer, sizeof(receive_buffer.message), 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        if (receive_buffer.message == 1)
        {
            printf("%d\n", *shm_address);
        }

        if (kill_child == 1)
        {
            kill(pid, SIGTERM);

            if (shmdt(shm_address) == -1){
                perror("shmdt");
                exit(EXIT_FAILURE);
            }

            if (shmctl(shmid, IPC_RMID, NULL) == -1){
                perror("shmctl");
                exit(EXIT_FAILURE);
            }
            
            if (msgctl(msgQId, IPC_RMID, NULL) == -1){
                perror("msgctl");
                exit(EXIT_FAILURE);
            }

            exit(0);
        }
        
        receive_buffer.message = 0;
    }
}