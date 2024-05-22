#include "pawn.h"

#include <stdlib.h>

int *get_possible_moves_pawn(bool *isWhiteTurn, int oldX, int oldY, const char board[ROWS][COLS]) {
    int size = 2;
    int *possible_moves_arr = (int *)malloc(size * sizeof(int));

    if (isWhiteTurn) {
        possible_moves_arr[0] = oldX + 1;
        possible_moves_arr[1] = oldY;
    } else {
        possible_moves_arr[0] = oldX - 1;
        possible_moves_arr[1] = oldY;
    }

    return possible_moves_arr;
}
