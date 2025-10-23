#include <ctype.h>
#include <stdio.h>

//Undersøg switches
int main(void)
{

    // Spillerne indtaster hænderne
    char haand1;
    char haand2;
    printf("Spiller 1, indtast haand! (r,p,s):\n");
    scanf(" %c", &haand1);

    printf("Spiller 2, indtast haand! (r,p,s):\n");
    scanf(" %c", &haand2);
    printf("\nThe results are in folks!\n");
    
    printf("Spiller 1: %c\n",haand1);
    printf("Spiller 2: %c\n",haand2);

    // Programmet udrenger vinderen
    int spiller1_vandt =
        (haand1 == 's') && (haand2 == 'p') ||
        (haand1 == 'r') && (haand2 == 's') ||
        (haand1 == 'p') && (haand2 == 'r');
    int spiller2_vandt =
        (haand1 == 'p') && (haand2 == 's') ||
        (haand1 == 's') && (haand2 == 'r') ||
        (haand1 == 'r') && (haand2 == 'p');
    int uafgjort = // Kan også skrive (haand1 == haand2)
        (haand1 == 'p') && (haand2 == 'p') ||
        (haand1 == 's') && (haand2 == 's') ||
        (haand1 == 'r') && (haand2 == 'r');

    // programmet udskriver om spiller 1 vandt
    if (spiller1_vandt)
    {
        printf("Spiller 1 Vandt!\n", spiller1_vandt);
    }

    else if (spiller2_vandt)
    {
        printf("Spiller 2 vandt!\n", spiller2_vandt);
    }

    else if (uafgjort)
    {
        printf("It's a tie!\n", uafgjort);
    }

    else
    {
        printf("ERROR, forkert input, Batman.");
    }
    return 0;
}