#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define ROWS 8
#define COLS 8

void make_move(bool* isWhiteTurn, char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);
void clearNewLineFromBuffer();

#endif
