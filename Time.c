#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main() {
    int i;
    uint8_t digits[10]; // 10 cifre

    srand(time(NULL));  // seed RNG

    // Første ciffer skal ikke være 0
    digits[0] = (rand() % 9) + 1;

    // Resten af cifrene
    for (i = 1; i < 10; i++) {
        digits[i] = rand() % 10;
    }

    // Print tallet
    printf("Tilfældigt 18-cifret tal: ");
    for (i = 0; i < 10; i++) {
        printf("%d", digits[i]);
    }
    printf("\n");

    return 0;
}