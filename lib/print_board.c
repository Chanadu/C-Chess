#include "print_board.h"

void print_board(char board[ROWS][COLS]) {
    printf("\n  ---------------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d |  ", 8 - i);
        for (int j = 0; j < COLS; j++) {
            char output = board[i][j] == ' ' ? '~' : board[i][j];
            printf("%c ", output);
        }
        printf(" |\n");
    }
    printf("  ---------------------\n     a b c d e f g h\n\n");
}
