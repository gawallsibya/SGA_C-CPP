/*
	����ٺ��� �ȹ��� ���� �ʰ�� ������ڴ�..
	������� ������ ���� �ٲ㼭 ���ŷθ� ������
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	int x = 0, y = 0;			// Ÿ�� ��ǥ
	int sizeX = 10, sizeY = 9;	// ���� ũ��
	char key = 0;				// ����Ű

	// ������ ��ǥ �Է�
	printf("Ÿ�� ��ġ(��ǥ) �Է� : ");
	scanf("%d %d", &y, &x);

	printf("\n");

	// �ݺ��ϸ鼭 �����϶����� ȭ���� �ٽ� �׸�
	// ���� ���� : ESC
	while (key != 27)
	{
		// ����� ���ӵ� �������ϴ� ȭ���� ����
		system("cls");

		// ���� �׸�
		printf("\n");
		for (int vert = 0; vert < sizeY; vert++)
		{
			for (int horz = 0; horz < sizeX; horz++)
			{
				vert == y && horz == x ? printf("��") : printf("��");
			}
			// ����Ű �ȳ� �ؽ�Ʈ �� ���� 0, 2 ,4 ,6, 8��° �ٿ� �ؽ�Ʈ ����
			if (vert == 0)
			{
				printf("     << �� �� Ű >>");
			}
			if (vert == 2)
			{
				printf("       UP	 : �� ");
			}
			if (vert == 4)
			{
				printf("       DOWN	 : �� ");
			}
			if (vert == 6)
			{
				printf("       LEFT	 : �� ");
			}
			if (vert == 8)
			{
				printf("       RIGHT : �� ");
			}
			printf("\n");
		}
		// ���� ��ǥ�� ǥ��
		printf("(%d, %d)\n\n", y, x);
		printf("\n");

		printf("���α׷� ���� : ESC\n\n");


		// �Է¹��� Ű���� key������ ����
		key = getch();

		// key�� ���� �� ����Ű�� AsciiCode���� ��ġ and ���� �Ѿ���� Ȯ���Ͽ� �� �� true�� ��� �ش� ��ǥ���� ����
		// LEFT
		if (key == 75 && x > 0)
		{
			x -= 1;
		}
		// RIGHT
		if (key == 77 && x < sizeX - 1)
		{
			x += 1;
		}
		// UP
		if (key == 72 && y > 0)
		{
			y -= 1;
		}
		// DOWN
		if (key == 80 && y < sizeY - 1)
		{
			y += 1;
		}
	}
	
}