#include <stdio.h>

int main()
{
    float einkpreis;
    float mehrwst;
    float aufschlag;
    float verkPreis;

    printf("Gebe den Einkaufspreis (€), die Mehrwertsteuer (Prozent) und den Aufschlag (Prozent) an\n");
    printf("-------------\n");
    scanf("%f %f %f", &einkpreis, &mehrwst, &aufschlag);

    mehrwst = einkpreis * (mehrwst / 100);
    aufschlag = einkpreis * (aufschlag / 100);
    verkPreis = (einkpreis + mehrwst + aufschlag);

    printf("Der Verkaufspreis ist %f", verkPreis);


    return 0;
}
