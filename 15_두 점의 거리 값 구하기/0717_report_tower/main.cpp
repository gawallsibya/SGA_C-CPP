/*
과제 ] 두 점 사이 거리 구하기

struct POINT
{ x , y }


거리 = calcDistance( &p1, &p2 );

POINT tower
POINT enemy
BOOL = tower.isinRange( &enemy );
-> "발사" , " "


[[ 두 점 사이 거리 공식 활용 ]]
#include <math.h>
pow( ,n)	->	n제곱승
sqrt( )		->	제곱근 ( 루트 연산 )

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

struct POINT
{
	int x;
	int y;
	int attackRange;

	bool isinRange(POINT *enemy)
	{
		//			(x좌표의 차)2제곱 + (y좌표 차)2제곱 에 루트를 씌운 값
		double objectRange = sqrt(pow((double)x - (double)enemy->x, 2) + pow((double)y - (double)enemy->y, 2));
		if (attackRange >= objectRange)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

enum Object
{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_TOWER,
	OBJ_ENEMY,
};

const int gStageWidth = 20;
const int gStageHeight = 20;

void initObject(POINT *tower, POINT *enemy, Object *stateMap);
void drowingGuide();
void enemyUpdate(char pKey, POINT *enemy, Object *stateMap);
void drowingObject(Object stageObject);

void main()
{
	char cKey = 0;
	Object stateMap[gStageWidth * gStageHeight] = {};
	POINT tower = { 9, 9, 5 };
	POINT enemy = { 2, 2, 0 };

	while (cKey != 27)
	{
		drowingGuide();

		initObject(&tower, &enemy, stateMap);

		if (tower.isinRange(&enemy))
		{
			printf("발사!\n");
		}
		
		// 입력받은 키값을 key변수에 대입
		cKey = getch();
		if (_kbhit())
		{
			cKey = getch();
			enemyUpdate(cKey, &enemy, stateMap);
		}


		system("cls");
	}
}
// 반복문을 돌려가면서 Object[]에 해당하는 Object룰 넣어줌
void initObject(POINT *tower, POINT *enemy, Object stateMap[])
{
	int nArr = 0;
	for (int vert = 0; vert < gStageHeight; vert++)
	{
		for (int horz = 0; horz < gStageWidth; horz++)
		{
			// 벽일경우
			if (vert == 0 || vert == gStageHeight - 1 || horz == 0 || horz == gStageWidth - 1)
			{
				stateMap[nArr] = OBJ_WALL;
			}
			// 타워의 경우
			else if (horz == tower->x && vert == tower->y)
			{
				stateMap[nArr] = OBJ_TOWER;
			}
			// 에너미의 경우
			else if (horz == enemy->x && vert == enemy->y)
			{
				stateMap[nArr] = OBJ_ENEMY;
			}
			else
			{
				stateMap[nArr] = OBJ_SPACE;
			}
			drowingObject(stateMap[nArr]);
			nArr += 1;
		}
		printf("\n");
	}
}

// Object에 담아온 숫자를 해당 문자로 출력
void drowingObject(Object stageObject)
{
	switch (stageObject)
	{
	case OBJ_SPACE:
		printf("　");
		break;

	case OBJ_WALL:
		printf("■");
		break;

	case OBJ_TOWER:
		printf("∏");
		break;

	case OBJ_ENEMY:
		printf("∇");
		break;
	default:
		printf("\n\ndrowingObject 에서 ERROR!!\n\n");
		break;
	}
}

// 안내문 출력
void drowingGuide()
{
	printf("     << 방 향 키 >>\n");
	printf("UP : ↑     DOWN : ↓     LEFT : ←     RIGHT : →     종료 : ESC\n");
}

// 방향키 이동시 에너미가 들어있는 배열을 구분해 이동할 곳이 빈 공간일 경우만 이동 가능하게 해줌
void enemyUpdate(char pKey, POINT *enemy, Object *stateMap)
{
	int nX = 1;
	int nY = gStageWidth;
	int nArr = (int)(enemy->y * gStageWidth) + enemy->x;

	
	// LEFT
	if (pKey == 75 && stateMap[nArr - nX] == OBJ_SPACE)
	{
		enemy->x -= 1;
	}
	// RIGHT
	else if (pKey == 77 && stateMap[nArr + nX] == OBJ_SPACE)
	{
		enemy->x += 1;
	}
	// UP
	else if (pKey == 72 && stateMap[nArr - nY] == OBJ_SPACE)
	{
		enemy->y -= 1;
	}
	// DOWN
	else if (pKey == 80 && stateMap[nArr + nY] == OBJ_SPACE)
	{
		enemy->y += 1;
	}
}