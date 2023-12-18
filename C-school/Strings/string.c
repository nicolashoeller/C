/*
File: string.c
Date: 18.12.2023
Autor: Nicolas Höller
*/

#include <stdio.h>

int calculate(char*);

int main(){
    char string[] = "Hello World!";
    
    int result = calculate(string);

    printf("%d", result);

    return 0;
}

int calculate(char* string){
    int length = 0;
    
    for (int i = 0; string[i] != '\0'; i++) {
        length++;
    }

    return length;
}