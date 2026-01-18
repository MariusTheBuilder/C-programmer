#include <stdio.h>
#include <string.h>

#define NAME_LEN 20

// ######## Strukturen af et bilkort ########
struct bilkort {
    char navn[NAME_LEN + 1];
    int topfart;
    int hestekraft;
    int acc;
    int ccm;
};
  typedef struct bilkort bilkort;



// ######## Prototyper ########
void print_bil(bilkort b);
bilkort hurtigst(bilkort b1, bilkort b2, bilkort b3);
bilkort input_kort(void);


 
// ######## Main ########
int main(void){
  bilkort lotus =
    {"Lotus", 200, 110, 8, 1973};
  bilkort mercedes =
    {"Mercedes", 215, 160, 9, 4520};
  bilkort b = 
    input_kort();

  printf("Din bil:\n"); 
    printf("[1]--------------[1]\n");
    print_bil(b);
  printf("[1]--------------[1]\n\n\n");

  printf("Anden bil:\n");
    printf("[2]--------------[2]\n");
    print_bil(lotus);
  printf("[2]--------------[2]\n\n\n");
  
  printf("Tredje bil:\n");
    printf("[3]--------------[3]\n");
    print_bil(mercedes);
    printf("[3]--------------[3]\n\n\n");
    
    printf("Den hurtigste var:\n");
    printf("[#]--------------[#]\n");
    bilkort h = hurtigst(lotus, mercedes, b);
    print_bil(h);
     printf("[#]--------------[#]");
    
return 0;
}

// Sammenligner Input bilen med de 2 andre biler.
bilkort hurtigst(bilkort b1, bilkort b2, bilkort b3){
  bilkort h;
  if(b1.topfart > b2.topfart && b1.topfart > b3.topfart ){
    h = b1;
  } else if (b2.topfart > b1.topfart && b2.topfart > b3.topfart){
    h = b2;
  } else if (b3.topfart > b1.topfart && b3.topfart > b2.topfart){
    h = b3;
  }
return h;
}

bilkort input_kort(void){
  // Brugeren indtaster navn, topfart, hestekrafter, osv.
  char n[NAME_LEN + 1];
  printf("Indtast navn: ");
  scanf("%s", n);

  int tf;
    printf("Indtast topfart: ");
    scanf("%d", &tf);

  int hk;
    printf("Indtast hestekrafter: ");
    scanf("%d", &hk);

  int a;
    printf("Indtast acceleration: ");
    scanf("%d", &a);

  int c;
    printf("Indtast ccm: ");
    scanf("%d", &c);
    printf("\n");


  // Opretter bilkort:
  bilkort b;

  // Lægger navn, topfart, osv ind i kort
  strcpy(b.navn, n);
  b.topfart = tf;
  b.hestekraft = hk;
  b.acc = a;
  b.ccm = c;

  return b;
}

void print_bil(bilkort b){
// Vi hiver felterne ud af b:

char name[NAME_LEN + 1];
strcpy(name, b.navn);
int tf = b.topfart;
int hk = b.hestekraft;
int a = b.acc;
int c = b.ccm;

// Vi printer:
printf("Name: %s\n", name);
printf("Topfart: %d\n", tf);
printf("Hestekrafter: %d\n", hk);
printf("Acceleration: %d\n", a);
printf("Ccm: %d\n", c);
}