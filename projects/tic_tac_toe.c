#include <stdio.h>

char board[9];

void reset_board(void) {
    for (int i = 0; i < 9; i++)
        board[i] = '1' + i;
}

void print_board(void) {
    printf("\n %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n\n", board[6], board[7], board[8]);
}

int check_winner(void) {
    int w[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    for (int i = 0; i < 8; i++) {
        if (board[w[i][0]] == board[w[i][1]] &&
            board[w[i][1]] == board[w[i][2]])
            return 1;
    }
    return 0;
}

int main(void) {
    char player = 'X';
    int pos, moves = 0;

    reset_board();
    printf("=== Tic-Tac-Toe (2 players) ===\n");

    while (moves < 9) {
        print_board();
        printf("Player %c, choose a square (1-9): ", player);
        int r = scanf("%d", &pos);
        if (r == EOF) return 1;
        if (r != 1) {
            printf("Enter a number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        if (pos < 1 || pos > 9 || board[pos - 1] == 'X' || board[pos - 1] == 'O') {
            printf("Invalid move, try again.\n");
            continue;
        }

        board[pos - 1] = player;
        moves++;

        if (check_winner()) {
            print_board();
            printf("Player %c wins!\n", player);
            return 0;
        }
        player = (player == 'X') ? 'O' : 'X';
    }

    print_board();
    printf("It's a draw!\n");
    return 0;
}
