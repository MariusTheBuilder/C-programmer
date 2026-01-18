#include <ctype.h>
#include <stdio.h>
#include <math.h>

// Skriv et program med tre doubles r, x og y.
// r fortolkes som radius af en cirkel omkring punktet (0,0).
// x og y er koordinaterne (x, y) af et punkt.
// Programmet skal afgøre om punktet (x, y) er placeret inden i cirklen, på cirkelperiferien, eller uden for cirklen.
// Kan I lave én printf med brug af betingede udtryk (?:), der udskriver 'inden i'/'uden for' og 'på' cirklen, baseret på de logiske udtryks værdi?
int main(void)
{
double r;
double x;
double y;

//Definerer vores cirkels radius.
    printf("Angiv radius af cirkel: \n");
scanf(" %lf", &r);

//Definerer vores punkt.
    printf("Angiv punktet:\n");
scanf(" %lf", &x);
scanf(" %lf", &y);

//Udregner punktets længde fra centrum.
    double laangden = sqrt(x * x + y * y);

    printf("\nPunktet:(%.0lf, %.0lf) ", x, y);
    printf("ligger %.2lf fra centrum!\n", laangden);

//Punktets placering bestemmes.
    int indenfor =
        (laangden < r);
        
    int cirkelpereferi =
        (laangden == r);

    int udenfor = // Kan slettes
        (laangden > r);

    if (indenfor)
    {
        printf("Punktet ligger inde i cirklen.");
    }
    else if (cirkelpereferi)
    {
        printf("Punktet ligger paa cirkelpereferien.");
    }
    else if (udenfor)
    {
        printf("Punktet ligger udenfor cirklen.");
    }
    return 0;
}
