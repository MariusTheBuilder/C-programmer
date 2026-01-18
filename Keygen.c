//Diffie Hellman key exchange.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

uint64_t modular_multiply(uint64_t a, uint64_t b, uint64_t mod);
uint64_t modular_pow(uint64_t generator, uint64_t secret_key, uint64_t prime_number);



uint64_t modular_multiply(uint64_t a, uint64_t b, uint64_t prime_number) {
    return (a * b) % prime_number;
}



// Binary exponentiation.
uint64_t modular_pow(uint64_t generator, uint64_t secret_key, uint64_t prime_number) {
    uint64_t result = 1;
    int iteration = 1;
    generator %= prime_number; // sikrer at generator er inden for modulus, hvlket beskytter mod overflow. (Vores har ikke brug for det tho)
    
    while (secret_key > 0) {
        if (secret_key & 1)
            result = modular_multiply(result, generator, prime_number);   // simple multiply

        generator = modular_multiply(generator, generator, prime_number); // simple square - after each loop, generator, g, becomes g^(2^i) mod p, where i = iteration number.
         printf("\nIt:     %d\n", iteration);
        printf("Result:     %llu\n",result);
        printf("Generator:  %llu\n",generator);
        printf("Secret_key: %llu\n",secret_key);
        printf("LSB:        %llu\n", secret_key & 1);
        secret_key >>= 1; //(divider med 2 og rund ned til helt tal) 1234567890 / 2 = 617283945
    iteration ++;
    }
    return result;
}


int main(void) {
    uint64_t prime_number = 2147483647; //prime_number → the prime modulus p (Park-Miller kompatibelt primtal)
    uint64_t generator = 7;             //generator → the number you are raising to a power.
    uint64_t secret_key;                   //hidden_num → the exponent (your private key a).


    printf("\nEnter your private key: ");
    scanf("%llu", &secret_key);

    // Resultatet af "modular_pow" bliver til "public_key"
    uint64_t public_key = modular_pow(generator, secret_key, prime_number);

    //printf("Prime:       %llu\n", prime_number);
    //printf("Generator:   %llu\n", generator);
    printf("Public key:  %llu\n", public_key);


    // Den anden bruger sender deres egen public key, som bruges i modular_pow til at lave deres shared key.
    printf("\nInput the other person's public key: ");
    scanf("%llu", &public_key);

    uint64_t shared_key = modular_pow(public_key, secret_key, prime_number);

    printf("Shared secret key: %llu\n", shared_key);
    return 0;
}


// uint64_t HP1 = 7471224351;      Public: 1740460175
// uint64_t HP2 = 4211947105;      Public: 1548806232
// secret key: 1279462954