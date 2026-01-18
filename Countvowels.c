#include <ctype.h>
#include <stdio.h>
int main() {
        // Maximum 150 characters (149) and the counters of vowels, consonants, digits and spaces.
  char line[150];
  int vowels, consonant, digit, space;

        // initialize all variables to 0
  vowels = consonant = digit = space = 0;

        // get full line of string input
        // fgets reads a whole line of text incl. spaces 
        // line was set to char [150] so sizeof(line) sets the limit to that size.
        // stdin means "standard input"
  printf("Enter a line of string: ");
  fgets(line, sizeof(line), stdin); 

        // loop through each character of the string until it hits the end '\0'
  for (int i = 0; line[i] != '\0'; ++i) {

            // convert character to lowercase - to make A and a ans so one be treated the same.
    line[i] = tolower(line[i]);

    // check if the character is a vowel
    if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' ||
        line[i] == 'o' || line[i] == 'u') {

      // increment value of vowels by 1
      ++vowels;
    }

    // if it is not a vowel and if it is an alphabet, it is a consonant
    else if ((line[i] >= 'a' && line[i] <= 'z')) {
      ++consonant;
    }

    // check if the character is a digit
    else if (line[i] >= '0' && line[i] <= '9') {
      ++digit;
    }

    // check if the character is an empty space
    else if (line[i] == ' ') {
      ++space;
    }
  }

  printf("Vowels: %d", vowels);
  printf("\nConsonants: %d", consonant);
  printf("\nDigits: %d", digit);
  printf("\nWhite spaces: %d", space);

  return 0;
}