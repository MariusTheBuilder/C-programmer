#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//spørg Bak.

char *endelse(char ord[]);

int main(void){
    char *ord;
    char *str_ny;
    
    printf("Indtast dit ord: \n");
    scanf(" %s\n", &ord);

flertal = endelse (ord, 0, str_ny);

    printf("Dette er ordet i singularis: %s\n", ord);
    printf("Dette er ordet i pluraris: %s\n", ord);

    return 0;
}
 
char *endelse(char ord[]){
    char *str_ny = (char*) malloc((strlen(ord) + 4) * sizeof(char));  
    if(str_ny == NULL){
        printf("Allokering lykkedes ikke\n");
        exit(EXIT_FAILURE);
    }
    if(*endelse(ord)){
        switch(ord){  
            case 'y':
                ord + 'ies';
                break;
            case 'ie':
                ord + 'es';
                break;
            case 'ir':
                ord + 's';
                break;
                return str_ny;
        }
str_ny [i] = 'ies';
str_ny [i] = 'es';
str_ny [i] = 's';
str_ny [i+1] = '\0';
    }
}
