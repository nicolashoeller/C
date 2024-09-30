#include <stdio.h>

int main()
{
    int x;

    if(x<=6 && x>=4){
        printf("\n Inside Intervall one");
    }
    
    if((x>=0&&x<=2) || (x>=4 && x<=10)){
        printf("\n Inside Intervall two");
    }

    if(x<=(-1) || x>=1){
        printf("\n Inside Intervall three");
    }
    
    if((x<=(-4)) || (x>=0 && x<=2) || x>=4){
        printf("\n Inside Intervall four");
    }

    return 0;
}
