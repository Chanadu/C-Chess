#include "get_move_input.h"

#include "moves/pawn.h"

int* get_move_input(bool* isWhiteTurn, const char board[ROWS][COLS]) {
    char pieceOldLocation[3];
    char pieceNewLocation[3];

    printf("[%s] Piece to move: \n", *isWhiteTurn ? "WHITE" : "BLACK");
    fgets(pieceOldLocation, 3, stdin);
    clearNewLineFromBuffer();

    // get indices for board (e.g. convert e4 to x and y index)
    int oldY = pieceOldLocation[0] - 'a';
    int oldX = 8 - (pieceOldLocation[1] - '0');

    if (board[oldX][oldY] == 'P' || board[oldX][oldY] == 'p') {
        int* possible_moves = get_possible_moves_pawn(isWhiteTurn, oldX, oldY, board);

        printf("[MOVING PAWN] POSSIBLE MOVES: (%d, %d)\n", possible_moves[0], possible_moves[1]);
    };

    printf("[%s] Piece new location: \n", *isWhiteTurn ? "WHITE" : "BLACK");
    fgets(pieceNewLocation, 3, stdin);
    clearNewLineFromBuffer();

    for (int i = 0; i < 2; i++) {
        pieceOldLocation[i] = tolower(pieceOldLocation[i]);
        pieceNewLocation[i] = tolower(pieceNewLocation[i]);
    }

    int newY = pieceNewLocation[0] - 'a';
    int newX = 8 - (pieceNewLocation[1] - '0');

    return (int[]){oldX, oldY, newX, newY};
}
