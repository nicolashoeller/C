/*
File: fakultät.c
Date: 11.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>

unsigned long long factorial(int n);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
    } else {
        printf("Factorial of %d = %llu\n", num, factorial(num));
    }

    return 0;
}

// Recursive function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}