#include <stdio.h>

int main()
{
    int eingabe = 0;
    int primz = 1;
    int i = 2;

    printf("\nGib deine Zahl ein: \n");
    printf("--------------\n");
    printf("-----> ");
    scanf("%d", &eingabe);
    printf("--------------\n");

    while (primz == 1 && (eingabe / 2) > i)
    {
        if (eingabe % i == 0) //Wenn Zahl teilbar ist
        {
            primz = 0; //Damit Schleife abgebrochen wird
            printf("Deine Zahl %d ist keine Primzahl", eingabe);
        }
        
        i++;

    }
    
    if (primz == 1) //Wenn Zahl nicht teilbar ist
    {
        printf("Deine Zahl %d ist eine Primzahl", eingabe);
    }
    
    return 0;
}