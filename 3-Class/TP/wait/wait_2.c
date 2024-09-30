/*
File: wait_2.c
Date: 27.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        printf("Fehler beim Erzeugen des Kindprozesses.\n");
        return -1;
    }

    if (pid == 0) {
        printf("Kindprozess PID: %d\n", getpid());
        sleep(2);
    } else {
        printf("Vaterprozess PID: %d\n", getpid());
        wait(NULL);
        printf("Guten Morgen Kindprozess mit der PID %d\n", pid);
    }

    return 0;
}