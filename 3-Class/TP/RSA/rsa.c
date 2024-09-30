/*
File: rsa.c
Date: 22.06.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int mod_inverse(int e, int phi);
int gcd(int a, int b);
int mod_exp(int base, int exp, int mod);

int main() {
    char input_string[1024];
    char encrypted_string[1024];
    char decrypted_string[1024];
    int p, q, e, n, d, phi;

    printf("Enter the input string: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = 0;

    printf("Enter prime number p: ");
    scanf("%d", &p);
    printf("Enter prime number q: ");
    scanf("%d", &q);
    printf("Enter public exponent e: ");
    scanf("%d", &e);

    n = p * q;
    phi = (p - 1) * (q - 1);

    if (gcd(e, phi) != 1) {
        fprintf(stderr, "e and phi(n) are not coprime. Choose a different e.\n");
        return 1;
    }

    d = mod_inverse(e, phi);

    for (int i = 0; i < strlen(input_string); ++i) {
        int m = input_string[i];
        int c = mod_exp(m, e, n);
        encrypted_string[i] = (char)c;
    }
    encrypted_string[strlen(input_string)] = '\0';

    printf("Encrypted message: ");
    for (int i = 0; i < strlen(encrypted_string); ++i) {
        printf("%d", (int)encrypted_string[i]);
    }
    printf("\n");

    for (int i = 0; i < strlen(encrypted_string); ++i) {
        int c = encrypted_string[i];
        int m = mod_exp(c, d, n);
        decrypted_string[i] = (char)m;
    }
    decrypted_string[strlen(encrypted_string)] = '\0';

    printf("Decrypted string: %s\n", decrypted_string);

    return 0;
}

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int mod_inverse(int e, int phi) {
    int t = 0, new_t = 1;
    int r = phi, new_r = e;
    while (new_r != 0) {
        int quotient = r / new_r;
        int temp_t = new_t;
        new_t = t - quotient * new_t;
        t = temp_t;
        int temp_r = new_r;
        new_r = r - quotient * new_r;
        r = temp_r;
    }
    if (t < 0) t += phi;
    return t;
}