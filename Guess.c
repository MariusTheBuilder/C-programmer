#include <stdio.h>

#define Rigtig 3

int main(void)
{
    int gaet;
    int antal_gaet = 1;
    
    printf("Guess a number, between 1 and 20! :)\n");
    scanf("%d", &gaet);
    do
    {
        if (gaet == Rigtig)
        {
            printf("Huzzah! You win!\n");
        }
        else if (0<gaet && gaet>20) 
        {
            printf("!!!Out of bounds, try again!!!\n");
            scanf("%d", &gaet);
        }
        else
        { 
            antal_gaet++;
            printf("Nope, try again ;)\n");
            scanf("%d", &gaet);
        }
        

    } while (gaet != Rigtig);
    if (gaet == Rigtig, antal_gaet>1)
    {
        printf("Huzzah! You win!\n");   
    }
    printf("You tried %d times.\n", antal_gaet);
return 0;
}