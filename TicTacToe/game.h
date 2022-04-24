#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3


void menu(void);

void IniteBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void player_move(char board[ROW][COL], int row, int col);

void computer_move(char board[ROW][COL], int row, int col);

char judge(char board[ROW][COL], int row, int col);