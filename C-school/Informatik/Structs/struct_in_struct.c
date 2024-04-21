/*
File: struct_in_struct.c
Date: 21.04.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

struct innerS1
{
    int num1;
    int num2;
};

struct innerS2
{
    int num3;
    int num4;
};

struct outerS
{
    struct innerS1 innerS1;
    struct innerS2 innerS2;
    
};

typedef struct innerS1 innerS1;
typedef struct innerS2 innerS2;
typedef struct outerS outerS;


int main(int argc, char* argv[]){
    outerS outer1 = {
        {10,20},
        {20,30}
    };

    printf("%d, %d\n", outer1.innerS1.num1, outer1.innerS1.num2);
    printf("%d, %d\n", outer1.innerS2.num3, outer1.innerS2.num4);

    return 0;
}