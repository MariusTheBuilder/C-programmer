#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bilkort {
  char navn[30];
  int top_fart;
  int hk;
  int acceleration;
  int ccm;
};

typedef struct bilkort bilkort;

void udskriv_kort(bilkort bil);

bilkort indlaes_bilkort(void);

void gem_kort_i_fil(FILE *f, bilkort b);

void gem_alle_kort_i_fil(FILE *f, bilkort ba[], int lenght);

bilkort laes_kort_fra_fil(FILE *f);

void laes_flere_kort_fra_fil(FILE *f, bilkort ba[], int length);

int main(void){
  bilkort b1 = {"Lotus", 200, 110, 8, 1973};
  bilkort b2 = {"Mercedes", 215, 160, 9, 4520};
  bilkort ba[2] = {b1, b2};

  udskriv_kort(b1);
  printf("\n");
  udskriv_kort(b2);

  FILE *f = fopen("biler.txt", "w");
  if (f == NULL){
    printf("Filen kunne ikke aabnes.\n");
    exit(EXIT_FAILURE);
  }
  
  gem_alle_kort_i_fil(f, ba, 2);

  fclose(f);

  FILE *f2 = fopen("biler.txt", "r");
  if(f == NULL){
    printf("Filen kunne ikke aabnes\n");
    exit(EXIT_FAILURE);
  }

  bilkort ba2[2];

  laes_flere_kort_fra_fil(f, ba2, 2);

  printf("\nVi laeste disse biler fra en fil:");
  udskriv_kort(ba2[0]);
  udskriv_kort(ba2[1]);

  fclose(f2);

  return 0;
}

void laes_flere_kort_fra_fil(FILE *f, bilkort ba[], int lenght){
  for(int i=0; i < lenght; i++){
    bilkort b;
      int success = fscanf(f, "%s %d %d %d %d", b.navn, &b.top_fart, &b.hk, &b.acceleration, &b.ccm);
      if(success != 5){
        break; 
      }
      ba[i] = b;
  }
}


bilkort laes_kort_fra_fil(FILE *f){
    bilkort b;
      fscanf(f, "%s %d %d %d %d", b.navn, &b.top_fart, &b.hk, &b.acceleration, &b.ccm);
return b;
}

void gem_alle_kort_i_fil(FILE *f, bilkort ba[], int lenght){
  for(int i=0; i < lenght; i++){
    gem_kort_i_fil(f, ba[i]);
  }
}

void gem_kort_i_fil(FILE *f, bilkort b){
  //Hiv alle felterne ud af b
  char n[30];
  strcpy(n,b.navn);
  int tf = b.top_fart;
  int heste = b.hk;
  int a = b.acceleration;
  int c = b.ccm;

  //Skriv felter ind i f
  fprintf(f, "%s %d %d %d %d\n", n, tf, heste, a, c);
}

void udskriv_kort(bilkort bil){
  //Hiv vaerdierne ud
  char *n = bil.navn;
  int f = bil.top_fart;
  int hest = bil.hk;
  int a = bil.acceleration;
  int ccm = bil.ccm;

  //Print
  printf("\n Navn: %s", n);
  printf("\n Top fart: %d", f);
  printf("\n HK: %d", hest);
  printf("\n Acceleration: %d", a);
  printf("\n CCM: %d\n", ccm);

}

bilkort indlaes_bilkort(void){
  char navnet[30];
  int f;
  int hk;
  int acc;
  int ccm;

  //Indlæs fra tastatur.
  printf("Tast et navn: \n");
  scanf("%s", navnet);
  printf("Tast topfart:\n");
  scanf("%d", &f);
  printf("Tast hestekrafter:\n");
  scanf("%d", &hk);
  printf("Tast acceleration:\n");
  scanf("%d", &acc);
  printf("Tast ccm:\n");
  scanf("%d", &ccm);

  //Opret bilkort og læg værdierne ind.
  bilkort nyt_kort;
  strcpy(nyt_kort.navn, navnet);
  nyt_kort.top_fart = f;
  nyt_kort.hk = hk;
  nyt_kort.acceleration = acc;
  nyt_kort.ccm = ccm;

  return nyt_kort;

}
