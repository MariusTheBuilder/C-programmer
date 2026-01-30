#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main (){
printf("\n");
int Number = 333;
int Number2 = 666;
char Letter = 'M';

int x = 60, y = 9;
int sum = x+y;
printf("%d\n\n",sum);

printf("%d?\nThats a lot!\nM er et ret sejt bogstav.\n",Number);
printf("Marius defineres som %c og hans tal er %d\n\n", Letter, Number);

 // Student data. Format Specifiers.
  int studentID = 303030;                  // Hele tal
  int studentAge = 21;                     // Hele tal
  float studentFee = 75.2555;              // 7 Decimaler
  char studentGrade = 'A';                 // Enkelte bogstaver
  char myText[]="Student has passed!";     // String = Ord eller tekst
  double studentDebt = 308.398272536;      // 15 Decimaler

  // Print variables
  printf("Student id: %d\n", studentID);
  printf("Student age: %d\n", studentAge);
  printf("Student fee: %.4f\n", studentFee);
  printf("Student grade: %c\n", studentGrade);
  printf("%s\n", myText);
  printf("Student debt: %.9lf\n\n", studentDebt);

 // Udregning af procentvis testscore.

 // Set the maximum possible score to 500
  const int MAXSCORE = 500;                  // Skriver "const" for at gøre den permanent og uforandrelig. Skriv dem med stort
  const int PASSINGSCORE = 300;
 
  // The actual score of the users
  int userScore1 = 413;

  // Calculate the percantage of the user's score in relation to the maximum available score
  float percentage = (float) userScore1 / MAXSCORE * 100.0;

   // Print the percentage
  printf("User's percentage is %.2f\n", percentage);

  if (userScore1>=PASSINGSCORE){
  printf("You have passed! Congratulations!\n\n");
  } else if (userScore1==0) { 
  printf("You failed.\n\n");
  } else {
  printf("You did not pass. Better luck next time.\n\n");
  }
  int day = 2;
  
  // Hvilken dag var det nu i dag?
  switch (day) {
    case 1:
      printf("Mandag\n\n");
      break;
    case 2:
      printf("Tuesday\n\n");
      break;
    case 3:
      printf("Wednesday\n\n");
      break;
    case 4:
      printf("Thursday\n\n");
      break;
    case 5:
      printf("Friday\n\n");
      break;
    case 6:
      printf("Saturday\n\n");
      break;
    case 7:
      printf("Sunday\n\n");
      break;
      default:
      printf("It must be Frey-day! :)\n\n");
  }
  int dice = 1;
  
  while (dice <= 6) {
    if (dice < 6) {
      printf("No Yatzy\n");
    } else {
      printf("Yatzy!\n\n");
    }
    dice = dice + 1;
  }
// Expression 1 is executed (one time) before the execution of the code block.
// Expression 2 defines the condition for executing the code block.
// Expression 3 is executed (every time) after the code block has been executed.
// for (expression 1; expression 2; expression 3)
int number = 2;
int i;
  //    1      2      3
  for (i=1; i <= 10; i++){
  printf("%dx%d=%d\n\n", number, i, number*i);
  }  

int c = 0;
  while (c < 10) {
    if (c == 4) {
      c++;
      continue;
    }
    printf("%d\n", c);
    c++;
  } 
printf("\n");
int b = 0;
  while (b < 10) {
    if (b == 4) {
      break;
    }
    printf("%d\n", b);
    b++;
  } 
printf("\n");

// Element nummering  0   1   2   3   4   5
int highscores [] = {201,204,382,456,890,1234};
printf ("The first Highscore ever recorded is: %d\n", highscores[0]);

float avg, sum2 = 0;
int h;
int length = sizeof(highscores) / sizeof(highscores[0]);

for (h = 0; h < length; h++) {
    sum2 += highscores[h];
  }

avg = sum2 / length;
// Print the average
printf("The average Highscore is: %.2f\n", avg);

int highestScore = highscores[0];
for (h = 0; h < length; h++) {
  if (highestScore < highscores[h]) {
    highestScore = highscores[h];
  }
}
printf("The highest Highscore ever achieved is: %d\n\n", highestScore);

// fat lige den her del
int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
printf("%d\n\n", matrix[0][2]);  // Outputs 2

char greetings[] = "Hello \"World!\"";
printf("%s", greetings);

return 0;
}