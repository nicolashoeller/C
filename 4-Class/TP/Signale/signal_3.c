/*
File: signal_3.c
Date: 23.09.2024
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
#include <time.h>

int signal_received = 0;

void handle_response(int sig)
{
    signal_received = 1;
}

int main(int argc, char *argv[])
{
    signal(SIGINT, handle_response);

    int pipefd[2];
    int pipefd2[2];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd2) == -1)
    {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    int pid = fork();

    int second = 0;
    if (pid == 0)
    {
        close(pipefd[1]);
        close(pipefd2[0]);
        char message[256];
        char response[256];
        int readSecond;
        int readSetTime;
        while (1)
        {
            while(!signal_received);
            read(pipefd[0], message, sizeof(message));
            printf("%s", message);

            sscanf(message, "Zeitstempel %ld %d Sekunde", &readSetTime, &readSecond);

            snprintf(response, sizeof(response), "Nachricht erhalten");
            write(pipefd2[1], response, strlen(response) + 1);
            kill(getppid(), SIGINT);

            if(readSecond == 10) {
                printf("Erledigt für Sekunde (%d)\n", readSecond);
            }

        }
        close(pipefd[0]);
        close(pipefd[1]);
    }
    else {
        close(pipefd[0]);
        close(pipefd2[1]);
        while (1)
        {
            time_t setTime = time(NULL);

            char message[256];
            char response[256];
            snprintf(message, sizeof(message), "Zeitstempel %ld %d Sekunde", setTime, second);
            for (int i = 0; i < second; i++)
            {
                strcat(message, ".");
            }
            strcat(message, "\n");

            write(pipefd[1], message, strlen(message) + 1);
            kill(pid, SIGINT);

            while (!signal_received);

            read(pipefd2[0], response, sizeof(response));
            printf("Kindprozess antwortet: %s\n", response);
            while (time(NULL) - setTime != 1);

            if (second >= 10)
            {
                kill(pid, SIGKILL);
                kill(getpid(), SIGKILL);
            }
            
            second++;
        }
        close(pipefd[1]);
        close(pipefd2[0]);
    }

    return 0;
}