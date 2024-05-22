#include "make_move.h"

#include "print_board.c"

void clearNewLineFromBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

void make_move(bool* isWhiteTurn, char board[ROWS][COLS]) {
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

    printf("Old X: [%d], Old Y: [%d]\n", oldX, oldY);
    printf("Old X: [%d], Old Y: [%d]\n", newX, newY);

    board[newX][newY] = board[oldX][oldY];
    board[oldX][oldY] = ' ';

    *isWhiteTurn ^= 1;

    print_board(board);
    make_move(isWhiteTurn, board);
}
