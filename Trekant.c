#include <stdio.h>
#include <math.h>

int main(void){
  double p1_x;
  double p1_y;
  double p2_x;
  double p2_y;
  double p3_x;
  double p3_y;

  //Brugeren angiver et linjestykke som to punkter i planet.
  printf("Indtast et punkt (x-koordinat mellemrum y-koordinat): \n");
  scanf(" %lf %lf", &p1_x, &p1_y);

  printf("Indtast endnu et punkt (x-koordinat mellemrum y-koordinat): \n");
  scanf(" %lf %lf", &p2_x, &p2_y);

  printf("Indtast det sidste punkt (x-koordinat mellemrum y-koordinat): \n");
  scanf(" %lf %lf", &p3_x, &p3_y);

  //Regn delta x'erne
  double delta_x1 = p1_x - p2_x;    //punkt 1
  double delta_x2 = p2_x - p3_x;    //punkt 2
  double delta_x3 = p3_x - p1_x;    //punkt 3

  //Regn delta y'erne
  double delta_y1 = p1_y - p2_y;    //punkt 1
  double delta_y2 = p2_y - p3_y;    //punkt 2
  double delta_y3 = p3_y - p1_y;    //punkt 3

  //Regn 
  double laengde1 = sqrt(delta_x1*delta_x1 + delta_y2*delta_y2);
  double laengde2 = sqrt(delta_x2*delta_x2 + delta_y2*delta_y2);
  double laengde3 = sqrt(delta_x3*delta_x3 + delta_y3*delta_y3);

  //Programmet skriver længderne ud
  printf("Her er laengde 1: %lf\n", laengde1);
  printf("Her er laengde 2: %lf\n", laengde2);
  printf("Her er laengde 3: %lf\n", laengde3);

  //Programmet beregner omkredsen, og skriver dem ud.
  printf("Tadaaa: %lf\n", laengde1 + laengde2 + laengde3);

  return 0;
}
