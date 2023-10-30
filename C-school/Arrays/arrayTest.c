#include <stdio.h>

int main()
{
    int geilesArray[100] = {0};
    int eingabe = 0;
    int i = 0;

    printf("Gib eine Zahl ein dio cane!\n");
    scanf("%d", &eingabe);

    while (eingabe >= 1)
    {
        geilesArray[i] = eingabe%2;
        eingabe/=2;
        i++;
    }

    while (i >= 0)
    {
        printf("%d", geilesArray[i]);
        i--;
    }
    
    return 0;
}
