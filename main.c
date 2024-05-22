#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ROWS 8
#define COLS 8

typedef enum
{
    false,  // 0
    true    // 1
} bool;

void make_move(bool* isWhiteTurn, char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);

int main(int argc, char** argv)
{
    // clang-format off
    char board[ROWS][COLS] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    // clang-format on

    bool isWhiteTurn = true;

    make_move(&isWhiteTurn, board);

    return 1;
}

void clearNewLineFromBuffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

void make_move(bool* isWhiteTurn, char board[ROWS][COLS])
{
    char pieceOldLocation[3];
    char pieceNewLocation[3];

    printf("[%s] Piece to move: \n", *isWhiteTurn ? "WHITE" : "BLACK");
    fgets(pieceOldLocation, 3, stdin);
    // fflush(stdin);
    clearNewLineFromBuffer();
    printf("[%s] Piece new location: \n", *isWhiteTurn ? "WHITE" : "BLACK");
    fgets(pieceNewLocation, 3, stdin);
    clearNewLineFromBuffer();

    for (int i = 0; i < 2; i++)
    {
        pieceOldLocation[i] = tolower(pieceOldLocation[i]);
        pieceNewLocation[i] = tolower(pieceNewLocation[i]);
    }

    printf("\n\n\n");
    printf("OLD: %s", pieceOldLocation);
    printf("\n\n\n");
    printf("NEW: %s", pieceNewLocation);
    printf("\n\n\n");

    // get indices for board (e.g. convert e4 to x and y index)
    int oldY = pieceOldLocation[0] - 'a';
    int oldX = 8 - (pieceOldLocation[1] - '0');

    int newY = pieceNewLocation[0] - 'a';
    int newX = 8 - (pieceNewLocation[1] - '0');

    printf("%d %d\n", oldX, oldY);
    printf("%d %d\n", newX, newY);

    board[newX][newY] = board[oldX][oldY];
    board[oldX][oldY] = ' ';

    *isWhiteTurn ^= 1;

    print_board(board);
    make_move(isWhiteTurn, board);
}

void print_board(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            char output = board[i][j] == ' ' ? '~' : board[i][j];
            printf("%c ", output);
        }
        printf("\n");
    }
}
