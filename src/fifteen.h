#ifndef FIFTEEN_H
#define FIFTEEN_H

#include <stdbool.h>

#define ROW 4
#define COL 4
#define SIZE 4
#define MAX_MOVES_EASY 30
#define MAX_MOVES_MEDIUM 20
#define MAX_MOVES_HARD 10

typedef enum {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
} Difficulty;

void clear_screen();
void create_board(int board[ROW][COL]);
void empty_tile(int board[ROW][COL], int *empty_row, int *empty_col);
void swap(int *a, int *b);
void user_movement(int board[ROW][COL], char input);
bool is_valid_input(char input);
bool is_solved(int board[ROW][COL]);
char get_valid_movement();
void print_board(int board[ROW][COL]);
void shuffle_board(int board[ROW][COL]);
int get_difficulty();

#endif