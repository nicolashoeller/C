#include <stdio.h>
#include <math.h>

int main() {
    int x, y, x1, y1, x2, y2;
    int xDiff, yDiff, x1Diff, y1Diff;
    float z, z1;

    printf("Geben Sie x ein: ");
    scanf("%d", &x);

    printf("Geben Sie y ein: ");
    scanf("%d", &y);

    printf("Geben Sie x1 ein: ");
    scanf("%d", &x1);

    printf("Geben Sie y1 ein: ");
    scanf("%d", &y1);

    printf("Geben Sie x2 ein: ");
    scanf("%d", &x2);

    printf("Geben Sie y2 ein: ");
    scanf("%d", &y2);

    xDiff = x - x1;
    yDiff = y - y1;

    x1Diff = x1 - x2;
    y1Diff = y1 - y2;

    z = sqrt(yDiff * yDiff + xDiff * xDiff);
    z1 = sqrt(y1Diff * y1Diff + x1Diff * x1Diff);

    z = z + z1;

    printf("%f", z);

    return 0;
}
