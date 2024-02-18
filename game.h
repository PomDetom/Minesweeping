#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINE 5

//��ʼ��
void initial_board(char board[ROWS][COLS], char initial_value);

//��ӡ
void print_board(char board[ROWS][COLS]);

//���õ���
void put_mine(char back_board[ROWS][COLS]);

//����
void find_mine(char show_board[ROWS][COLS], char back_board[ROWS][COLS]);

//��������
char count_mine(char back_board[ROWS][COLS], int x, int y);

//չ��һƬ
void spread_board(char back_board[ROWS][COLS], char show_board[ROWS][COLS], int x, int y);

//�ж�ʤ��
void judge(char show_board[ROWS][COLS],char back_board[ROWS][COLS]);
