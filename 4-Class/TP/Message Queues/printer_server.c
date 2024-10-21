/*
File: printer_server.c
Date: 14.10.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <signal.h>

#define MAX_CLIENTS 5

typedef struct msg_buffer
{
    long msg_type;
    char msg_text[100];
} message;

void client_server(int);
void print_server(int);

int main(int argc, char *argv[])
{
    int pid;
    int msgQId;
    srand(time(NULL));

    if ((msgQId = msgget(IPC_PRIVATE, IPC_CREAT | 0666)) < 0)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == 0)
    {
        client_server(msgQId);
        exit(0);
    }
    else
    {
        print_server(msgQId);
        wait(NULL);
        msgctl(msgQId, IPC_RMID, NULL);
    }

    return 0;
}

void client_server(int msgQId)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            sleep(rand() % 3);
            message send_buffer;
            send_buffer.msg_type = 1;

            if (msgsnd(msgQId, &send_buffer, sizeof(send_buffer.msg_text), 0) == -1)
            {
                perror("msgsnd");
                exit(EXIT_FAILURE);
            }

            message receive_buffer;
            if (msgrcv(msgQId, &receive_buffer, sizeof(receive_buffer.msg_text), i + 1, 0) == -1)
            {
                perror("msgrcv");
                exit(EXIT_FAILURE);
            }
            printf("Client %d received: %s\n", i + 1, receive_buffer.msg_text);

            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }
}

void print_server(int msgQId)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        message receive_buffer;

        if (msgrcv(msgQId, &receive_buffer, sizeof(receive_buffer.msg_text), 1, 0) == -1)
        {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        message send_buffer;
        send_buffer.msg_type = i + 1;
        int random = rand() % 101;

        if (random <= 70)
        {
            sprintf(send_buffer.msg_text, "Ich bin die Biene %d", i + 1);
        }
        else if (random > 70 && random <= 90)
        {
            strcpy(send_buffer.msg_text, "Kein Papier!");
        }
        else
        {
            strcpy(send_buffer.msg_text, "Eingabe-/Ausgabefehler");
        }

        if (msgsnd(msgQId, &send_buffer, sizeof(send_buffer.msg_text), 0) == -1)
        {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
    }
}