#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("\n\t**********************************\n");
	printf("\t************ ��1��PLAY ***********\n");
	printf("\t************ ��0��EXIT ***********\n");
	printf("\t**********************************\n");
}
void game()
{
	//�洢����-��ά����
	char board[ROW][COL];
	//��ʼ������-��ʼ���ո�
	InitBoard(board, ROW, COL);

	//��ӡ���̵ı���-��ӡ��������
	DisplayBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬

	while (1)
	{
		//�����
		PlayerMove(board,ROW,COL);
		printf("\n���������³ɹ���\n\n");
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ��Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ��Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}

	if (ret == '*')
		printf("\n*** ���ʤ�� ***\n\n");
	else if (ret == '#')
		printf("\n### ����ʤ�� ###\n\n");
	else
		printf("\n��ƽ�֡�\n\n");
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do
	{
		menu();
		printf("\n��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}//break��������switch���
	} while (input);
}

