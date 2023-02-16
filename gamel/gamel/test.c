#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("\n\t**********************************\n");
	printf("\t************ 【1】PLAY ***********\n");
	printf("\t************ 【0】EXIT ***********\n");
	printf("\t**********************************\n");
}
void game()
{
	//存储数据-二维数组
	char board[ROW][COL];
	//初始化棋盘-初始化空格
	InitBoard(board, ROW, COL);

	//打印棋盘的本质-打印数组内容
	DisplayBoard(board, ROW, COL);
	char ret = 0;//接收游戏状态

	while (1)
	{
		//玩家走
		PlayerMove(board,ROW,COL);
		printf("\n【棋子落下成功】\n\n");
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑走
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}

	if (ret == '*')
		printf("\n*** 玩家胜利 ***\n\n");
	else if (ret == '#')
		printf("\n### 电脑胜利 ###\n\n");
	else
		printf("\n【平局】\n\n");
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do
	{
		menu();
		printf("\n请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}//break跳出的是switch语句
	} while (input);
}

