/*
���� ]

�⺻ ] Ÿ�� ��ġ(��ǥ) �Է� : __ , __


�Է��� �Ѱ� �� -> ��

Ȯ�� ] Ÿ�� ��ġ 2��...
*/

#include <stdio.h>

void main()
{
	// 1. ��ǥ�Է� 
	// 2. �� �� ���
	// 3. �Էµ� ��ǥ�� ����� ������ ��ǥ�� ��
	// 4. �� �� ��µǴ� �߿� �Էµ� ��ǥ���� ���ʰ� ���� �Ḧ ���

	int x = 0, y = 0;

	printf("Ÿ�� ��ġ(��ǥ) �Է� : ");
	scanf("%d %d", &y, &x);
	printf("\n");
	for (int vert = 0; vert < 9; vert++)
	{
		for (int horz = 0; horz < 10; horz++)
		{
			vert == y && horz == x ? printf("��") : printf("��");
		}
		printf("\n");
	}

	printf("\n");

	//============

	// Ÿ����ġ 2�� ������
	
	// ... �׳� ������ 4���� ���̰� �ι� ���ϸ�...
	// �ι� ���ϱ� ���ٴ� || �� �־ �ѹ���

	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;

	printf("ù ��° Ÿ�� ��ġ(��ǥ) �Է� : ");
	scanf("%d %d", &y1, &x1);

	printf("�� ��° Ÿ�� ��ġ(��ǥ) �Է� : ");
	scanf("%d %d", &y2, &x2);
	printf("\n");

	for (int vert = 0; vert < 9; vert++)
	{
		for (int horz = 0; horz < 10; horz++)
		{
			(vert == y1 && horz == x1) || (vert == y2 && horz == x2) ? printf("��") : printf("��");
		}
		printf("\n");
	}

	printf("\n");
}