#include <stdio.h>

int main()
{
    int a, b, c, x;
    printf("\nGebe drei natürliche Zahlen ein. \n"); //inputs
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    printf("----------------\n");

    x = 0; 
    if(b>=c){ 
        x = b;
    }else
    {
        x = c;
    }

    if(a>=x){
        printf("Groeßte Zahl: %d", a);
        printf("\n Mittlere Zahl %d", x);
        if(x!=c){
            printf("\n Kleinste Zahl %d", c);
        }
        else{
            printf("\n Kleinste Zahl %d", b);
        }
                
    }
    else{
        if(a>x){
            printf("\n Groeßte Zahl: %d", a);
            printf("\n Mittlere Zahl %d", x);
            if(x!=c){
                printf("\n Kleinste Zahl %d", c);
            }
            else{
                printf("\n Kleinste Zahl %d", b);
            }

        } else
        {
            printf("\n Groeßte Zahl: %d", x);
            if(x==c){
                if(a>=b){
                    printf("\n Mittlere Zahl %d", a);
                    printf("\n Kleinste Zahl %d", b);
                }
                else if(b>a){
                    printf("\n Mittlere Zahl %d", b);
                    printf("\n Kleinste Zahl %d", a);
                }
            }
            else
            {
                if(x==b){ 
                    if(a>=c){
                        printf("\n Mittlere Zahl %d", a);
                        printf("\n Kleinste Zahl %d", c);
                    }
                    else if(c>a){
                        printf("\n Mittlere Zahl %d", c);
                        printf("\n Kleinste Zahl %d", a);
                    }
                }
            }
   
        }            
    }
    return 0;
}
