#include <stdio.h>
void get_value(char c);
void get_char(int value);
 
int main() {
   char c;
   printf("\n Skriv et bogstav:");
   scanf("%c", &c);
   
   get_value(c);
   
   int f;
   printf("\n Skriv et tal mellem 0-25:");
   scanf("%d", &f);
 
   get_char(f);
 
   return 0;
}
 
void get_value(char c) {
   switch(c){
      case 'A': case 'a':
         printf("0\n");
            break;
      case 'B': case 'b':
         printf("1\n");
            break;
      case 'C': case 'c':
         printf("2\n");
            break;
      case 'D': case 'd':
         printf("3\n");
            break;
      case 'E': case 'e':
         printf("4\n");
            break;
      case 'F': case 'f':
         printf("5\n");
            break;
      case 'G': case 'g':
         printf("6\n");
            break;
      case 'H': case 'h':
         printf("7\n");
            break;
      case 'I': case 'i':
         printf("8\n");
            break;
      case 'J': case 'j':
         printf("9\n");
            break;
      case 'K': case 'k':
         printf("10\n");
            break;
      case 'L': case 'l':
         printf("11\n");
            break;
      case 'M': case 'm':
         printf("12\n");
            break;
      case 'N': case 'n':
         printf("13\n");
            break;
      case 'O': case 'o':
         printf("14\n");
            break;
      case 'P': case 'p':
         printf("15\n");
            break;
      case 'Q': case 'q':
         printf("16\n");
            break;
      case 'R': case 'r':
         printf("17\n");
            break;
      case 'S': case 's':
         printf("18\n");
            break;
      case 'T': case 't':
         printf("19\n");
            break;
      case 'U': case 'u':
         printf("20\n");
            break;
      case 'V': case 'v':
         printf("21\n");
            break;
      case 'W': case 'w':
         printf("22\n");
            break;
      case 'X': case 'x':
         printf("23\n");
            break;
      case 'Y': case 'y':
         printf("24\n");
            break;
      case 'Z': case 'z':
         printf("25\n");
            break;
      default:
         printf("Skriv kun bogstaver!!!!!!!");
   }
}
 
 
void get_char(int value) {
   switch(value) {
      case 0:
         printf("A\n");
            break;
      case 1:
         printf("B\n");
            break;
      case 2:
         printf("C\n");
            break;
      case 3:
         printf("D\n");
            break;
      case 4:
         printf("E\n");
            break;
      case 5:
         printf("F\n");
            break;
      case 6:
         printf("G\n");
            break;
      case 7:
         printf("H\n");
            break;
      case 8:
         printf("I\n");
            break;
      case 9:
         printf("J\n");
            break;
      case 10:
         printf("K\n");
            break;
      case 11:
         printf("L\n");
            break;
      case 12:
         printf("M\n");
            break;
      case 13:
         printf("N\n");
            break;
      case 14:
         printf("O\n");
            break;
      case 15:
         printf("P\n");
            break;
      case 16:
         printf("Q\n");
            break;
      case 17:
         printf("R\n");
            break;
      case 18:
         printf("S\n");
            break;
      case 19:
         printf("T\n");
            break;
      case 20:
         printf("U\n");
            break;
      case 21:
         printf("V\n");
            break;
      case 22:
         printf("W\n");
            break;
      case 23:
         printf("X\n");
            break;
      case 24:
         printf("Y\n");
            break;
      case 25:
         printf("Z\n");
            break;
      default:
         printf("Skriv kun tal mellem 0-25!!!!\n");
   }
}