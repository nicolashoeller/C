#include <stdio.h>
#include <math.h>

int main()
{
    float seitenl1;
    float seitenl2;
    float berechnungen;

    printf("Gebe zwei Seitenlängen eines Rechteckt a und b an (Kommazahlen erlaubt)\n");
    printf("--------------\n");
    scanf("%f %f", &seitenl1, &seitenl2);
    printf("--------------\n");

    berechnungen = seitenl1 * seitenl2;
    printf("Die Fläche ist %f\n", berechnungen);

    berechnungen = 2 * seitenl1 + 2 * seitenl2;
    printf("Der Umfang ist %f\n", berechnungen);

    berechnungen = sqrt(seitenl1 * seitenl1 + seitenl2 * seitenl2);
    printf("Die Diagonale ist %f lang\n", berechnungen);

    return 0;
}
