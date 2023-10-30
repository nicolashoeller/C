#include <stdio.h>
#include <math.h>

int main(){
    
    float a = 0;
    float b = 0;
    float c = 0;

    printf("Gebe eine beliebige Zahl ein: ");
    scanf("%f", &a);

    printf("Gebe eine weitere Zahl ein: ");
    scanf("%f", &b);

    printf("Gebe eine weitere Zahl ein: ");
    scanf("%f", &c);

    printf("---------------\n");

    if (a > b && a > c)
    {
        if (b > c)
        {
            printf("%f ist die größte zahl", a);
            printf("%f ist die zweit größte Zahl", b);
            printf("%f ist die kleinste Zahl", c);
        }
    }
    else{
        if (b > a && b > c)
        {
            if (a > c)
            {
                printf("%f ist die größte zahl", b);
                printf("%f ist die zweit größte Zahl", a);
                printf("%f ist die kleinste Zahl", c);
            }
            else{
                printf("%f ist die größte zahl", b);
                printf("%f ist die zweit größte Zahl", c);
                printf("%f ist die kleinste Zahl", a);
            }
            
        }
        
    }
    
    
    

    return 0;
}
