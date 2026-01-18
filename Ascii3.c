#include <stdio.h>


int main (void){
    int n; //Given værdi
    int j; //Tal foran *
    int i; //Antal *

    // Indtast n og m.
    printf("Indtast et heltal:\n");
    scanf("%d", &n);

//Gentager følgende n gange:
// Print tal og m stjerner.
for (j = 0; j<n; j++){
   printf("%d", j);

for (i = 0; i<=n; i++){
if(i>=j){ //den her vender shit på hovedet. (<= og >=)
printf(" ");
}else{
    printf("*");
}
}
printf("\n");
}

return 0;
}