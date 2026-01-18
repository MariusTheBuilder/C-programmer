#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int i;
    char number[11]; // 10 ciffer + null terminator

    srand(time(NULL)); // Random number generator

    number[0] = (rand() % 9) + '1'; // det er så første ciffer ikke er 0

    for(i = 1; i < 10; i++){
        number[i] = (rand() % 10) + '0'; // resten af cifrene kan være mellem 0-9
    }

        number[10] = '\0'; // null terminator
        
        printf("%s\n", number);
        //getchar(); 

        return 0;

}