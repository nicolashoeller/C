/*
File: selfWrittenProgram.c
Date: 05.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen("HelloWorld.c", "w");

    if (file == NULL)
    {
        printf("Beim öffnen der Datei ist ein Fehler aufgetreten!");
        return -1;
    }

    fprintf(file, "#include <stdio.h>\nint main() {printf(\"Hello World\");return 0;}");
    fclose(file);

    int id = fork();
    if (id == 0)
    {
        id = fork();

        if (id == 0)
        {
            char *args[] = {"gcc", "HelloWorld.c", "-o", "HelloWorld", NULL};
            execvp("gcc", args);

            perror("Failed to compile");
        }
        else
        {
            wait(NULL);
            char *args2[] = {"./HelloWorld", NULL};
            execvp(args2[0], args2);

            perror("Failed to run");
        }
    }
    else
    {
        wait(NULL);
        printf("\nTschüdelü");
    }

    return 0;
}