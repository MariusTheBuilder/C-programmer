 
//Diffie Hellman key exchange.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

uint64_t modular_multiply(uint64_t a, uint64_t b, uint64_t mod);
uint64_t modular_pow(uint64_t generator, uint64_t hidden_num, uint64_t prime_number);

//a = a temporary value inside the exponentiation process
//b = a temporary value inside the exponentiation process
//mod = prime number

//Modular multiplicering
uint64_t modular_multiply(uint64_t a, uint64_t b, uint64_t prime_number){
  uint64_t result = 0;
    a %= prime_number; // a = a % prime_number; == 27 mod 10 = 7 == 27 and 7 are the same value to keep numbers small.

    while (b > 0) //Loop continues while there are still bits left in b.
    {
        if (b & 1) { // Binary multiplication Checks if the lowest bit of b is 1. 1 = add current a. 0 = skip addition.


          //(result + a) % prime_number -- but overflow proof.
            // Hvis resultatet + a overstiger prime_number, laver vi result + a - prime_number (modulo)
            
            if (result >= prime_number - a) // Dette holder result i intervallet [0, prime_number-1].
                result = result + a - prime_number;
            else
                result += a;
        }

        // a = (a * 2) % prime_number -- but overflow proof.
        if (a >= prime_number - a)
            a = a * 2 - prime_number;
        else
            a = a * 2;

        b >>= 1;
    }

    return result; // (a * b) % prime_number
}

//Modular exponentiation (square-and-multiply)
//Returns: (generator^hidden_num) % prime_number
uint64_t modular_pow(uint64_t generator, uint64_t hidden_num, uint64_t prime_number){
  uint64_t result = 1;
  generator %= prime_number; // = 3 

  // Loop runs until all bits of the exponent (hidden_num) are processed.
  while (hidden_num > 0)
  {
    if (hidden_num & 1) // If the lowest bit is 1 (ulige tal), multiply result by the current base (or skip if 0).
                        //and square the generator base before moving on to next bit with "">>= 1"
        result = modular_multiply(result, generator, prime_number);        //multiply
        
    generator = modular_multiply(generator, generator, prime_number);  //square
    hidden_num >>= 1; 
  }

  return result;
}


int main(void){
  uint64_t prime_number = 429496731142949673ULL;    //prime_number → the prime modulus p
  uint64_t generator = 3ULL;                        //generator → the number you are raising to a power.
  uint64_t hidden_num;                              //hidden_num → the exponent (your private key a).
  
  
  printf("\nInput private key: ");
  scanf("%llu", &hidden_num);

  // Resultatet af "modular_pow" bliver til "public_key"
  uint64_t public_key = modular_pow(generator, hidden_num, prime_number);

    printf("Prime number:            %llu\n", prime_number);
    printf("Generator:               %llu\n", generator);
    printf("Public key:              %llu\n", public_key);


    // 
    printf("\nInput the other person's public key: ");
    scanf("%llu", &public_key);

    uint64_t secret_key = modular_pow(public_key, hidden_num, prime_number);

    printf("Shared secret key: %llu\n", secret_key);
    return 0;
}


// uint64_t HP1 = 640122435421194110;      Public: 208347560710223328
// uint64_t HP2 = 883145891446335899;      Public: 330132355905543021
// secret key: 7068530040918966