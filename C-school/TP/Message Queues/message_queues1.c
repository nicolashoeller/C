/*
File: message_queues1.c
Date: 23.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <time.h>

struct msg_buffer{
    long msg_Type;
    char msg_Text[100];
} message;

void error_and_die(const char* error);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int key = rand() % 1000;
    int msgQId;

    if ((msgQId = msgget(key, IPC_CREAT | 0666)) == -1)   
        error_and_die("Error get msgQ");

    printf("Type in your message!\n----> ");
    scanf("%s", message.msg_Text);
    message.msg_Type = 1;
    
    msgsnd(msgQId, message.msg_Text, sizeof(message), 0);

    printf("Message recieved: %s", message.msg_Text);
    
    return 1;
}

void error_and_die(const char* error) {
    printf("%s", error);
    printf("\n");
    exit(0);
}