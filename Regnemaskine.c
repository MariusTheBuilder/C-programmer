#include <stdio.h>
#include <stdbool.h>
#include <math.h>

      // Regnemaskinen her holder styr på et enkelt tal, akkumulatoren, af typen double.
     // Først vælger man en operator  - (char) - af hvilke der er 9: [+], [-], [*], [/], [^], [#], [%], [!] og [q].
    // Dernæst vælger man en operand - (double) - hvilket er et vilkårligt tal.

   // scan_data har to output parametre, som returnerer en operator og en operand.
  // Hvis der bliver anvendt en unær operator, returneres operanden som 0.0.
 // ("*" foran operator og operand betyder at det er en pointer variabel) :)

// Hvis ikke der indtastes en af de definerede operators, så afslutter vi loopen starter fra toppen.
void scan_data(char *operator, double *operand) {
    printf("Enter operator:   ");
    if (scanf(" %c", operator) != 1) { 
        *operator = 'q'; 
        return;
    }

 // Hvis det er en binær operation, hopper vi videre til at læse en operand.
// Hvis operanden ikke bliver læst korrekt, sætter vi den til 0.0.

// FIKS MANGLER HER. Bogstav i stedet for tal sender den i kuk-kuk.
    if (*operator == '+' || *operator == '-' || *operator == '*' || *operator == '/' || *operator == '^') {
        printf("Enter operand:    ");
        if (scanf(" %lf", operand) != 1) {
            *operand = 0.0;
        }
    } else {
        *operand = 0.0;
    }
}

// Tjekker om operator er binær.
bool is_binary_operator(char operator) {
    return (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^');
}

   // Her udføres operationen på akkumulatoren.
  // Vi bruger en midlertidig definition for akkumulatoren, a, for overskuelighed.
 // Operand ignoreres for unære operatorer. 
 
// Binære operatorer.
void do_next_op(char operator, double operand, double *accumulator) {
    double a = *accumulator;

    if (is_binary_operator(operator)) {
        switch (operator) {
            case '+':
                a = a + operand;
                break;
            case '-':
                a = a - operand;
                break;
            case '*':
                a = a * operand;
                break;
            case '/':
                if (operand != 0.0) {
                    a = a / operand;       
                } 
                break;
            case '^':
                a = pow(a, operand);
                break;
        }
        *accumulator = a;
        return;
    }

    // Unære operatorer.
    switch (operator) {
        case '#':
            if (*accumulator >= 0.0) {
                *accumulator = sqrt(*accumulator);
            }
            break;
        case '%':
            *accumulator = -(*accumulator);
            break;
        case '!':
            if (*accumulator != 0.0) {
                *accumulator = 1.0 / (*accumulator);
            }
            break;
        case 'q':
            break;
        default:
            // ukendt operator: gør ingenting (akkumulator uændret).
            break;
    }
}

 // Lommeregnerens primære dialog.
// Det er denne, som main kører, som så starter hele sekvensen igennem de de andre funktioner.
double run_calculator(void) {
    double accumulator = 0.0;
    char operator;
    double operand;
             printf("\n|----------------------------------------------------|\n"); 
             printf("|             !Welcome to Calc-O-Marius!             |\n");
             printf("|               Starting result: [0.0]               |\n");

                printf("| Your following options are:                        |\n");
                printf("| [+] for addition                                   |\n");
                printf("| [-] for subtraction                                |\n");
                printf("| [*] for multiplication                             |\n");
                printf("| [/] for division                                   |\n");
                printf("| [^] for raising to a power                         |\n");

                printf("| [#] to take the squareroot of the operand          |\n");
                printf("| [%%] to change the sign                             |\n");
                printf("| [!] to divide 1 by the result                      |\n");
                printf("| [q] to finish the calculator with the final result |\n");
                printf("|----------------------------------------------------|\n\n");

    while (1) {
        scan_data(&operator, &operand);

        if (operator == 'q') {
            printf("Final result is: [%.6f]\n", accumulator);
            return accumulator;
        }

// Udfører operationen igen.
        do_next_op(operator, operand, &accumulator);

// Viser resultatet efter hver operation.
        printf("Result so far is [%.6f].\n", accumulator);
    }
}

// Main gemmer sig hernede, og kører lommeregneren, som så sørger for at køre både scan_data og do_next_op.
int main(void) {
    run_calculator();
    return 0;
}