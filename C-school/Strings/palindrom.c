#include <stdio.h>
#include <string.h>
#include <ctype.h>

int istPalindrom(char*);

int main() {
    char str[100];

    printf("Gib einen String ein: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (istPalindrom(str)) {
        printf("%s ist ein Palindrom.\n", str);
    } else {
        printf("%s ist kein Palindrom.\n", str);
    }

    return 0;
}

int istPalindrom(char *str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {

        while (i < j && !isalnum(str[i])) {
            i++;
        }
        while (i < j && !isalnum(str[j])) {
            j--;
        }

        if (tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
    }

    return 1;
}