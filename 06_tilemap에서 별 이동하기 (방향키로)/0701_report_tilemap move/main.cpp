/*
	만들다보니 안배운걸 쓰지 않고는 못만들겠다..
	만들고나면 조건을 조금 바꿔서 배운거로만 만들자
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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
	// 종료 조건 : ESC
	while (key != 27)
	{
		// 출력이 연속되 지저분하니 화면을 정리
		system("cls");

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
				printf("       UP	 : ↑ ");
			}
			if (vert == 4)
			{
				printf("       DOWN	 : ↓ ");
			}
			if (vert == 6)
			{
				printf("       LEFT	 : ← ");
			}
			if (vert == 8)
			{
				printf("       RIGHT : → ");
			}
			printf("\n");
		}
		// 현재 좌표를 표시
		printf("(%d, %d)\n\n", y, x);
		printf("\n");

		printf("프로그램 종료 : ESC\n\n");


		// 입력받은 키값을 key변수에 대입
		key = getch();

		// key의 값이 각 방향키의 AsciiCode값과 일치 and 맵을 넘어가는지 확인하여 둘 다 true일 경우 해당 좌표값을 변경
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