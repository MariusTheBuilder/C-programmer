#include <ctype.h>
#include <stdio.h>

//it's shit, fix later:

char line[150];
int count = 0;
int i;

int main(char line[], int count){
    printf("Enter a line of string: ");
    scanf("%c", line[i]);
    
    for (int i = 0; line[i] != '\0'; ++i){
        if(islower(line[i] ==0)){
            count ++;
        }
        else if (islower(line[i]) == 0){
            ++i;
        }
        else if (islower(line[i]) == '\0'){
        }
        printf("Here you go: %d", count);
    return count;
}
}

//Check it out:

// funktionsprototype
int find_lower(char str[], int sum);
 
int main(void)
{
 
    char str[] = "feedback";
    int sum = 0; // antallet af små bogstaver
 
    // funktionskald
    sum = find_lower(str, sum);
 
    printf("Der er %d små bogstaver i ordet\n", sum);
 
    return 0;
}
 
int find_lower(char str[], int sum){
    int i = 0;
    while (str[i] != '\0'){
        if (islower(str[i]))
        {
            sum += 1;
        }
        i++;
    }
    return sum;
}