#include "fifteen.h"
#include "game.h"
#include <stdio.h>

int main(void) {
    int board[ROW][COL];
    int difficulty = get_difficulty();

    create_board(board);
    shuffle_board(board);

    int movements;
    int remaining_moves;
    game_loop(board, difficulty, &movements, &remaining_moves);

    return 0;
}
