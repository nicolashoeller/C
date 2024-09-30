/*
Autor: Nicolas Höller
Datum: 25.09.2023
*/

#include <stdio.h>

int main()
{
    int dezizahl;

    printf("Gib eine Zahl ein die umgewandelt werden soll:\n");
    scanf("%d", &dezizahl);
    printf("---------------------------------------------------------------------------------------------------\n");

    while (dezizahl >= 1)
    {   
        printf("%d\t\t : \t\t2\t\t = \t\t%d\t\t|\t\t%d\n", dezizahl, dezizahl / 2, dezizahl % 2);
        dezizahl = dezizahl / 2;
    }

    return 0;
}