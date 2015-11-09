/*
���� ] �� �� ���� �Ÿ� ���ϱ�

struct POINT
{ x , y }


�Ÿ� = calcDistance( &p1, &p2 );

POINT tower
POINT enemy
BOOL = tower.isinRange( &enemy );
-> "�߻�" , " "


[[ �� �� ���� �Ÿ� ���� Ȱ�� ]]
#include <math.h>
pow( ,n)	->	n������
sqrt( )		->	������ ( ��Ʈ ���� )

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
		//			(x��ǥ�� ��)2���� + (y��ǥ ��)2���� �� ��Ʈ�� ���� ��
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
			printf("�߻�!\n");
		}
		
		// �Է¹��� Ű���� key������ ����
		cKey = getch();
		if (_kbhit())
		{
			cKey = getch();
			enemyUpdate(cKey, &enemy, stateMap);
		}


		system("cls");
	}
}
// �ݺ����� �������鼭 Object[]�� �ش��ϴ� Object�� �־���
void initObject(POINT *tower, POINT *enemy, Object stateMap[])
{
	int nArr = 0;
	for (int vert = 0; vert < gStageHeight; vert++)
	{
		for (int horz = 0; horz < gStageWidth; horz++)
		{
			// ���ϰ��
			if (vert == 0 || vert == gStageHeight - 1 || horz == 0 || horz == gStageWidth - 1)
			{
				stateMap[nArr] = OBJ_WALL;
			}
			// Ÿ���� ���
			else if (horz == tower->x && vert == tower->y)
			{
				stateMap[nArr] = OBJ_TOWER;
			}
			// ���ʹ��� ���
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

// Object�� ��ƿ� ���ڸ� �ش� ���ڷ� ���
void drowingObject(Object stageObject)
{
	switch (stageObject)
	{
	case OBJ_SPACE:
		printf("��");
		break;

	case OBJ_WALL:
		printf("��");
		break;

	case OBJ_TOWER:
		printf("��");
		break;

	case OBJ_ENEMY:
		printf("��");
		break;
	default:
		printf("\n\ndrowingObject ���� ERROR!!\n\n");
		break;
	}
}

// �ȳ��� ���
void drowingGuide()
{
	printf("     << �� �� Ű >>\n");
	printf("UP : ��     DOWN : ��     LEFT : ��     RIGHT : ��     ���� : ESC\n");
}

// ����Ű �̵��� ���ʹ̰� ����ִ� �迭�� ������ �̵��� ���� �� ������ ��츸 �̵� �����ϰ� ����
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