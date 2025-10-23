#include <stdio.h>

int main(void) {

  int percent, grade;

  printf("How many percent? ");
  scanf("%d",&percent);

  if (percent >= 90)
    grade = 12;
  else if (percent >= 82)
    grade = 10;
  else if (percent >= 74)
    grade = 7;
  else if (percent >= 66)
    grade = 4;
  else if (percent >= 58)
    grade = 02;
  else if (percent >= 50)
    grade = 00;
  else if (percent >= 10)
    grade = -3;
  else grade = 404; 

  printf("%d percent corresponds to the Danish grade %d\n\n", 
          percent, grade);
  
  return 0;
}