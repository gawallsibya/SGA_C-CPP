/*

�ѱ��ھ� Ÿ�����ؼ� Ʋ���κ��� ���� ����.

��)
�־��� ����	] a rolling stone gathers no moss
Ÿ����		] a r_ll_ng s_one gathers no moss

�⺻	 ] �� ���ڰ� Ʋ�Ƚ��ϴ�. :: ___

Ȯ�� ] Ÿ���� �Ϸ���� �ɸ��ð� :: ___

���� >> ���� ������ ���ڿ� �Է�
scanf("%[^\n]", string);

Ȯ��2 ] Ʋ�� �κ� ����

*/


#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	char strA[] = "a rolling stone gathers no moss";	// ���� ����
	char strB[255] = {};								// �Է� ����
	char strC[255] = {};								// Ʋ�� ��ġ
	int nCount = 0;										// ��Ÿ ����
	int nLength = sizeof(strA) / sizeof(char);			// strA �� �迭 ����
	clock_t tTime = 0;									// ���� �ð�
	char cSwitch = 0;									// enter or esc�� ���� ����
	float fResTime = 0;									// �ɸ� �ð�

	while (cSwitch != 27)
	{
		nCount = 0;

		printf("�����Ϸ��� enter, �����Ϸ��� esc\n");

		cSwitch = getch();

		if (cSwitch == 13)
		{
			tTime = clock();

			printf("�־��� ����	] ");
			printf("%s\n", strA);

			printf("Ÿ����		] ");
			fflush(stdin);
			scanf("%[^\n]", strB);

			// ����ð��� ���۽ð��� �� �� 1000���� ���� -> clock�� 1�ʰ� 1000�̱� ������
			fResTime = (float)(clock() - tTime) / CLK_TCK;	// CLK_TC�� == 1000

			// �־��� ����� Ÿ���� ����� �迭�� �� �־��������� ���̸�ŭ ���鼭 ��
			// strC �� ������ġ�� ' '�� �ѱ�� Ʋ�� ��ġ�� '^' �� �־� ǥ��
			// \0 �� �Ǿ� ������ ' '�� ���� �ʰ� ������ �߰�
			for (int i = 0; i < nLength; i++)
			{
				if (strA[i] != strB[i] && strA[i] != '\0')
				{
					nCount += 1;
					strC[i] = '^';
				}
				else if (strA[i] == strB[i] && strA[i] != '\0')
				{
					strC[i] = ' ';
				}
			}
			printf("Ʋ�� �κ�   	] %s\n\n", strC);
			printf("��Ÿ Ƚ�� ::%d\n\n", nCount);
			printf("Ÿ���� �Ϸ���� �ɸ��ð� :: %.2f ��\n\n", fResTime);

			system("pause");
			system("cls");
		}
		else
		{
			system("cls");
		}

	}
}