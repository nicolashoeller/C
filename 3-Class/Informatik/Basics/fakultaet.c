#include <stdio.h>

int main ()
{
	int eingabe, b;
    
    printf("\nGib eine Zahl ein bei der die Fakultaet berechnet werden soll:\n");
    printf("-----> ");
	scanf("%d",&eingabe);

    b = eingabe;

    if (eingabe > 0)
    {
        while (b > 2)
        {
            b--;
            eingabe *= b;
        }
        
        printf("Die Fakultaet Ihrer Zahl ist %d", eingabe);
    }
    else if (eingabe < 0)
    {
        printf("Die Fakultaet Ihrer Zahl ist nicht definiert");
    }
    else{
        printf("Die Fakultaet Ihrer Zahl ist 1");
    }
    
	return 0;
}