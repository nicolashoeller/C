/*
File: malloc.c
Date: 08.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

int str_length(char* string);
char* concat(char *string1, char *string2);

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Bitte geben Sie mindestens zwei Argumente ein.\n");
        return 1;
    }

    char* result = argv[1];
    for (int i = 2; i < argc; i++) {
        char* temp = concat(result, argv[i]);
        if (i < 2){
            free(result);
        }
        result = temp;
    }

    printf("%s\n", result);
    free(result);

    return 0;
}

int str_length(char* string){
    int length = 0;
    int i = 0;
    while (string[i] != '\0'){
        length++;
        i++;
    }

    return length;
}

char* concat(char *string1, char *string2) {
    int length1 = str_length(string1);
    int length2 = str_length(string2);

    char* result = malloc((length1 + length2 + 2) * sizeof(char));
    if (result == NULL) {
        printf("Speicher konnte nicht reserviert werden.\n");
        exit(0);
    }

    int i = 0;
    for (i ; i < length1; i++) {
        result[i] = string1[i];
    }

    result[i] = ' '; 
    i++;

    for (int j = 0; j < length2; j++, i++) {
        result[i] = string2[j];
    }

    result[i] = '\0';

    return result;
}