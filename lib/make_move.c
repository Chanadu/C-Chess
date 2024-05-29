#include "make_move.h"

#include <stdio.h>

#include "get_move_input.c"
#include "moves/pawn.c"
#include "print_board.c"



void make_move(bool* isWhiteTurn, char board[ROWS][COLS]) {
    int* user_move = get_move_input(isWhiteTurn, board);

    int oldX = user_move[0];
    int oldY = user_move[1];
    int newX = user_move[2];
    int newY = user_move[3];

    printf("Old X: [%d], Old Y: [%d]\n", oldX, oldY);
    printf("Old X: [%d], Old Y: [%d]\n", newX, newY);

    board[newX][newY] = board[oldX][oldY];
    board[oldX][oldY] = ' ';

    *isWhiteTurn ^= 1;

    print_board(board);
    make_move(isWhiteTurn, board);
}
