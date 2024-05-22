#include <stdio.h>
#include <string.h>

#define ROWS 8
#define COLS 8

void make_move(char turn[5], char board[ROWS][COLS]);
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

    char turn[5] = "WHITE";

    make_move(turn, board);

    return 1;
}

void make_move(char turn[5], char board[ROWS][COLS])
{
    char pc_oldlc[30];
    char pc_newlc[30];

    printf("[%s] Piece to move: \n", turn);
    scanf("%s", pc_oldlc);
    printf("[%s] Piece new location: \n", turn);
    scanf("%s", pc_newlc);

    // get indices for board (e.g. convert e4 to x and y index)
    int oy = pc_oldlc[0] - 'a';
    int ox = 8 - (pc_oldlc[1] - '0');

    int ny = pc_newlc[0] - 'a';
    int nx = 8 - (pc_newlc[1] - '0');

    printf("%d %d\n", ox, oy);
    printf("%d %d\n", nx, ny);

    board[nx][ny] = board[ox][oy];
    board[ox][oy] = ' ';

    print_board(board);

    if (strcmp(turn, "WHITE") == 0)
    {
        turn = "BLACK";
    }
    else if (strcmp(turn, "BLACK") == 0)
    {
        turn = "WHITE";
    }

    make_move(turn, board);
}

void print_board(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == ' ')
            {
                printf("~ ");
            }
            else
            {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}
