#include <stdio.h>

int main (void){
    int m; //idek
    int n; //Given værdi
    int j; //Tal foran *
    int i; //Antal *

         // Indtast n og m.
         printf("Indtast to heltal:\n");
         scanf("%d %d", &n, &m);


//Printer n tal med m antal stjerner
for(j=0; j<n; j++){
    printf("%d", j);

for(i=0; i<m; i++){
    printf("*");
}
printf("\n");
}
printf("\n");


//Printer lige så mange stjener som tal.
for(j=0; j<n; j++){
    printf("%d", j);

for(i=0; i<j; i++){
    printf("*");
}
printf("\n");
}
printf("\n");

//Vender træet på hovedet.
for(j=0; j<n; j++){
    printf("%d", j);

for(i=0; i<=n; i++){
if(i<=j){ //den her vender shit på hovedet. (<= og >=)
printf(" ");
}else{
    printf("*");
}
}
printf("\n");
}
printf("\n");

//Vender træet. Skriver n i starten, find lige et fiks.
for(i=0; i<n; i++){
    printf("%d", i);

for(m=n; m>i; --m){
    printf(" ");
}
for(j=0; j<i; j++){
    printf("*");
}
printf("\n");
}
printf("\n");
return 0;
}