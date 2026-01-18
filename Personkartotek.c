//  qsort og person_comp virker ikke rigtigt........

// opgave: Læsning af personkartotek i komma-separeret tekstfil

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LGT 50

struct person
{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
};

typedef struct person person;

void indlaas_fil(FILE *f, person k[], int length);

void sorter_kartotek(FILE *f2, person k[], int lenght);

int person_comp(const void *a, const void *b);

int main(void)
{

    person kartotek[9];

    FILE *f = fopen("personkartotek.txt", "r");

    if (f == NULL){
        printf("Filen kan ikke aabnes!");
        exit(EXIT_FAILURE);
    }

    indlaas_fil(f, kartotek, 9);

    fclose(f);

    FILE *f2 = fopen("blank.txt", "w");
    if (f2 == NULL){
        printf("Filen kan ikke aabnes!");
        exit(EXIT_FAILURE);
    }

    sorter_kartotek(f2, kartotek, 9);

    fclose(f2);

    return 0;
}

void sorter_kartotek(FILE *f2, person k[], int length)
{

    qsort(k, length, sizeof(person), person_comp);

    for (int i = 0; i < length; i++)
    {
        fprintf(f2, "%s, %s, %s, %d, %d, %s\n",
                k[i].fornavn,
                k[i].efternavn,
                k[i].vejnavn,
                k[i].vejnummer,
                k[i].postnummer,
                k[i].bynavn);
    }
}

int person_comp(const void *a, const void *b)
{
    const person *p1 = (const person *)a;
    const person *p2 = (const person *)b;

    return strcmp(p1->efternavn, p2->efternavn);
}

void indlaas_fil(FILE *f, person k[], int length)
{

    for (int i = 0; i < length; i++)
    {
        person p;
        fscanf(f, "%[A-Za-z] %[A-Za-z], %[^0-9] %d, %d %[A-Za-z].\n", p.fornavn, p.efternavn, p.vejnavn, &p.vejnummer, &p.postnummer, p.bynavn);

        printf("%s: %s %s %d %d %s\n", p.fornavn, p.efternavn, p.vejnavn, p.vejnummer, p.postnummer, p.bynavn);
    }
}