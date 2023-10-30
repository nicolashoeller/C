#include <stdio.h>

int main()
{
    int hoehe;
    int alter;
    printf("Wie groß ist der Baum: \n");
    scanf("%d", &hoehe);

    printf("Wie alt ist der Baum: \n");
    scanf("%d", &alter);

    printf("-------------\n");

    if (hoehe >= 20 && alter >= 70)
    {
        hoehe = hoehe - 20;
        alter = alter - 70;
        printf("Der Baum darf gefällt werden da er %d Meter zu groß und %d Jahre zu alt ist", hoehe, alter);
    }
    else if (hoehe >= 20 && alter <= 70)
    {
        printf("Der Baum darf nicht gefällt werden da er %d Jahre zu jung ist", alter);
    }
    else if (hoehe <= 20 && alter >= 70)
    {
        printf("Der Baum darf nicht gefällt werden da er %d Meter zu groß ist", hoehe);
    }
    else{
        hoehe = 20 - hoehe;
        alter = 70 - alter;
        printf("Der Baum darf nicht gefällt werden da er %d Meter zu klein und %d Jahre zu jung ist", hoehe, alter);
    }

    return 0;
}
