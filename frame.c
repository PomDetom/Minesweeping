#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//�˵�
void menu()
{
	printf("*************************\n");
	printf("*********ɨ ��***********\n");
	printf("*******1.��ʼ��Ϸ********\n");
	printf("*******0.�˳���Ϸ********\n");
	printf("*************************\n");

}

//��Ϸ
void game()
{
	char show_board[ROWS][COLS] = { 0 };
	char back_board[ROWS][COLS] = { 0 };

	printf("����'*'��ʾδ֪�����ִ�����Χ�˸��м����ס�\n");
	printf("ʤ�������������пո��ҳ���\n");
	printf("���ȵ���ʱ����Ϸʧ�ܡ�\n");
	//���̳�ʼ��
	initial_board(show_board, '*');
	initial_board(back_board, '0');
	
	//���õ���
	put_mine(back_board);
	
	//��ӡ����
	print_board(show_board);
	//print_board(back_board);

	//����
	find_mine(show_board, back_board);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ��\n");
				break;
			default:
				printf("ѡ���������ѡ��\n");
				break;
		}
	} while (input);

	return 0;
}