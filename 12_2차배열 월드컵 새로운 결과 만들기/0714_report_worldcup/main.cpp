/*
���� ]] ������ ���... ������ �� ����..

1���� [] [] [] []   [] [] [] []		// 8��	char *pQuaterFinal[8] = ???
2����   []   []	   []    []			// 4��	char *pSemiFinal[4] = ???
3����     []             []			// 2��	char *pFinal[2] = ???
4����            []					// 1��	char *pWinner = ???
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main()
{
	// �迭�� �����Ϳ� �Ҵ��ϴ°ŷ�
	char *pQuaterFinal[8] = {};		// 8��
	char *pSemiFinal[4] = {};		// 4��
	char *pFinal[2] = {};			// 2��
	char *pWinner = 0;				// ���

	char pNation[8][20] = {};		// ���� ����� 8����
	int nRandom = 0;				//	0 or 1 1/2Ȯ��

	srand(time(NULL));

	while (true)
	{
		// ���� ���� �Է¹ޱ�
		for (int i = 0; i < 8; i++)
		{
			fflush(stdin);
			printf("%d. ", i+1);
			scanf("%s", pNation[i]);
			// �Է¹��� ���� 8���� ����ش�
			pQuaterFinal[i] = pNation[i];
		}
		getch();

		// 8��
		// 12 34 56 78 ������ �ٿ��� ���� �ϳ��� �ø���.
		// i, j �ΰ� �����ؼ� i+=1, j+=2 �� �� �������� �÷��ش�
		printf("\n4�� ���� : ");
		for (int i = 0, j = 0; i < 4; i+=1, j+=2)
		{
			nRandom = rand() % 2;
			// 0�̸� ����, 1�̸� ���ڰ� ����
			nRandom == 0 ? pSemiFinal[i] = pQuaterFinal[j] : pSemiFinal[i] = pQuaterFinal[j + 1];

			printf("%s ", pSemiFinal[i]);
		}
		printf("\n");
		getch();

		// 4��
		//  8���� �������
		printf("\n��� ���� : ");
		for (int i = 0, j = 0; i < 2; i += 1, j += 2)
		{
			nRandom = rand() % 2;
			// 0�̸� ����, 1�̸� ���ڰ� ����
			nRandom == 0 ? pFinal[i] = pSemiFinal[j] : pFinal[i] = pSemiFinal[j + 1];

			printf("%s ", pFinal[i]);
		}
		printf("\n");
		getch();

		// 2��
		// �ݺ��� �ʿ������ �׳� ó��
		nRandom = rand() % 2;
		nRandom == 0 ? pWinner = pFinal[0] : pWinner = pFinal[1];
		
		// ���
		printf("\n��� : %s\n\n", pWinner);

		system("pause");
		system("cls");

	}
}