/*
File: message_queues3.c
Date: 23.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <time.h>
#include <string.h>

typedef struct msg_buffer{
    long type;
    char text[100];
} message;

void server(int);
void client(int);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int pid;
    int msgQId;

    if ((msgQId = msgget(IPC_PRIVATE, IPC_CREAT | 0666)) == -1)
        printf("msgget");

    pid = fork();

    if (pid == 0)
    {
        server(msgQId);
    }
    else
    {
        client(msgQId);
    }

    return 0;
}

void client(int msgQId){
    message send_buffer;
    send_buffer.type = 1;

    printf("Gib ein was gedruckt werden soll: ");
    scanf("%s", send_buffer.text);
    if ((msgsnd(msgQId, &send_buffer, sizeof(send_buffer), 0)) == -1) {
        perror("msgsnd");
        exit(1);
    }

    if (msgrcv(msgQId, &send_buffer, sizeof(send_buffer), 2, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }
    printf("Status Drucker: %s", send_buffer.text);
}

void server(int msgQId){
    message rcv_buffer;
    rcv_buffer.type = 1;
    int random_num = rand() % 100;

    if (msgrcv(msgQId, &rcv_buffer, sizeof(rcv_buffer) + 1, 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Empfangene Nachricht vom Server: %s\n", rcv_buffer.text);

    rcv_buffer.type = 2;

    if (random_num < 70){
        strcpy(rcv_buffer.text, "Erfolgreich gedruckt!");
    }else if (random_num < 90 && random_num >= 70){
        strcpy(rcv_buffer.text, "Kein Papier");
    }else{
        strcpy(rcv_buffer.text, "Eingabe-/Ausgabefehler");
    }

    msgsnd(msgQId, &rcv_buffer, sizeof(rcv_buffer.text) + 1, 0);
}