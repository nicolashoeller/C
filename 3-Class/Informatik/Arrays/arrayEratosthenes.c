/*
Autor: Nicolas Höller
File: eratosthenes.c
Date: 16.10.2023
*/

#include <stdio.h>

int main(){
    
    int begrenzer = 0;
    int zahlen[10000] = {0,1,2,3,5,7};

    printf("Gib deinen Begrenzer ein:\n");
    scanf("%d", &begrenzer);
    printf("\n-----------\n");

    for (int i = 2; i < begrenzer; i++)
    {   
        if (i%2==0 || i%3==0 || i%5==0 || i%7==0)
        {
            continue;
        }
        else
        {
            zahlen[i] = i;
            printf("%d\n", zahlen[i]);           
        }
        
    }   

    return 0;
}