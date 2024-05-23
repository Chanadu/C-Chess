#ifndef PAWN_H
#define PAWN_H

#include "../utils.h"

int* get_possible_moves_pawn(bool* isWhiteTurn, int oldX, int oldY, const char board[ROWS][COLS]);

#endif
