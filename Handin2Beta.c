#include <stdio.h>

// I denne opgave skal du skrive et program, der kan tælle hvor mange tal (fra 1 til n) der indeholder et bestemt ciffer c. 
// For eksempel er der 19 tal fra 1 til 100 der indeholder cifferet 5. 


// This function checks if integer "number" contains the digit, c, we are looking for.
// It will be used to check all numbers from 1 to n, in the for loop in main. 
// It uses the modulo operator to get the remainder when dividing by 10, and comparing it to c, before dividing by 10 to check the next digit, if not found.
int containsDigit(int number, int c){
    while(number>0){
        if(number % 10 == c)
            return 1;                    // If the digit is found, it stops.
        number = number/10;            //  Remove last digit.
    }
    return 0;
}

// Our main function.
int main(){ 
    int n;                 // The number we are counting up to. (Minimum of 1)
    int c;                //  The number we are checking for occurrences. (0 - 9)
    int occurrences = 0; //   Occurences of the digit. (Only if it is present, not how many times.)
    printf("Let's count how many numbers from 1 to n contain a given digit.\n");

// Defining and setting boundary for the number n.
    printf("How far are we counting up to: ");
    if(scanf("%d", &n) !=1 || n<1){
        printf("Error, out of bounds!\n");
        return 1;
    }

// Defining and setting boundary for the digit c.
    printf("Which number are we counting: ");
    if(scanf("%d", &c) !=1 || c<0 ||c>9){
        printf("Error, out of bounds!\n");
        return 1;
    }

// This function will check every number, i, from 1 to n, by putting each number i in the "containsDigit" function, to check if it contains the digit c.
    for (int i = 1; i <= n; i++) {
        if (containsDigit(i, c)) {
            occurrences++;
        }
    }

// Printing the result of the program
    printf("\n");
    printf("The number (%d) appears in %d numbers from 1 to %d.\n", c, occurrences, n);
    return 0;
}
