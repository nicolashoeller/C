/*
Autor: Nicolas Höller
File: arrayGleichheit.c
Date: 18.10.2023
*/

#include <stdio.h>

int main(){
    
    int array[2][10] =   {{1,2,3,4,5,6,7,8,9},
                        {1,2,3,4,5,6,7,8,8,9}};

    int count = 0;
    int count2 = 0;

    for (int k = 0; k < 9; k++)
    {
        if (array[2][k] == array[2][k+1])
        {
            count2++;
        }
        
    }
    
    count2--;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (array[0][i] == array[1][j])
            {
                count+=1;
            }
            
        }
        
    }

    count = count - count2;

    if (count == 9)
    {
        printf("Dein Array ist gleich");
    }
    else
    {
        printf("Dein Array ist nicht gleich");
    }

    return 0;
}