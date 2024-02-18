#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINE 5

//初始化
void initial_board(char board[ROWS][COLS], char initial_value);

//打印
void print_board(char board[ROWS][COLS]);

//布置地雷
void put_mine(char back_board[ROWS][COLS]);

//排雷
void find_mine(char show_board[ROWS][COLS], char back_board[ROWS][COLS]);

//计算雷数
char count_mine(char back_board[ROWS][COLS], int x, int y);

//展开一片
void spread_board(char back_board[ROWS][COLS], char show_board[ROWS][COLS], int x, int y);

//判断胜利
void judge(char show_board[ROWS][COLS],char back_board[ROWS][COLS]);
