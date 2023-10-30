#include <stdio.h>
#include <math.h>

int main(){
    
    //Initialisierung der Variablen
    int auswahl = 0;
    int wertanzahl = 0;
    int i = 0;
    int count = 0;
    
    int a[21] = {0};
    int b[21] = {0};
    int y[21] = {0};

    //Auswahl KNF oder DNF
    printf("DNF == 1 | KNF == 2\n");
    printf("-----> ");
    scanf("%d", &auswahl);

    //DNF
    if (auswahl == 1)
    {
        printf("Wie viele Inputs soll dein Schaltkreis haben? (2 - 3)\n");
        printf("-----> ");
        scanf("%d", &wertanzahl);

        if (wertanzahl == 2)
        {
            //Prüft ob die angegebenen Zahlen 0 oder 1 sind
            //Abbruchbedingung
            while ((a[i] == 0 || a[i] == 1) && (b[i] == 0 || b[i] == 1) && (y[i] == 0 || y[i] == 1))
            {
                i++;
                printf("Gib a ein: ");
                scanf("%d", &a[i]);
                printf("Gib b ein: ");
                scanf("%d", &b[i]);
                printf("Gib y ein: ");
                scanf("%d", &y[i]);

            }

            printf("\n\n------------\n\n");

            i--;
            while (i >= 0)
            {
                if (y[i] == 1)
                {
                    if (a[i] == 1 && b[i] == 1)
                    {
                        printf("(A AND B) OR ");
                    }
                    else if (a[i] == 1 && b[i] == 0)
                    {
                        printf("(A AND NOT A) OR ");
                    }
                    else if (a[i] == 0 && b[i] == 1)
                    {
                        printf("(NOT A AND B) OR ");
                    }
                    else{
                        printf("(NOT A AND NOT B) OR ");
                    }                             
                } 
                i--;
            }
            

            while (i > 0)
            {
                printf("%d\n", a[i]);
                printf("%d\n", b[i]);
                printf("%d\n", y[i]);
                i--;
            }
            
            
            
            return 0;
        }

        if (wertanzahl == 3)
        {

            return 0;
        }

        //Abbruch des Programm wegen falscher Benutung
        if (wertanzahl != 2 && wertanzahl != 3)
        {
            printf("Deine Wertetabelle muss 2 - 3 Inputs haben\n");
            return 0;
        }
        
    }

    //KNF
    if (auswahl == 2)
    {
        printf("Wie viele Inputs soll dein Schaltkreis haben? (2 - 3)\n");
        scanf("%d", &wertanzahl);

        if (wertanzahl == 2)
        {
            
            return 0;
        }
        if (wertanzahl == 3)
        {

            return 0;
        }

        //Abbruch des Programm wegen falscher Benutung
        if (wertanzahl != 2 && wertanzahl != 3)
        {
            printf("Deine Wertetabelle muss 2 - 3 Inputs haben\n");
            return 0;
        }
        
    }

    return 0;
}
