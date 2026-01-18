#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Nah fam, this shit aint finished.

enum planets {Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptun};
typedef enum planets planets;

double circumference (planets planet_input){


switch (planet_input){
  case Mercury:
    return 15.329;
    break;
  case Venus:
    return 38.025;
    break;
  case Earth:
    return 40.075;
    break;
  case Mars:
    return 21.344;
    break;
  case Jupiter:
    return 439.264;
    break;
  case Saturn:
    return 378.675;
    break;
  case Uranus:
    return 160.590;
    break;
  case Neptun:
    return 155.600;
    break;
}
return j;
}

int main() {
int planet_input;
    printf("Enter planet: ");
    scanf("%d", planet_input);

    printf("This planet has a circumference of: %d km!", circumference);
return 0;
}