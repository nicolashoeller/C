/*
File: pipe_2.c
Date: 08.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    int pipefd2[2];
    int pid;
    char buffer[80];
    char buffer2[80];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd2) == -1)
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

        int num1, num2;
        int loesung;
        char operator;

        sscanf(buffer, "%d %c %d", &num1, &operator, & num2);

        close(pipefd[0]);

        switch (operator)
        {
        case '+':
            loesung = num1 + num2;
            break;
        case '-':
            loesung = num1 - num2;
            break;
        case '*':
            loesung = num1 * num2;
            break;
        case '/':
            loesung = num1 / num2;
            break;
        default:
            break;
        }

        close(pipefd2[0]);

        write(pipefd2[1], &loesung, sizeof(loesung));

        close(pipefd2[1]);
    }
    else
    {
        close(pipefd[0]);

        char *rechnung = "4*4";
        int loesung;
        write(pipefd[1], rechnung, strlen(rechnung) + 1);
        close(pipefd[1]);

        close(pipefd2[1]);

        read(pipefd2[0], &loesung, sizeof(loesung));

        printf("%d", loesung);

        close(pipefd2[0]);
    }

    return 0;
}
