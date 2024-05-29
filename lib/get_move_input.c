#include "get_move_input.h"

#include "moves/pawn.h"

void clearNewLineFromBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

int* get_move_input(bool* isWhiteTurn, const char board[ROWS][COLS]) {
    char pieceOldLocation[3];
    char pieceNewLocation[3];

    printf("[%s] Piece to move: \n", *isWhiteTurn ? "WHITE" : "BLACK");
    fgets(pieceOldLocation, 3, stdin);
    clearNewLineFromBuffer();

    // get indices for board (e.g. convert e4 to x and y index)
    int oldY = pieceOldLocation[0] - 'a';
    int oldX = 8 - (pieceOldLocation[1] - '0');
    int newX, newY;
    if (board[oldX][oldY] == 'P' || board[oldX][oldY] == 'p') {
        int* possible_moves = get_possible_moves_pawn(isWhiteTurn, oldX, oldY, board);
        for (int i = 1; i < possible_moves[0]; i += 2) {
            printf("[MOVING PAWN] POSSIBLE MOVE: (%c, %c)\n", possible_moves[0 + i] + 'a',
                   possible_moves[1 + i] + '0');
        }

        bool isValid = false;

        while (!isValid) {
            int* newLocation = get_new_move_input(isWhiteTurn);
            newX = newLocation[0];
            newY = newLocation[1];

            for (int i = 1; i < possible_moves[0]; i += 2) {
                if (newX == possible_moves[i] && newY == possible_moves[i + 1]) {
                    isValid = true;
                    break;
                }
            }
            free(newLocation);
            printf("That move is not valid. Please try again.\n");
        }

        free(possible_moves);
    };

    return (int[]){oldX, oldY, newX, newY};
}

int* get_new_move_input(bool* isWhiteTurn) {
    char newLocation[3];
    printf("[%s] Piece new location: \n", *isWhiteTurn ? "WHITE" : "BLACK");
    fgets(newLocation, 3, stdin);
    clearNewLineFromBuffer();

    for (int i = 0; i < 2; i++) {
        newLocation[i] = tolower(newLocation[i]);
    }
    return convert_input_to_xy(newLocation);
}

int* convert_input_to_xy(char* newLocation) {
    int* newFixedLocation = (int*)malloc(sizeof(int) * 2);
    newFixedLocation[0] = newLocation[0] - 'a';
    newFixedLocation[1] = 8 - (newLocation[1] - '0');
    free(newLocation);
    return newFixedLocation;
}