#include<stdio.h>
#include<math.h>

int main(){
    long long dezim;
    int rest, a, nuller, einser, zweier, dreier, vierer, fuenfer, sechser, siebener, achter, neuner;
    char x;
    a=0;
    einser=0;
    zweier=0;
    dreier=0;
    vierer=0;
    fuenfer=0;
    sechser=0;
    siebener=0;
    achter=0;
    neuner=0;
    nuller=0;
    x='#';
    printf("Gib eine Zahl ein!\n");
    scanf("%lld", &dezim);

    while(dezim>0){ 
        rest = dezim % 10;
        dezim = dezim/10; 
                switch (rest){
                    case 0: nuller=nuller+1;break;
                    case 1: einser=einser+1;break;
                    case 2: zweier=zweier+1;break;
                    case 3: dreier=dreier+1;break;
                    case 4: vierer=vierer+1;break;
                    case 5: vierer=vierer+1;break;
                    case 6: sechser=sechser+1;break;
                    case 7: siebener=siebener+1;break;
                    case 8: achter=achter+1;break;
                    case 9: neuner=neuner+1;break;
                } 
    }
    printf("1|");
    while(nuller>0){
        printf("%c", x);
        nuller=nuller-1;
    }
    printf("\n1|");
   while(einser>0){
        printf("%c", x);
        einser=einser-1;
    }
    printf("\n2|");
   while(zweier>0){
        printf("%c", x);
        zweier=zweier-1;
    }
    printf("\n3|");
   while(dreier>0){
        printf("%c", x);
        dreier=dreier-1;
    }
    printf("\n4|");
   while(vierer>0){
        printf("%c", x);
        vierer=vierer-1;
    }
    printf("\n5|");
   while(fuenfer>0){
        printf("%c", x);
        fuenfer=fuenfer-1;
    }
    printf("\n6|");
   while(sechser>0){
        printf("%c", x);
        sechser=sechser-1;
    }
    printf("\n7|");
   while(siebener>0){
        printf("%c", x);
        siebener=siebener-1;
    }
    printf("\n8|");
   while(achter>0){
        printf("%c", x);
        achter=achter-1;
    }
    printf("\n9|");
   while(neuner>0){
        printf("%c", x);
        neuner=neuner-1;
    }
    printf("\n");
    return'0';
}
