#include <stdio.h>

void scale(int gammel_plaene_laengde, int gammel_plaene_bredde, int faktor,
           int *ny_plaene_laengde_pejer, int *ny_plaene_bredde_pejer);

void get_input(int *gammel_planene_laengde, int* gammel_plaene_bredde,
               int *faktor);

int main(void){
  int gammel_plaene_laengde = 5;
  int gammel_plaene_bredde = 3;
  int ny_plaene_laengde;
  int ny_plaene_bredde;
  int faktor = 2;

  get_input(&gammel_plaene_laengde, &gammel_plaene_bredde, &faktor);

  scale(gammel_plaene_laengde, gammel_plaene_bredde, 
        faktor,
        &ny_plaene_laengde, &ny_plaene_bredde);

  printf("Ny laengde %d\nNy bredde %d\n", 
         ny_plaene_laengde, ny_plaene_bredde);

  return 0;
}

void get_input(int *gammel_planene_laengde, int* gammel_plaene_bredde,
               int *faktor){
  printf("Indtast laengde, bredde og faktor:\n");
  scanf("%d %d %d",gammel_planene_laengde, gammel_plaene_bredde, faktor);
}

void scale(int gammel_plaene_laengde, 
           int gammel_plaene_bredde, int faktor,
           int *ny_plaene_laengde_pejer, 
           int *ny_plaene_bredde_pejer){
  *ny_plaene_laengde_pejer = gammel_plaene_laengde * faktor;
  *ny_plaene_bredde_pejer = gammel_plaene_bredde * faktor;
}
