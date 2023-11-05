/*
Autor: Nicolas Höller
File: dnfUpgrade.c
Date: 15.10.2023
*/

#include <stdio.h>

int main()
{

    int werte[4][50] = {0};

    int auswahl = 0;
    int i = 0;
    int count = 0;

    // Auswahl KNF oder DNF
    printf("DNF == 1 | KNF == 2\n");
    printf("-----> ");
    scanf("%d", &auswahl);

    // DNF
    if (auswahl == 1)
    {
        printf("Wie viele Inputs soll dein Schaltkreis haben? (2 - 3)\n");
        printf("-----> ");
        scanf("%d", &auswahl);

        // Überprüft ob die Eingabe 2 ist
        if (auswahl == 2)
        {
            printf("\n\nGib deine Werte an (Abbrechen Zahl =! 0 oder != 1 eingeben)\n\n");

            while (1)
            {
                // Überprüft ob die angegebenen werde 1 || 0 sind
                printf("Gib a ein: ");
                scanf("%d", &werte[0][i]);
                if (werte[0][i] != 0 && werte[0][i] != 1)
                {
                    break;
                }
                printf("Gib b ein: ");
                scanf("%d", &werte[1][i]);
                printf("............\n");
                if (werte[1][i] != 0 && werte[1][i] != 1)
                {
                    break;
                }
                printf("Gib y ein: ");
                scanf("%d", &werte[2][i]);
                printf("------------\n");
                if (werte[2][i] != 0 && werte[2][i] != 1)
                {
                    break;
                }

                i++;
            }

            printf("\n\n-----------------\n\n");

            i--;

            // Auslesen der Zahlen und Umwandeln in verständliche Darstellung
            while (i >= 0)
            {
                // Ablesen ob y 1 ist da man sich bei DNF auf die 1 richtet
                if (werte[2][i] == 1)
                {
                    if (werte[0][i] == 0 && werte[1][i] == 0)
                    {
                        printf("(NOT A AND NOT B)");
                        // Wird benötigt damit am Ende nicht ein "OR" steht
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 0 && werte[1][i] == 1)
                    {
                        printf("(NOT A AND B)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 1 && werte[1][i] == 0)
                    {
                        printf("(A AND NOT B)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        printf("(A AND B)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                }
                i--;
            }
        }

        else if (auswahl == 3)
        {
            printf("\n\nGib deine Werte an (Abbrechen Zahl =! 0 oder != 1 eingeben)\n\n");

            while (1)
            {
                // Überprüft ob die angegebenen werde 1 || 0 sind
                printf("Gib a ein: ");
                scanf("%d", &werte[0][i]);
                if (werte[0][i] != 0 && werte[0][i] != 1)
                {
                    break;
                }
                printf("Gib b ein: ");
                scanf("%d", &werte[1][i]);
                if (werte[1][i] != 0 && werte[1][i] != 1)
                {
                    break;
                }
                printf("Gib c ein: ");
                scanf("%d", &werte[2][i]);
                printf("............\n");
                if (werte[2][i] != 0 && werte[2][i] != 1)
                {
                    break;
                }
                printf("Gib y ein: ");
                scanf("%d", &werte[3][i]);
                printf("------------\n");
                if (werte[3][i] != 0 && werte[3][i] != 1)
                {
                    break;
                }

                i++;
            }

            printf("\n\n-----------------\n\n");

            i--;

            while (i >= 0)
            {
                if (werte[3][i] == 1)
                {
                    if (werte[0][i] == 0 && werte[1][i] == 0 && werte[2][i] == 0)
                    {
                        printf("(NOT A AND NOT B AND NOT C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 0 && werte[1][i] == 0 && werte[2][i] == 1)
                    {
                        printf("(NOT A AND NOT B AND C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 0 && werte[1][i] == 1 && werte[2][i] == 0)
                    {
                        printf("(NOT A AND B AND NOT C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 0 && werte[1][i] == 1 && werte[2][i] == 1)
                    {
                        printf("(NOT A AND B AND C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 1 && werte[1][i] == 0 && werte[2][i] == 0)
                    {
                        printf("(A AND NOT B AND NOT C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 1 && werte[1][i] == 0 && werte[2][i] == 1)
                    {
                        printf("(A AND NOT B AND C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 1 && werte[1][i] == 1 && werte[2][i] == 0)
                    {
                        printf("(A AND B AND NOT C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        printf("(A AND B AND C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                }
                i--;
            }
        }

        // Abbruch des Programms wegen falscher eingabe
        else
        {
            printf("Deine Wertetabelle muss 2 - 3 Inputs haben\n");
        }
        return 0;
    }

    //--------------------------------------------------------------------------------

    // KNF
    if (auswahl == 2)
    {
        printf("Wie viele Inputs soll dein Schaltkreis haben? (2 - 3)\n");
        printf("-----> ");
        scanf("%d", &auswahl);

        // Überprüft ob die Eingabe 2 ist
        if (auswahl == 2)
        {
            printf("\n\nGib deine Werte an (Abbrechen Zahl =! 0 oder != 1 eingeben)\n\n");

            while (1)
            {
                // Überprüft ob die angegebenen werde 1 || 0 sind
                printf("Gib a ein: ");
                scanf("%d", &werte[0][i]);
                if (werte[0][i] != 0 && werte[0][i] != 1)
                {
                    break;
                }
                printf("Gib b ein: ");
                scanf("%d", &werte[1][i]);
                printf("............\n");
                if (werte[1][i] != 0 && werte[1][i] != 1)
                {
                    break;
                }
                printf("Gib y ein: ");
                scanf("%d", &werte[2][i]);
                printf("------------\n");
                if (werte[2][i] != 0 && werte[2][i] != 1)
                {
                    break;
                }

                i++;
            }

            printf("\n\n-----------------\n\n");

            i--;

            // Auslesen der Zahlen und Umwandeln in verständliche Darstellung
            while (i >= 0)
            {
                // Ablesen ob y 1 ist da man sich bei DNF auf die 1 richtet
                if (werte[3][i] == 0)
                {
                    if (werte[0][i] == 0 && werte[1][i] == 0)
                    {
                        printf("(A AND B)");
                        // Wird benötigt damit am Ende nicht ein "OR" steht
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 0 && werte[1][i] == 1)
                    {
                        printf("(A AND NOT B)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 1 && werte[1][i] == 0)
                    {
                        printf("(NOT A AND B)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        printf("(NOT A AND NOT B)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                }
                i--;
            }
        }

        else if (auswahl == 3)
        {
            printf("\n\nGib deine Werte an (Abbrechen Zahl =! 0 oder != 1 eingeben)\n\n");

            while (1)
            {
                // Überprüft ob die angegebenen werde 1 || 0 sind

                printf("Gib a ein: ");
                scanf("%d", &werte[0][i]);
                if (werte[0][i] != 0 && werte[0][i] != 1)
                {
                    break;
                }
                printf("Gib b ein: ");
                scanf("%d", &werte[1][i]);
                if (werte[1][i] != 0 && werte[1][i] != 1)
                {
                    break;
                }
                printf("Gib c ein: ");
                scanf("%d", &werte[2][i]);
                printf("............\n");
                if (werte[2][i] != 0 && werte[2][i] != 1)
                {
                    break;
                }
                printf("Gib y ein: ");
                scanf("%d", &werte[3][i]);
                printf("------------\n");
                if (werte[3][i] != 0 && werte[3][i] != 1)
                {
                    break;
                }

                i++;
            }

            printf("\n\n-----------------\n\n");

            i--;

            while (i >= 0)
            {
                if (werte[3][i] == 0)
                {
                    if (werte[0][i] == 0 && werte[1][i] == 0 && werte[2][i] == 0)
                    {
                        printf("(A AND B AND C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 0 && werte[1][i] == 0 && werte[2][i] == 1)
                    {
                        printf("(A AND B AND NOT C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 0 && werte[1][i] == 1 && werte[2][i] == 0)
                    {
                        printf("(A AND NOT B AND C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 0 && werte[1][i] == 1 && werte[2][i] == 1)
                    {
                        printf("(A AND NOT B AND NOT C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 1 && werte[1][i] == 0 && werte[2][i] == 0)
                    {
                        printf("(NOT A AND B AND C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 1 && werte[1][i] == 0 && werte[2][i] == 1)
                    {
                        printf("(NOT A AND B AND NOT C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else if (werte[0][i] == 1 && werte[1][i] == 1 && werte[2][i] == 0)
                    {
                        printf("(NOT A AND NOT B AND C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        printf("(NOT A AND NOT B AND NOT C)");
                        if (i > 0)
                        {
                            printf(" OR ");
                        }
                        else
                        {
                        }
                    }
                }
                i--;
            }
        }

        // Abbruch des Programms wegen falscher eingabe
        else
        {
            printf("Deine Wertetabelle muss 2 - 3 Inputs haben\n");
        }
    }

    return 0;

    // Abbruch
    if (auswahl != 1 && auswahl != 2)
    {
        printf("Gib 1 (Für DNF) oder 2 (Für KNF) ein");
    }

    return 0;
}