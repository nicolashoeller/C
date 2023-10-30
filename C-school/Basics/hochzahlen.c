#include <stdio.h>
#include <math.h>

int main()
{
    int eing1, eing2, erg, erg2;
    int i = 0;

    printf("Gib deine Basis ein:\n");
    scanf("%d", &eing1);
    printf("Gib deinen Exponenten ein:\n");
    scanf("%d", &eing2);

    if (eing1 != 0 && eing2 == 0)
    {
        printf("Ihr Ergebnis ist 1");
        return 0;
    }
    if (eing1 == 0 && eing2 != 0)
    {
        printf("Ihre Eingabe ist 0");
        return 0;
    }
    if (eing1 == 0 && eing2 == 0)
    {
        printf("Ihre Eingabe ist undefiniert");
    }
    
    if (eing1 != 0 && eing2 != 0)
    {
        while (eing2 > i)
        {
            erg = eing1 * eing1;
            erg+= erg2;
            i++;
        }
    }
    

    printf("%d", erg);
    return 0;
}
