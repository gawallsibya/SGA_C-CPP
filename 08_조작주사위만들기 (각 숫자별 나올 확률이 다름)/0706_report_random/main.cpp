/*
���� ]] ���� �ֻ��� �����

1	->	100 c			60 %
2	->	300 c			32 %
3	->	5000 c			4 %
4	->	20000 c			2 %
5	->	1000000 c		1 %
6	->	100000000 c		1 %
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

bool gatcha(int nMinNum, int nMaxNum, int nRand);

void main()
{
	int nMaxPercent = 100;	// �ִ� 100%

	int nList1 = 60;	// 60%
	int nList2 = 32;	// 32%
	int nList3 = 4;		// 4%
	int nList4 = 2;		// 2%
	int nList5 = 1;		// 1%
	int nList6 = 1;		// 1%

	int nDice = 0;		// rand ���� ����
	char cSelect = 0;	// y or n ������ ����

	nList6 = nMaxPercent;		// nList1 = 100
	nList5 = nList6 - nList5;	// nList2 = 99
	nList4 = nList5 - nList4;	// nList3 = 98
	nList3 = nList4 - nList3;	// nList4 = 96
	nList2 = nList3 - nList2;	// nList5 = 92
	nList1 = nList2 - nList1;	// nList6 = 60
	
	while (true)
	{
		// random ���� ����
		nDice = (rand() % 100) + 1;

		// �Ұ��� ������
		printf("�ֻ����� �����ּ���. ( y / n )\n\n");
		cSelect = getch();

		// ���ǿ����� ���
		if (cSelect == 'y')
		{
			// 1 : 0 < nRandom <= 60	60%
			if (gatcha(0, nList1, nDice))
			{
				printf(" 1 !\n\n");
				printf("100 c ��÷!!\n\n\n");
			}
			// 2 : 60 < nRandom <= 92	32%
			else if (gatcha(nList1, nList2, nDice))
			{
				printf(" 2 !!\n\n");
				printf("300 c ��÷!!\n\n\n");
			}
			// 3 : 92 < nRandom <= 96	4%
			else if (gatcha(nList2, nList3, nDice))
			{
				printf(" 3 !!!\n\n");
				printf("5000 c ��÷!!\n\n\n");
			}
			// 4 : 96 < nRandom <= 98	2%
			else if (gatcha(nList3, nList4, nDice))
			{
				printf(" 4 !!!!\n\n");
				printf("20000 c ��÷!!\n\n\n");
			}
			// 5 : 98 < nRandom <= 99	1%
			else if (gatcha(nList4, nList5, nDice))
			{
				printf(" 5 !!!!!\n\n");
				printf("1000000 c ��÷!!\n\n\n");
			}
			// 6 : 99 < nRandom <= 100	1%
			else if (gatcha(nList5, nList6, nDice))
			{
				printf(" 6 !!!!!!\n\n");
				printf("100000000 c ��÷!!\n\n\n");
			}
			system("pause");
		}
		else if (cSelect == 'n')
		{
			break;
		}
		system("cls");
	}
}

// �̱� ��÷ ���� ���� �� ���� Ȯ��
bool gatcha(int nMinNum, int nMaxNum, int nRand)
{
	if (nRand > nMinNum && nRand <= nMaxNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}