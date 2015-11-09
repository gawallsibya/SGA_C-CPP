/*
	막상 만들려니 거의 비슷하니 그냥 우선 복사해와서 고치자
*/

#include <stdio.h>

void main()
{
	int x = 0, y = 0;			// 타겟 좌표
	int sizeX = 10, sizeY = 9;	// 맵의 크기
	char key = 0;				// 방향키

	// 최초의 좌표 입력
	printf("타일 위치(좌표) 입력 : ");
	scanf("%d %d", &y, &x);

	printf("\n");

	// 반복하면서 움직일때마다 화면을 다시 그림
	// 종료 조건 : X
	while (key != 'x' )
	{
		// 맵을 그림
		printf("\n");
		for (int vert = 0; vert < sizeY; vert++)
		{
			for (int horz = 0; horz < sizeX; horz++)
			{
				vert == y && horz == x ? printf("★") : printf("□");
			}
			// 방향키 안내 텍스트 맵 기준 0, 2 ,4 ,6, 8번째 줄에 텍스트 삽입
			if (vert == 0)
			{
				printf("     << 방 향 키 >>");
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
		// 현재 좌표를 표시
		printf("(%d, %d)\n\n", y, x);
		printf("\n");

		printf("프로그램 종료 : X\n\n");


		// 방향키값를 입력
		fflush(stdin);
		scanf("%c", &key);

		// 입력된 값이 해당 방향키의 대, 소문자를 포함해 맞는지 확인 and 맵을 넘어가는지 확인하여 둘 다 true일 경우 해당 좌표값을 변경
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