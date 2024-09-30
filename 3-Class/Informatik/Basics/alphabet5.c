#include <stdio.h>

int main()
{
    char a;
    printf("Gib ein Symbol ein\n");
    scanf("%c", &a);
    printf("--------------\n");

    if (a >= 'a' && a <= 'z')
    {
        printf("Dein Symbol ist im Alphabet und ist ein Kleinbuchstabe");
    }
    else if (a >= 'A' && a <= 'Z')
    {
        printf("Dein Symbol ist im Alphabet und ist ein Großbuchstabe");
    }
    else
    {
        printf("Dein Symbol ist nicht im Alphabet");
    }
    
    return 0;

}
