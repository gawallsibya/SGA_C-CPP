/*
	���� ������� ���� ����ϴ� �׳� �켱 �����ؿͼ� ��ġ��
*/

#include <stdio.h>

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
	// ���� ���� : X
	while (key != 'x' )
	{
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
				printf("       UP	 : W ");
			}
			if (vert == 4)
			{
				printf("       DOWN	 : S ");
			}
			if (vert == 6)
			{
				printf("       LEFT	 : A ");
			}
			if (vert == 8)
			{
				printf("       RIGHT : D ");
			}
			printf("\n");
		}
		// ���� ��ǥ�� ǥ��
		printf("(%d, %d)\n\n", y, x);
		printf("\n");

		printf("���α׷� ���� : X\n\n");


		// ����Ű���� �Է�
		fflush(stdin);
		scanf("%c", &key);

		// �Էµ� ���� �ش� ����Ű�� ��, �ҹ��ڸ� ������ �´��� Ȯ�� and ���� �Ѿ���� Ȯ���Ͽ� �� �� true�� ��� �ش� ��ǥ���� ����
		// LEFT
		if ((key == 'a' || key == 'A') && x > 0)
		{
			x -= 1;
		}
		// RIGHT
		if ((key == 'd' || key == 'D') && x < sizeX - 1)
		{
			x += 1;
		}
		// UP
		if ((key == 'w' || key == 'W') && y > 0)
		{
			y -= 1;
		}
		// DOWN
		if ((key == 's' || key == 'S') && y < sizeY - 1)
		{
			y += 1;
		}
	}
}