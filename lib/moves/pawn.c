#include "pawn.h"

#include <stdlib.h>

int *get_possible_moves_pawn(bool *isWhiteTurn, int oldX, int oldY, const char board[ROWS][COLS]) {
    int size = 2;
    int *possible_moves_arr =
        (int *)malloc((size + 1) * sizeof(int));  // THIS NEEDS TO BE FREED CUZ IT'S DYNAMIC MEMORY
    possible_moves_arr[0] = size;
    if (isWhiteTurn) {
        possible_moves_arr[1] = oldX + 1;
        possible_moves_arr[2] = oldY;
    } else {
        possible_moves_arr[1] = oldX - 1;
        possible_moves_arr[2] = oldY;
    }

    return possible_moves_arr;
}
