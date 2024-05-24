/*
File: pipe_2.c
Date: 24.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void client(int pipefd[2]);
void server(int pipefd[2]);

int main(int argc, char* argv[])
{
    int pipefd1[2];
    int pid;

    if (pipe(pipefd1) == -1)
        printf("[!] Error creating pipe!");
    

    pid = fork();

    if (pid == 0){
        close(pipefd1[0]);
        client(pipefd1);
        close(pipefd1[1]);
    }
    else{
        close(pipefd1[1]);
        server(pipefd1);
        close(pipefd1[0]);
    }
    
    return 0;
}

void client(int pipefd[2]){
    int num;

    printf("Welche Zahl dem Server zugeschickt werden: ");
    scanf("%d", &num);

    write(pipefd[1], &num, sizeof(num));
}

void server(int pipefd[2]){
    int num;
    
    read(pipefd[0], &num, sizeof(num));
    printf("Der Server hat %d empfangen!\n", num);
}