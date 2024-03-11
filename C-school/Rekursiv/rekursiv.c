/*
File: rekursiv.c
Date: 11.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

int i = 0;

void hallo()
{
    printf("Hallo Welt! %d\n", i);
    i++;
    hallo();
}

int main(int argc, char* argv[])
{
    hallo();
    return 0;
}