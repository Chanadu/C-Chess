#include "make_move.h"

#include <stdbool.h>

#include "get_move_input.h"
#include "print_board.h"

void clearNewLineFromBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

void make_move(bool* isWhiteTurn, char board[ROWS][COLS]) {
    int* user_move_arr = get_move_input(isWhiteTurn);

    int oldX = user_move_arr[0];
    int oldY = user_move_arr[1];
    int newX = user_move_arr[2];
    int newY = user_move_arr[3];

    printf("Old X: [%d], Old Y: [%d]\n", oldX, oldY);
    printf("Old X: [%d], Old Y: [%d]\n", newX, newY);

    board[newX][newY] = board[oldX][oldY];
    board[oldX][oldY] = ' ';

    *isWhiteTurn ^= 1;

    print_board(board);
    make_move(isWhiteTurn, board);
}
