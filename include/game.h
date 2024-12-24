#ifndef GAME_H
#define GAME_H
#define ROW 4
#define COL 4

#include "fifteen.h"

void game_loop(int board[ROW][COL], int difficulty, int *movements, int *remaining_moves);

#endif