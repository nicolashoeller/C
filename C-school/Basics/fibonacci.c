#include <stdio.h>

int main()
{
    int array1[100] = {0, 1};
    int i = 0;
    int j = 1;
    int k = 2;
    int n = 0;
    int d = 0;

    printf("Gib eine Zahl ein\n");
    scanf("%d", &n);

    if(n == 1 || n <= 0){
        printf("Deine Zahl muss größer als 1 sein\n");
    }
    while (n > j)
    {
        d = i + j;
        i = j;
        j = d;
        array1[k] = j;
        k++;
    }
    for (int z = 0; z < k-1; z++)
    {
        printf("%d,", array1[z]);
    }

    return 0;
}
