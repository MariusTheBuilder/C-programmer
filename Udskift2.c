#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str2;
char *udskift(char str[], char c1, char c2);


int main(void){
    char str[] = "Foodback";
        printf("Her er strengen: %s\n", str);

        printf("\nNu udskifter vi o med e:\n");
    str2 = udskift(str, 'o', 'e');

        printf("Her er den gamle streng: %s\n", str);
        printf("Her er den nye streng: %s\n", str2);
return 0;
}



char *udskift(char str[], char c1, char c2){
    char *str_ny = (char*) malloc((strlen(str)+1) * sizeof(char));
    if(str_ny == NULL){
        printf("allokeringen lykkedes ikke :-(\n");
        exit(EXIT_FAILURE);
    }
int i = 0;
while(str[i]!='\0'){
    if(str[i] == c1){
        str_ny[i] = c2;
    } else {
        str_ny[i] = str[i];
    }
    i++;
}
str_ny[i]='\0';
return str_ny;
}

