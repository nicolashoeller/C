/*
File: drucker.c
Date: 27.05.2024
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

#define MAX_PRINTERS 5
#define ERROR_PROBABILITY 0.2  // 20% probability of error

typedef struct msg {
    long msg_type;
    char msg_text[100];
} message;

typedef struct {
    char name[100];
    int address;
} Printer;

void druck_server(Printer* printer_addr, int msg_q, int shmid);
void druck_client(Printer* printer_addr, int msg_q, int shmid);
void registerPrinter(Printer* printer_addr, int index, int pid, char* name);
void printRequest(int msg_q, int type);
void error_n_die(const char *error);
void ausgabe_drucker(Printer* printer_addr);
void handle_print_error(int msg_q, message* rcv_buffer);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int pid;
    int msg_q;
    key_t key = ftok("drucker.c", 'B');
    int shmid;
    Printer* printer_addr;

    if ((msg_q = msgget(key, IPC_CREAT | 0666)) == -1)
        error_n_die("msgget");

    if ((shmid = shmget(key, MAX_PRINTERS * sizeof(Printer), IPC_CREAT | 0666)) == -1)
        error_n_die("shmget");

    if ((printer_addr = shmat(shmid, NULL, 0)) == (Printer*) -1)
        error_n_die("shmat");

    if ((pid = fork()) == -1)
        error_n_die("fork");
    if (pid == 0){
        druck_server(printer_addr, msg_q, shmid);
    }
    else{
        druck_client(printer_addr, msg_q, shmid);
        wait(NULL);
    }

    return 0;
}

void druck_server(Printer* printer_addr, int msg_q, int shmid){
    int pid;
    for (int i = 0; i < MAX_PRINTERS; i++) {
        if ((pid = fork()) == -1)
            error_n_die("fork");

        if (pid == 0) {
            char name[100];
            sprintf(name, "Drucker %d", getpid());
            registerPrinter(printer_addr, i, getpid(), name);

            printRequest(msg_q, getpid());
            exit(0);
        }
    }

    for (int i = 0; i < MAX_PRINTERS; i++) {
        wait(NULL);  // Auf alle Kindprozesse warten
    }
}

void druck_client(Printer* printer_addr, int msg_q, int shmid){
    int drucker_id;
    message snd_buffer;

    while (1) {
        sleep(1);
        printf("Welchen Drucker möchtest du auswählen? (Zum Beenden -1 eingeben)\n");
        ausgabe_drucker(printer_addr);

        printf("----> ");
        scanf("%d", &drucker_id);

        if (drucker_id == -1) {
            break;
        }

        snd_buffer.msg_type = drucker_id;

        printf("Was möchtest du senden?\n-----> ");
        scanf("%s", snd_buffer.msg_text);

        if (msgsnd(msg_q, &snd_buffer, sizeof(snd_buffer.msg_text), 0) == -1)
            error_n_die("msgsnd");
    }
}

void printRequest(int msg_q, int type){
    message rcv_buffer;
    while (1) {
        if (msgrcv(msg_q, &rcv_buffer, sizeof(rcv_buffer.msg_text), type, 0) == -1)
            error_n_die("msgrcv");

        if ((rand() % 100) < (ERROR_PROBABILITY * 100)) {
            printf("Drucker %d: Druckfehler bei Auftrag \"%s\".\n", type, rcv_buffer.msg_text);
            handle_print_error(msg_q, &rcv_buffer);
        } else {
            printf("Drucker %d: Druckauftrag erfolgreich gedruckt: \"%s\"\n", type, rcv_buffer.msg_text);
        }
    }
}

void handle_print_error(int msg_q, message* rcv_buffer) {
    int pipefd[2];

    if (pipe(pipefd) == -1)
        error_n_die("pipe");

    int pid = fork();
    if (pid == -1) {
        error_n_die("fork");
    }

    if (pid == 0) {
        close(pipefd[1]);
        read(pipefd[0], rcv_buffer->msg_text, sizeof(rcv_buffer->msg_text));
        close(pipefd[0]);

        if (msgsnd(msg_q, rcv_buffer, sizeof(rcv_buffer->msg_text), 0) == -1)
            error_n_die("msgsnd");
        exit(0);
    } else {
        close(pipefd[0]);
        write(pipefd[1], rcv_buffer->msg_text, sizeof(rcv_buffer->msg_text));
        close(pipefd[1]);
        wait(NULL);
    }
}

void registerPrinter(Printer* printer_addr, int index, int pid, char* name){
    printer_addr[index].address = pid;
    strcpy(printer_addr[index].name, name);
}

void ausgabe_drucker(Printer* printer_addr){
    for (int i = 0; i < MAX_PRINTERS; i++) {
        printf("%d, %s\n", printer_addr[i].address, printer_addr[i].name);
    }
}

void error_n_die(const char *error) {
    perror(error);
    exit(1);
}
