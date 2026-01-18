//Opgaven: Læsningaf personkartotek i komma-separeret tekstfil

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LGT 50

  struct person{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
  };
    typedef struct person person;

void indlaas_fil(FILE *f, person k[], int length);


int main(void){
    
    person kartotek[9];

    FILE *f = fopen("personkartotek.txt", "r");
    
    if(f == NULL){
        printf("Filen kan ikke aabnes!");
        exit(EXIT_FAILURE);
    }

    indlaas_fil(f, kartotek, 9);
    fclose(f);


    return 0;
}


void indlaas_fil(FILE *f, person k[], int length){
    
  for(int i = 0; i < length; i++){
      person p;
fscanf(f, "%[A-Za-z] %[A-Za-z], %[^0-9] %d, %d %[A-Za-z].\n", p.fornavn, p.efternavn, p.vejnavn, &p.vejnummer, &p.postnummer, p.bynavn);      
      printf("%s: %s %s %d %d %s\n", p.fornavn, p.efternavn, p.vejnavn, p.vejnummer, p.postnummer, p.bynavn);
  }
}