#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int guess, num1, num2, num3;
    int tries = 1;
    printf("\n3 random numbers from 1 to 10 will be chosen.\nGuess one of them to win!\n");

// Generer tilfældige tal
    num1 = rand() % 10 + 1;
do{
    num2 = rand() % 10 + 1;
}while(num2==num1);
do{
    num3 = rand() % 10 + 1;
}while(num3 == num1 ||num3==num2);

    printf("GUESS: ");
    scanf("%d", &guess);

while(guess != num1 || guess != num2 ||guess != num3){
    if(0<guess && guess>10){
        printf("!!!Out of bounds, try again!!!\n");
        scanf("%d", &guess);
    
    }else if(guess == num1 || guess == num2 ||guess == num3){
        printf("Huzzah! You win!\n");
        printf("The numbers were: [%d]&[%d]&[%d]\n", num1, num2, num3);
        printf("You tried %d times.\n", tries);
        break;

    }else{ 
        tries++;
        printf("Nope, try again ;)\n");
        scanf("%d", &guess);
    }
}
return 0;
}
