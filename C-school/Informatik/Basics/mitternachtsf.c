#include <stdio.h>
#include <math.h>

int main(){
    
    float x = 0;
    float x1 = 0;
    float a = 0;
    float b = 0;
    float c = 0;
    float d = 0;

    printf("Gebe a ein: ");
    scanf("%f", &a);

    printf("Gebe b ein: ");
    scanf("%f", &b);

    printf("Gebe c ein: ");
    scanf("%f", &c);
    
    printf("-------------------\n");    
    
    if (a != 0){

        d = (b*b)-(4*a*c);

        if (d < 0)
        {
            printf("Deine Funktion hat keinen Nullpunkt");
        }
        else{
            x = (-b+(sqrt((b*b)-(4*a*c))))/(2*a);

            printf("Dein erster Nullpunkt ist: %f\n", x);

            x = (-b-(sqrt((b*b)-(4*a*c))))/(2*a);

            printf("Dein zweiter Nullpunkt ist: %f\n", x);
        }    
    }
    else if (a == 0, c == 0){
        printf("Dein Nullpunkt ist: 0");
    }
    else if (a == 0){
        x = (c*-1)/b;
        printf("Dein Nullpunkt ist: %f", x);
    }
    
    return 0;
}