/*
File: message_queues4.c
Date: 24.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

typedef struct msg_buffer{
    long msg_type;
    int msg_text;
} message;

void client(int);
void server(int);

int main(int argc, char* argv[])
{
    int pid;
    int key = rand() % 1000;
    int msgQId;

    msgQId = msgget(key, IPC_CREAT | 0666);

    pid = fork();

    if (pid == 0)
    {
        client(msgQId);
    }
    else
    {
        wait(NULL);
        server(msgQId);
        msgctl(msgQId, IPC_RMID, NULL);
    }
    
    return 0;

}

void client(int msgQId){
    message snd_buffer;
    snd_buffer.msg_type = 1;
    printf("Welche Zahl soll mit 5 multipliziert werden: ");
    scanf("%d", &snd_buffer.msg_text);

    msgsnd(msgQId, &snd_buffer, sizeof(snd_buffer), 0);
}

void server(int msgQId){
    message rcv_buffer;

    msgrcv(msgQId, &rcv_buffer, sizeof(rcv_buffer), 1, 0);
    printf("Die Zahl ist: %d", rcv_buffer.msg_text*5);
}