/*
File: message_queues2.c
Date: 23.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <time.h>

typedef struct msg_buffer{
    long msg_type;
    char msg_text[100];
} message;

void error_and_die(const char* error);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    key_t key = rand() % 1000;
    int msgQId;
    int pid;

    message send_buffer, rec_buffer;

    if ((msgQId = msgget(IPC_PRIVATE, IPC_CREAT | 0666)) == -1)
        error_and_die("Error msgget");
    
    pid = fork();

    if (pid == 0)
    {
        printf("Gib die Nachricht ein die dem Vater zugesendet werden soll\n----> ");
        scanf("%s", send_buffer.msg_text);

        send_buffer.msg_type = 1;

        msgsnd(msgQId, &send_buffer, sizeof(send_buffer.msg_text) + 1, IPC_NOWAIT);
    }
    else
    {
        wait(NULL);
        msgrcv(msgQId, &rec_buffer, sizeof(rec_buffer.msg_text) + 1, 1, IPC_NOWAIT);
        printf("Diese Nachricht wurde empfangen: %s", rec_buffer.msg_text);

        msgctl(msgQId, IPC_RMID, 0);
    }
    
    

    return 0;
}

void error_and_die(const char* error) {
    printf("%s", error);
    printf("\n");
    exit(0);
}