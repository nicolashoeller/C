/*
File: signal_4.c
Date: 04.10.2024
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

int *stop_timer_signal;
int *is_resetted;
int *active_signal_stop;
int *seconds;

void handle_restart_timer(int sig)
{
    *seconds = 30;
    *is_resetted = 1;
}

void handle_stop_timer(int sig)
{
    (*active_signal_stop)++;
    *stop_timer_signal = 1;
}

void handle_resume_timer(int sig)
{
    *stop_timer_signal = 0;
}

void busy_wait(int n_seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < n_seconds);
}

int main(int argc, char *argv[])
{
    int shm_id = shmget(IPC_PRIVATE, sizeof(int) * 4, IPC_CREAT | 0666);
    if (shm_id < 0)
    {
        perror("shmget");
        exit(1);
    }

    int *shared_memory = (int *)shmat(shm_id, NULL, 0);
    if (shared_memory == (int *)-1)
    {
        perror("shmat");
        exit(1);
    }

    stop_timer_signal = &shared_memory[0];
    is_resetted = &shared_memory[1];
    active_signal_stop = &shared_memory[2];
    seconds = &shared_memory[3];

    *stop_timer_signal = 0;
    *is_resetted = 0;
    *active_signal_stop = 0;
    *seconds = 30;

    signal(SIGINT, handle_restart_timer);
    signal(SIGUSR1, handle_stop_timer);
    signal(SIGUSR2, handle_resume_timer);

    srand(time(NULL));

    time_t setTime = time(NULL);
    time_t setTimeTemp = setTime;

    while (time(NULL) - setTime <= 5)
    {
        printf("Seconds %d\n", *seconds);
        busy_wait(1);
        (*seconds)--;
    }

    int pid = fork();

    if (pid == 0)
    {
        int pid2 = fork();

        if (pid2 == 0)
        {
            setTimeTemp = time(NULL);

            while (!*is_resetted && *seconds != 0)
            {
                busy_wait(1);
                if (rand() % 6 == 5)
                {
                    kill(getppid(), SIGINT);
                    printf("Signal SIGINT sent!\n");
                }
            }
            exit(0);
        }
        else
        {
            int pid3 = fork();

            if (pid3 == 0)
            {
                setTimeTemp = time(NULL);
                while (*active_signal_stop <= 3 && *seconds != 0)
                {
                    busy_wait(1);
                    if (rand() % 6 == 5 && *stop_timer_signal == 0)
                    {
                        kill(getppid(), SIGUSR1);
                        printf("Signal SIGUSR1 sent!\n");
                    }
                }
                exit(0);
            }
            else
            {
                while (*active_signal_stop <= 3 && *seconds != 0)
                {
                    while (*stop_timer_signal == 0);
                    busy_wait(4);
                    kill(getppid(), SIGUSR2);
                    printf("Signal SIGUSR2 sent!\n");
                }
                exit(0);
            }
        }
    }
    else
    {
        while (*seconds >= 0)
        {
            printf("Seconds %d\n", *seconds);
            while (*stop_timer_signal);
            busy_wait(1);
            (*seconds)--;
        }

        wait(NULL);

        shmdt(shared_memory);
        shmctl(shm_id, IPC_RMID, NULL);
    }

    return 0;
}
