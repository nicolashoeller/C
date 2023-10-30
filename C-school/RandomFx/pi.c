/*
Autor: Nicolas Höller
File: pi.c
Date: 25.10.2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

int main()
{
    srand(time(NULL));

    long long achsenXY[2] = {0};
    int tropfenGesamt = 0;
    long long tropfenImKreis = 0;
    double hypothenuse = 0;

    printf("Wie viele Tropfen sollen erstellt werden? (min 100 | max 2.147.483.647)\n");
    printf("-----> ");
    scanf("%lld", &tropfenGesamt);

    if (tropfenGesamt >= 100)
    {
        for (int i = 0; i < tropfenGesamt; i++)
        {
            achsenXY[0] = rand() % RAND_MAX;
            achsenXY[1] = rand() % RAND_MAX;

            if (sqrt(achsenXY[0] * achsenXY[0] + achsenXY[1] * achsenXY[1]) <= RAND_MAX)
            {
                tropfenImKreis++;
            }
            else
            {
            }
        }

        printf("-------------\n");
        printf("Pi ist ~ %f", 4 * (double)tropfenImKreis / tropfenGesamt);
    }
    else
    {
        printf("Gib eine Zahl > 100 ein!");
    }

    return 0;
}