/*
File: bruch_addieren.c
Date: 23.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

struct bruch
{
    int num1;
    int num2;
};

typedef struct bruch Bruch;

Bruch ergebnis(Bruch bruch1, Bruch bruch2);

int main(int argc, char* argv[])
{
    if(argc != 5){
        printf("Gib zwei Brüche an! Format: num1 num2 num3 num4");
        return -1;
    }

    Bruch bruch1;
    Bruch bruch2;

    bruch1.num1 = atoi(argv[1]);
    bruch1.num2 = atoi(argv[2]);

    bruch2.num1 = atoi(argv[3]);
    bruch2.num2 = atoi(argv[4]);

    Bruch end = ergebnis(bruch1, bruch2);

    printf("%d/%d", end.num1, end.num2);

    return 0;
}

Bruch ergebnis(Bruch bruch1, Bruch bruch2){
    Bruch end;
    
    end.num2 = bruch1.num2 * bruch2.num2;
    end.num1 = bruch1.num1 * end.num2 + bruch2.num1 * end.num2;

    return end;
}