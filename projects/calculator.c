#include <stdio.h>

double add(double a, double b)      { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b)   { return a / b; }

int main(void) {
    int choice;
    double a, b;

    do {
        printf("\n===== Simple Calculator =====\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }

        if (choice == 5) {
            printf("Goodbye!\n");
            break;
        }
        if (choice < 1 || choice > 4) {
            printf("Please choose between 1 and 5.\n");
            continue;
        }

        printf("Enter two numbers: ");
        if (scanf("%lf %lf", &a, &b) != 2) {
            printf("Invalid numbers. Exiting.\n");
            return 1;
        }

        switch (choice) {
            case 1: printf("Result: %.2f\n", add(a, b)); break;
            case 2: printf("Result: %.2f\n", subtract(a, b)); break;
            case 3: printf("Result: %.2f\n", multiply(a, b)); break;
            case 4:
                if (b == 0)
                    printf("Error: cannot divide by zero.\n");
                else
                    printf("Result: %.2f\n", divide(a, b));
                break;
        }
    } while (1);

    return 0;
}
