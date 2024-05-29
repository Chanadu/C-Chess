#ifndef GET_MOVE_INPUT_H
#define GET_MOVE_INPUT_H

#include "utils.h"


int* get_move_input(bool* isWhiteTurn, const char board[ROWS][COLS]);
int* get_new_move_input(bool* isWhiteTurn);
int* convert_input_to_xy(char* newLocation);
void clearNewLineFromBuffer();

#endif
