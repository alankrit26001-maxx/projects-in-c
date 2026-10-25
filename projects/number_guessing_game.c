#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int secret, guess, attempts = 0;
    const int max_attempts = 7;

    srand((unsigned)time(NULL));
    secret = rand() % 100 + 1;

    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts.\n\n", max_attempts);

    while (attempts < max_attempts) {
        printf("Attempt %d - enter your guess: ", attempts + 1);
        int r = scanf("%d", &guess);
        if (r == EOF) return 1;
        if (r != 1) {
            printf("Please enter a valid number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        attempts++;

        if (guess == secret) {
            printf("Correct! You got it in %d attempt(s).\n", attempts);
            return 0;
        } else if (guess < secret) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }
    }

    printf("Game over! The number was %d.\n", secret);
    return 0;
}
