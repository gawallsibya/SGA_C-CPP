/*
���ڿ� �����ϱ�

str1 ���� = "ȫ�浿" " ��浿" " ��쵿"
str2 ������ �ؼ� = " "
str3 ��� �ƴ� = " �� �ƴ�" "���ڰ� ���"

�����ϰ� �����ϱ�.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show(char str[20]);

void main()
{
	// ��.. �׳� ����Ҷ� ���� 0~4�� �������� �ٽ� �����鼭 ������ ��� �ݺ��ϸ� ��..
	// �򰥸��� �ʰ� 5����� �������
	char str1[5][20] = { "��Ʈ����", "��ģ��", "�ſ￡ ���� �����", "�ͽ���", "���л���" };
	char str2[5][20] = { "������ �¾Ƽ�", "���������� �ؼ�", "������ ���� ���", "���ڷ��� �Ǿ", "��2���� ���Ƽ�" };
	char str3[5][20] = { "�����ߴ�.", "�����ߴ�.", "��ȭ! �Ͽ���.", "����� �Ǿ���.", "��踦 ���ƴ�." };

	srand(time(NULL));

	while (true)
	{
		int num = rand()%5;
		show(str1[num]);

		num = rand() % 5;
		show(str2[num]);

		num = rand() % 5;
		show(str3[num]);

		printf("\n");
		system("pause");
		system("cls");
	}
}

void show(char str[20])
{
	printf("%s ", str);
}