#ifndef GET_MOVE_INPUT_H
#define GET_MOVE_INPUT_H

#include "utils.h"

int* get_move_input(bool* isWhiteTurn, const char board[ROWS][COLS]);
void clearNewLineFromBuffer();

#endif
