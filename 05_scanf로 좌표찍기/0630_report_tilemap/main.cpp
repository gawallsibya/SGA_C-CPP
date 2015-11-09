/*
과제 ]

기본 ] 타일 위치(좌표) 입력 : __ , __


입력한 한곳 □ -> ■

확장 ] 타일 위치 2개...
*/

#include <stdio.h>

void main()
{
	// 1. 좌표입력 
	// 2. □ 를 출력
	// 3. 입력된 좌표와 출력할 순서의 좌표를 비교
	// 4. □ 가 출력되는 중에 입력된 좌표값의 차례가 오면 ■를 출력

	int x = 0, y = 0;

	printf("타일 위치(좌표) 입력 : ");
	scanf("%d %d", &y, &x);
	printf("\n");
	for (int vert = 0; vert < 9; vert++)
	{
		for (int horz = 0; horz < 10; horz++)
		{
			vert == y && horz == x ? printf("■") : printf("□");
		}
		printf("\n");
	}

	printf("\n");

	//============

	// 타일위치 2개 가보자
	
	// ... 그냥 변수를 4개로 늘이고 두번 비교하면...
	// 두번 비교하기 보다는 || 를 넣어서 한번에

	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;

	printf("첫 번째 타일 위치(좌표) 입력 : ");
	scanf("%d %d", &y1, &x1);

	printf("두 번째 타일 위치(좌표) 입력 : ");
	scanf("%d %d", &y2, &x2);
	printf("\n");

	for (int vert = 0; vert < 9; vert++)
	{
		for (int horz = 0; horz < 10; horz++)
		{
			(vert == y1 && horz == x1) || (vert == y2 && horz == x2) ? printf("■") : printf("□");
		}
		printf("\n");
	}

	printf("\n");
}