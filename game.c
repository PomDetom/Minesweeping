#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//初始化
void initial_board(char board[ROWS][COLS], char initial_value)
{
	int i = 0;

	for (i = 0; i < ROWS; i++)
	{
		int j = 0;

		for (j = 0; j < COLS; j++)
		{
			board[i][j] = initial_value;
		}
	}
}

//打印
void print_board(char board[ROWS][COLS])
{
	int i = 1;

	printf("-------扫雷-------\n");
	for (i = 0; i < ROW + 1; i++)
	{
		printf("%d ", i);
	}

	printf("\n");

	for (i = 1; i < ROW + 1; i++)
	{
		int j = 1;
		
		printf("%d ", i);
		for (j = 1; j < COL + 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------扫雷-------\n");

}

//布置地雷
void put_mine(char back_board[ROWS][COLS])
{
	int count = MINE;
	
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;

		if (back_board[x][y] == '0')
		{
			back_board[x][y] = '1';
			count--;
		}
	}
}

//排雷
void find_mine(char show_board[ROWS][COLS], char back_board[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		//判断胜利
		judge(show_board,back_board);

		printf("请输入坐标（如5 8）：");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= ROW && y > 0 && y <= COL)
		{
			if (show_board[x][y] == '*')
			{
				if (back_board[x][y] == '1')
				{
					print_board(back_board); 
					printf("踩到地雷，游戏结束！\n");
					break;
				}
				else if (back_board[x][y] == '0')
				{
					spread_board(back_board, show_board, x, y);
					print_board(show_board);
				}
			}
			else
			{
				printf("已排雷，重新选择。\n");
			}
		}
		else
		{
			printf("坐标不合法！\n");
		}
	}
}

//计算雷数
char count_mine(char back_board[ROWS][COLS], int x, int y)
{
	char count = '0';
	int i = x;
	for (i = x; i < x + 3; i++)
	{
		int j = y;
		for (j = y; j < y + 3; j++)
		{
			count += (back_board[i - 1][j - 1] - '0');
		}
	}
	return count;
}

//展开一片
void spread_board(char back_board[ROWS][COLS], char show_board[ROWS][COLS], int x, int y)
{
	int i = x;

	if (x > 0 && x <= ROW && y > 0 && y <= COL && show_board[x][y] == '*' && back_board[x][y] == '0')
	{
		if (count_mine(back_board, x, y) == '0')
		{
			show_board[x][y] = '0';
			for (i = x; i < x + 3; i++)
			{
				int j = y;

				for (j = y; j < y + 3; j++)
				{
					spread_board(back_board, show_board, i - 1, j - 1);
				}
			}
		}
		else
		{
			show_board[x][y] = count_mine(back_board, x, y);
		}
	}
}

//判断胜利
void judge(char show_board[ROWS][COLS], char back_board[ROWS][COLS])
{
	int x = 0;
	int count = 0;
	
	for (x = 1; x <= ROW; x++)
	{
		int y = 0;
		for (y = 1; y <= COL; y++)
		{
			if (show_board[x][y] == '*')
			{
				count++;
			}
		}
	}
	if (count == MINE)
	{
		printf("游戏胜利！\n");
	}
}
