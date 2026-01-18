#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *endelse(char ord[]);

int main(void)
{
    char ord[100];  // statisk lagerallokering, hvor vi laver rigeligt plads i lageret
    char *flertal;

    printf("Indtast dit ord i ental: \n");
    scanf("%99s", ord); // angiver hvor mange karakterer vi kan tage imod

    flertal = endelse(ord);

    printf("Dette ordet i singularis: %s\n", ord);
    printf("Dette er ordet i pluralis: %s\n", flertal);

    free(flertal);  // frigiver dynamisk allokeret hukommelse

    return 0;
}

char *endelse(char ord[])
{
    int laengde = strlen(ord); // finder længden af ordet

    // allokerer dynamisk et array der skal indeholde den nye streng
    // (ies er maks dvs. 3 ekstra tegn + '\0', derfor +4)
    char *str_ny = (char *) malloc((laengde + 4) * sizeof(char));
    if(str_ny == NULL){
        printf("Allokering lykkedes ikke\n");
        exit(EXIT_FAILURE);
    } 

    strcpy(str_ny, ord); // kopiering af streng over i ny variabel

    // Regel 1: ord der ender på 'y': 'y' bliver 'ies'
    if (ord[laengde - 1] == 'y') // her tjekker vi endelsen
    {
        str_ny[laengde - 1] = 'i'; // her tilføjer vi på laengde-1'ende plads osv.
        str_ny[laengde] = 'e';
        str_ny[laengde + 1] = 's';
        str_ny[laengde + 2] = '\0';
    }
    // Regel 2: ord der ender på s, ch, sh → tilføj 'es'
    else if (ord[laengde - 1] == 's' || 
             (laengde > 1 && ((ord[laengde - 2] == 'c' && ord[laengde - 1] == 'h') ||
                              (ord[laengde - 2] == 's' && ord[laengde - 1] == 'h'))))
    {
        str_ny[laengde] = 'e';
        str_ny[laengde + 1] = 's';
        str_ny[laengde + 2] = '\0';
    }
    // Regel 3: standard → tilføj 's'
    else
    {
        str_ny[laengde] = 's';
        str_ny[laengde + 1] = '\0';
    }

    return str_ny;
}
