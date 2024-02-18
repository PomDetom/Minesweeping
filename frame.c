#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//菜单
void menu()
{
	printf("*************************\n");
	printf("*********扫 雷***********\n");
	printf("*******1.开始游戏********\n");
	printf("*******0.退出游戏********\n");
	printf("*************************\n");

}

//游戏
void game()
{
	char show_board[ROWS][COLS] = { 0 };
	char back_board[ROWS][COLS] = { 0 };

	printf("规则：'*'表示未知，数字代表周围八格有几个雷。\n");
	printf("胜利条件：将所有空格找出。\n");
	printf("当踩到雷时，游戏失败。\n");
	//棋盘初始化
	initial_board(show_board, '*');
	initial_board(back_board, '0');
	
	//布置地雷
	put_mine(back_board);
	
	//打印棋盘
	print_board(show_board);
	//print_board(back_board);

	//排雷
	find_mine(show_board, back_board);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏。\n");
				break;
			default:
				printf("选择错误，重新选择。\n");
				break;
		}
	} while (input);

	return 0;
}