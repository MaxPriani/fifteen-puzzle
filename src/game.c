#include <stdio.h>
#include "game.h"

void game_loop(int board[ROW][COL], int difficulty, int *movements, int *remaining_moves) {

    *movements = 0;
    *remaining_moves = difficulty;
    while (!is_solved(board) && *remaining_moves != 0) {

        clear_screen();
        printf("=== FIFTEEN ===\n");
        print_board(board);

        printf("Controls: 'w', 'a', 's', 'd' \n");
        printf("Press 'q' to exit\n");
        printf("Movements: %d (%d remaining)\n", *movements, *remaining_moves);
        char input = get_valid_movement();

        if (input == 'q') {
            break;
        }

        user_movement(board, input);
        (*movements)++;
        (*remaining_moves)--;
    }

    if (!is_solved(board)) {
        clear_screen();
        printf("You've reached the maximum of movements (%d)\n", difficulty);
        printf("Better luck next time!\n");
    } else {
        clear_screen();
        printf("You've won in %d moves!\n", *movements);
        printf("Congratulations!\n");
    }
}