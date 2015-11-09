/*
과제 ]] Enemy 를 맵에서 이동하기

□□□□□□□□□□
□□□□□□□□□□
□□㉿□□□□□□□	㉿ : enemy
□□□□□□T□□□
□□□□□□□□□□
□□□□□□★□□□	★ : destination
□□□□□□□□□□
□□□□□□□□□□

Enemy 구조체의 start 위치에서 enemy 시작
dest 위치를 추가로 넣고,
일정 시간마다 목적지로 이동하기

_sleep( 1000 )  1000 = 약 1 초
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

// 0부터 빈공간, 벽, 타워, 적, 타겟 으로 구성
enum Object
{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_TOWER,
	OBJ_ENEMY,
	OBJ_TARGET
};

// 가야할 방향을 표시하기 위해 만듬, 이하생략
enum Direction
{
	DRC_LEFT,
	DRC_RIGHT,
	DRC_UP,
	DRC_DOWN,
	DRC_LEFTUP,
	DRC_LEFTDOWN,
	DRC_RIGHTUP,
	DRC_RIGHTDOWN
};

struct POINT
{
	// 배열구조에 따른 좌표로 되어있어 int형이어야 하지만.. float형을 고집해봄
	float x;
	float y;
};

// 맵의 가로, 세로 크기
// main 위에 놓고 싶었는데 isSpaceWay도 필요로 하는 바람에 UNIT 구조체 위에서 선언함..ㅠ
static const int gStageWidth = 20;
static const int gStageHeight = 20;
// 마찬가지로 여러곳에서 쓰여서 전역변수로 선언
static Object stateMap[gStageWidth * gStageHeight] = {};

// isSpaceWay는 UNIT 구조체 내에서만 반복사용되고 쓰이지 않기때문에 UNIT만 알게하기 위해 밖에다가 만들고 UNIT에게 선언함
bool isSpaceWay(POINT *pPoint, Direction drcMark);
struct UNIT
{
	POINT m_point;		// 좌표값
	POINT m_wayPoint;	// 상대와의 좌표값 차
	char m_name[12];	// 이름
	float m_hp;			// 생명력
	float m_damage;		// 공격력
	float m_range;		// 공격범위

	// 상대와의 좌표값 차를 계산해서 대입해준다.
	void setWayPoint(POINT *_pPoint)
	{
		m_wayPoint = { m_point.x - _pPoint->x, m_point.y - _pPoint->y };
	}

	// 공격범위 안에 오면 true 안오면 false를 반환
	bool isinRange(POINT *_pPoint)
	{
		setWayPoint(_pPoint);
		//			(x좌표의 차)2제곱 + (y좌표 차)2제곱 에 루트를 씌운 값
		if (getRange() >= sqrt(pow(getWayPoint().x, 2) + pow(getWayPoint().y, 2)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// 대상 유닛이 공격범위 안에 있으면 공격
	void attack(UNIT *pVictim)
	{
		// 공격 범위에 있나 판단
		if (isinRange(&pVictim->getPoint()))
		{
			// 대상이 죽은적인지 확인 (제거가 안되서 죽었는지 여부를 묻는거로 대신함)
			if (!pVictim->isDead())
			{
				// 공격력 만큼 HP 감소
				pVictim->setHp(pVictim->getHp() - getDamage());
				printf("%s(은)는 %s에게 %.1f의 피해를 입혔다!     ", getName(), pVictim->getName(), getDamage());
				// HP가 0 이하면 죽음, 죽었다고 알려줌
				if (pVictim->getHp() <= 0)
				{
					pVictim->dead();
					printf("%sHP : %.1f\n", pVictim->getName(), pVictim->getHp());
					printf("%s(이)가 소멸하였다!\n", pVictim->getName());
				}
				else
				{
					// 현재 남아있는 대상의 HP를 띄움
					printf("%sHP : %.1f\n", pVictim->getName(), pVictim->getHp());
				}
			}

		}
	}

	void move()
	{
		// 거리좌표 x, y 값이 양수인지 음수인지 0인지 구분해서 가야할 곳이 빈공간인지 확인, 맞으면 좌표값 이동
		// 왼쪽으로 
		if (getWayPoint().x > 0 && getWayPoint().y == 0)
		{
			if (isSpaceWay(&getPoint(), DRC_LEFT))
			{
				setPoint(getPoint().x - 1.0f, getPoint().y);
			}
		}
		// 오른쪽으로
		else if (getWayPoint().x < 0 && getWayPoint().y == 0)
		{
			if (isSpaceWay(&getPoint(), DRC_RIGHT))
			{
				setPoint(getPoint().x + 1.0f, getPoint().y);
			}
		}
		// 위로
		else if (getWayPoint().x == 0 && getWayPoint().y > 0)
		{
			if (isSpaceWay(&getPoint(), DRC_UP))
			{
				setPoint(getPoint().x, getPoint().y - 1.0f);
			}
		}
		// 아래로
		else if (getWayPoint().x == 0 && getWayPoint().y < 0)
		{
			if (isSpaceWay(&getPoint(), DRC_DOWN))
			{
				setPoint(getPoint().x, getPoint().y + 1.0f);
			}
		}
		// 왼쪽 위로
		else if (getWayPoint().x > 0 && getWayPoint().y > 0)
		{
			if (isSpaceWay(&getPoint(), DRC_LEFTUP))
			{
				setPoint(getPoint().x - 0.5f, getPoint().y - 0.5f);
			}
		}
		// 왼쪽 아래로
		else if (getWayPoint().x > 0 && getWayPoint().y < 0)
		{
			if (isSpaceWay(&getPoint(), DRC_LEFTDOWN))
			{
				setPoint(getPoint().x - 0.5f, getPoint().y + 0.5f);
			}
		}
		//오른쪽 위로
		else if (getWayPoint().x < 0 && getWayPoint().y > 0)
		{
			if (isSpaceWay(&getPoint(), DRC_RIGHTUP))
			{
				setPoint(getPoint().x + 0.5f, getPoint().y - 0.5f);
			}
		}
		// 오른쪽 아래로
		else if (getWayPoint().x < 0 && getWayPoint().y < 0)
		{
			if (isSpaceWay(&getPoint(), DRC_RIGHTDOWN))
			{
				setPoint(getPoint().x + 0.5f, getPoint().y + 0.5f);
			}
		}
	}

	// 제거가 안되 모든 정보를 초기화하는거로 대신함
	void dead()
	{
		m_point = {};
		m_wayPoint = {};
		for (int x : m_name)	// 배열이라 하나하나 대입해줘야 해서 배열 for문 돌림
		{
			x = NULL;
		}
		m_hp = NULL;
		m_damage = NULL;
		m_range = NULL;
	}

	// 죽었는지 hp를 보고 판단하여 죽었으면 true, 안죽었으면 false를 반환
	bool isDead()
	{
		if (m_hp == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// 이하 set어쩌구는 값을 받아와서 대입시켜줌, get어쩌구는 값을 리턴시켜서 사용할 수 있게함	(흉내만 낸거니 의미는 없음..)
	void setPoint(float _x, float _y)
	{
		m_point.x = _x;
		m_point.y = _y;
	}

	void setName(char _pName[])
	{
		// 불특정 배열의 크기를 구해야해서 받아온 문자열배열 만큼 NULL값이 나올때까지 루프
		// NULL값이 나왓다고 바로 나오면 마지막 글자가 안들어가서 do while을 사용함
		int i = 0;
		do
		{
			m_name[i] = _pName[i];
			i += 1;
		} while (_pName[i] != NULL);
	}

	void setHp(float _hp)
	{
		m_hp = _hp;
	}

	void setDamage(float _damage)
	{
		m_damage = _damage;
	}

	void setRange(float _range)
	{
		m_range = _range;
	}

	POINT getWayPoint()
	{
		return m_wayPoint;
	}

	POINT getPoint()
	{
		return m_point;
	}

	char *getName()
	{
		return m_name;
	}

	float getHp()
	{
		return m_hp;
	}

	float getDamage()
	{
		return m_damage;
	}

	float getRange()
	{
		return m_range;
	}
};

bool isSpaceWay(POINT *pPoint, Direction drcMark)
{
	int nX = 1;				// X축으로 1칸씩 움직일 배열번호
	int nY = gStageWidth;	// Y축으로 1칸씩 움직일 배열번호
	int nArr = (int)(((int)pPoint->y * gStageWidth) + (int)pPoint->x);	//pPoint의 현재 좌표값의 배열번호

	// 가야할 방향이 어디쪽이고 그곳배열의 값이 OBJ_SPACE 이면 true, 아니면 false를 반환
	// 왼쪽으로
	if (drcMark == DRC_LEFT && stateMap[nArr - nX] == OBJ_SPACE)
	{
		return true;
	}
	// 오른쪽으로
	else if (drcMark == DRC_RIGHT && stateMap[nArr + nX] == OBJ_SPACE)
	{
		return true;
	}
	// 위쪽으로
	else if (drcMark == DRC_UP && stateMap[nArr - nY] == OBJ_SPACE)
	{
		return true;
	}
	// 아래쪽으로
	else if (drcMark == DRC_DOWN && stateMap[nArr + nY] == OBJ_SPACE)
	{
		return true;
	}
	// 왼쪽 위로
	else if (drcMark == DRC_LEFTUP && stateMap[(nArr - nX) - nY] == OBJ_SPACE)
	{
		return true;
	}
	// 왼쪽 아래로
	else if (drcMark == DRC_LEFTDOWN && stateMap[(nArr - nX) + nY] == OBJ_SPACE)
	{
		return true;
	}
	// 오른쪽 위로
	else if (drcMark == DRC_RIGHTUP && stateMap[(nArr + nX) - nY] == OBJ_SPACE)
	{
		return true;
	}
	// 오른쪽 아래로
	else if (drcMark == DRC_RIGHTDOWN && stateMap[(nArr + nX) + nY] == OBJ_SPACE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void initObject(UNIT *tower, UNIT *enemy, UNIT *target);
void drowingObject(Object stageObject);
bool isSpaceWay(POINT *pPoint, Direction drcMark);

void main()
{
	// 선언 및 초기화
	char cKey = 0;

	UNIT tower = {};
	tower.setPoint(16.0f, 15.0f);
	tower.setName("BowTower");
	tower.setHp(300.0f);
	tower.setDamage(5.0f);
	tower.setRange(3.0f);

	UNIT enemy = {};
	enemy.setPoint(1.0f, 1.0f);
	enemy.setName("Zombi");
	enemy.setHp(50.0f);
	enemy.setDamage(5.0f);
	enemy.setRange(2.0f);

	UNIT target = {};
	target.setPoint(18.0f, 18.0f);
	target.setName("Nexus");
	target.setHp(500.0f);
	target.setDamage(0.0f);
	target.setRange(0.0f);
	
	// 루프 시작
	while (cKey != 27)	// esc를 누르면 종료
	{
		// Object 배열 초기화
		initObject(&tower, &enemy, &target);
		
		// tower가 죽지 않았다면 tower는 enemy를 공격하라
		if (!tower.isDead())
		{
			tower.attack(&enemy);
		}
		
		// enemy가 죽지않았다면 enemy는 target을 공격하라
		// target과의 거리를 측정, 움직여라
		if (!enemy.isDead())
		{
			enemy.attack(&target);
			enemy.setWayPoint(&target.getPoint());
			enemy.move();
		}
		_sleep(1000);
		
		system("cls");
	}
}


// 반복문을 돌려가면서 Object[]에 해당하는 Object룰 넣어줌
void initObject(UNIT *tower, UNIT *enemy, UNIT *target)
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
			else if (tower != NULL && horz == tower->getPoint().x && vert == tower->getPoint().y)
			{
				stateMap[nArr] = OBJ_TOWER;
			}
			// 에너미의 경우
			else if (enemy != NULL && horz == (int)enemy->getPoint().x && vert == (int)enemy->getPoint().y && !enemy->isDead())
			{
				stateMap[nArr] = OBJ_ENEMY;
			}
			else if (target != NULL && horz == target->getPoint().x && vert == target->getPoint().y)
			{
				stateMap[nArr] = OBJ_TARGET;
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
		printf("□");
		break;

	case OBJ_WALL:
		printf("■");
		break;

	case OBJ_TOWER:
		printf("♠");
		break;

	case OBJ_ENEMY:
		printf("좀");
		break;

	case OBJ_TARGET:
		printf("◈");
		break;
	default:
		printf("\n\ndrowingObject 에서 ERROR!!\n\n");
		break;
	}
}