/*
File: pipe_2.c
Date: 08.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    int pid;
    char buffer[80];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        close(pipefd[1]);

        sleep(1);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Kindprozess hat empfangen: %s\n", buffer);
        close(pipefd[0]);
    }
    else
    {
        close(pipefd[0]);

        printf("Elternprozess schreibt...\n");
        write(pipefd[1], "Hallo Kindprozess!", 19);
        close(pipefd[1]);
    }

    return 0;
}