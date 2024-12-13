#include "fifteen.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_screen() {
    system("clear");
}

void create_board(int board[ROW][COL]) {
    int n = 1;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (n <= 15) {
                board[i][j] = n;
                n++;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void empty_tile(int board[ROW][COL], int *empty_row, int *empty_col) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == 0) {
                *empty_row = i;
                *empty_col = j;
                return;
            }
        }
    }
}

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void user_movement(int board[ROW][COL], char input) {
    int row, col;
    empty_tile(board, &row, &col);

    switch (input) {
        case 'w':
            if (row > 0) {
                swap(&board[row][col], &board[row - 1][col]);
            }
            break;
        case 's':
            if (row < SIZE - 1) {
                swap(&board[row][col], &board[row + 1][col]);
            }
            break;
        case 'a':
            if (col > 0) {
                swap(&board[row][col], &board[row][col - 1]);
            }
            break;
        case 'd':
            if (col < SIZE - 1) {
                swap(&board[row][col], &board[row][col + 1]);
            }
            break;
    }
}

bool is_valid_input(char input) {
    return (input == 'w' || input == 's' || input == 'a' || input == 'd');
}

bool is_solved(int board[ROW][COL]) {
    int n = 1;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == ROW - 1 && j == COL - 1) {
                if (board[i][j] != 0) return false;
            } else {
                if (board[i][j] != n) return false;
                n++;
            }
        }
    }
    return true;
}

char get_valid_movement() {
    char input;
    printf("Input: ");
    scanf(" %c", &input);

    while (!is_valid_input(input) && input != 'q') {
        printf("Invalid input, use {'w', 'a', 's', 'd'}\n");
        printf("Input: ");
        scanf(" %c", &input);
    }

    return input;
}

void print_board(int board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == 0) {
                printf("  _");
            } else {
                printf(" %2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void shuffle_board(int board[ROW][COL]) {
    srand(time(NULL));

    for (int i = 0; i < 25; i++) {
        int row, col;
        empty_tile(board, &row, &col);

        int movement = rand() % 4;
        char moves[] = {'w', 's', 'a', 'd'};

        switch (moves[movement]) {
            case 'w':
                if (row > 0) user_movement(board, 'w');
                break;
            case 's':
                if (row < SIZE - 1) user_movement(board, 's');
                break;
            case 'a':
                if (col > 0) user_movement(board, 'a');
                break;
            case 'd':
                if (col < SIZE - 1) user_movement(board, 'd');
                break;
        }
    }
}

int get_difficulty() {
    Difficulty difficulty;

    printf("=== FIFTEEN ===\n");
    printf("Select Difficulty:\n");
    printf("1. EASY (30 movements)\n");
    printf("2. MEDIUM (20 movements)\n");
    printf("3. HARD (10 movements)\n");
    printf("Choice: ");
    scanf("%d", &difficulty);

    switch (difficulty) {
        case EASY:
            difficulty = MAX_MOVES_EASY;
            break;
        case MEDIUM:
            difficulty = MAX_MOVES_MEDIUM;
            break;
        case HARD:
            difficulty = MAX_MOVES_HARD;
            break;
        default:
            difficulty = MAX_MOVES_EASY;
            break;
    }

    return difficulty;
}
