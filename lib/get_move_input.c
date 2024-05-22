#include "get_move_input.h"

#include <ctype.h>

int* get_move_input(bool* isWhiteTurn) {
    char pieceOldLocation[3];
    char pieceNewLocation[3];

    printf("[%s] Piece to move: \n", *isWhiteTurn ? "WHITE" : "BLACK");
    fgets(pieceOldLocation, 3, stdin);
    clearNewLineFromBuffer();

    printf("[%s] Piece new location: \n", *isWhiteTurn ? "WHITE" : "BLACK");
    fgets(pieceNewLocation, 3, stdin);
    clearNewLineFromBuffer();

    for (int i = 0; i < 2; i++) {
        pieceOldLocation[i] = tolower(pieceOldLocation[i]);
        pieceNewLocation[i] = tolower(pieceNewLocation[i]);
    }

    // get indices for board (e.g. convert e4 to x and y index)
    int oldY = pieceOldLocation[0] - 'a';
    int oldX = 8 - (pieceOldLocation[1] - '0');

    int newY = pieceNewLocation[0] - 'a';
    int newX = 8 - (pieceNewLocation[1] - '0');

    return (int[]){oldX, oldY, newX, newY};
}
