/*
메모장으로 그린 맵 이미지 불러와서 화면 출력

타일맵 불러오기 ( 크기는 고정 설정 )

주의 ]	특수문자는 2byte이고
각 열의 끝에는 null 문자 있음을 고려

확장 ] 캐릭터가 이동, 세이브포인트에 도착할시 저장되어 로드시 세이브포인트부터 시작
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

// 0부터 빈공간, 벽, 타워, 적, 타겟 으로 구성

#define SPACE '0'
#define WALL '1'
#define TOWER '2'
#define PLAYER '3'
#define TARGET '4'
#define SAVEPOINT '5'
#define TARGETGOAL '6'
#define SAVEPOINTGOAL '7'

#define TOWERCOUNT 6


const int gStageWidth = 20+1;
const int gStageHeight = 20;
bool gbGoal = false;
bool gbSave = false;
bool gbDead = false;
struct POINT
{
	int x;
	int y;
};

struct UNIT
{
	POINT m_point;		// 좌표값
	POINT m_wayPoint;	// 상대와의 좌표값 차
	char m_name[12];	// 이름
	int m_hp;			// 생명력
	int m_damage;		// 공격력
	int m_range;		// 공격범위

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
		if (getRange() >= sqrt(pow((float)getWayPoint().x, 2) + pow((float)getWayPoint().y, 2)))
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
				printf("%s(은)는 %s에게 %d의 피해를 입혔다!     ", getName(), pVictim->getName(), getDamage());
				// HP가 0 이하면 죽음, 죽었다고 알려줌
				if (pVictim->getHp() <= 0)
				{
					pVictim->dead();
					printf("%sHP : %d\n", pVictim->getName(), pVictim->getHp());
					printf("%s(이)가 소멸하였다!\n", pVictim->getName());
				}
				else
				{
					// 현재 남아있는 대상의 HP를 띄움
					printf("%sHP : %d\n\n", pVictim->getName(), pVictim->getHp());
				}
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
	void setPoint(int _x, int _y)
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

	void setHp(int _hp)
	{
		m_hp = _hp;
	}

	void setDamage(int _damage)
	{
		m_damage = _damage;
	}

	void setRange(int _range)
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

	int getHp()
	{
		return m_hp;
	}

	int getDamage()
	{
		return m_damage;
	}

	int getRange()
	{
		return m_range;
	}
};

void stageOpen(FILE *pFile, char *pFileName, char *pLoadFileName, char *pMode, char *pBuffer, int bufferSize);
void draw(const char *pState, int width, int height);
void unitInit(char *pState, int width, int height, UNIT *pPlayer, UNIT *pTower);
void unitPointInit(char *pState, int width, int height, UNIT *pUnit, char unitType);
void unitMove(char *pState, int width, int height, char cKey, UNIT *pUnit);
void unitPointUpdate(char *pState, int width, int height, int moveX, int moveY, UNIT *pUnit);
void stageSave(FILE *pFile, char *pSaveFileName, char *pMode, char *pBuffer, int bufferSize);
void main()
{

	UNIT tower[TOWERCOUNT] = {};
	UNIT player = {};
	FILE *pFile = nullptr;
	char state[gStageWidth * gStageHeight] = {};	// 가로 * 세로 만큼 배열할당
	char cKey = NULL;

	// 파일 읽어오기
	stageOpen(pFile, "mstage1.txt", "lmstage1.txt", "r", state, sizeof(state));
	// 유닛 초기화
	unitInit(state, gStageWidth, gStageHeight, &player, tower);

	while (cKey != 27)
	{
		unitPointInit(state, gStageWidth, gStageHeight, &player, PLAYER);

		// 타워들 공격설정
		for (int i = 0; i < TOWERCOUNT; i++)
		{
			tower[i].attack(&player);
		}

		// 플레이어가 죽었는지 확인
		if (player.isDead())
		{
			gbDead = true;
		}

		// 화면그리기
		draw(state, gStageWidth, gStageHeight);

		if (gbDead)
		{
			printf("다시 하시겠습니까? ( y / n )\n");
			fflush(stdin);
			scanf("%c", &cKey);
			if (cKey == 'y' || cKey == 'Y')
			{
				system("cls");
				// 정보 초기화
				stageOpen(pFile, "mstage1.txt", "lmstage1.txt", "r", state, sizeof(state));
				unitInit(state, gStageWidth, gStageHeight, &player, tower);
				gbDead = false;
				// 다시시작
				continue;
			}
			else if (cKey == 'n' || cKey == 'N')
			{
				// 종료
				break;
			}
		}

		if (gbSave)
		{
			stageSave(pFile, "lmstage1.txt", "w", state, sizeof(state));
		}

		if (gbGoal)
		{
			printf("골인!!\n");
			printf("다시 하시겠습니까? ( y / n )\n");
			fflush(stdin);
			scanf("%c", &cKey);
			if (cKey == 'y' || cKey == 'Y')
			{
				system("cls");
				// 정보 초기화
				stageOpen(pFile, "mstage1.txt", "lmstage1.txt", "r", state, sizeof(state));
				unitInit(state, gStageWidth, gStageHeight, &player, tower);
				gbGoal = false;
				// 다시시작
				continue;
			}
			else if (cKey == 'n' || cKey == 'N')
			{
				// 종료
				break;
			}
		}

		// 입력받은 키값을 key변수에 대입
		cKey = _getch();
		if (_kbhit())
		{
			cKey = _getch();
			system("cls");

			// 유닛 조작 및 맵 정보 업데이트
			unitMove(state, gStageWidth, gStageHeight, cKey, &player);
		}
	}
}

void stageOpen(FILE *pFile, char *pFileName, char *pLoadFileName, char *pMode, char *pBuffer, int bufferSize)
{
	errno_t err;
	if ((err = fopen_s(&pFile, pLoadFileName, pMode)) == 0)
	{
		char ck = NULL;
		printf("1. 불러오기\n2. 처음부터\n");
		ck = _getch();
		if (ck == '1')
		{
			fread(pBuffer, bufferSize, 1, pFile);
			fclose(pFile);
			return;
		}
		else if (ck == '2')
		{
			fopen_s(&pFile, pFileName, pMode);
			{
				fread(pBuffer, bufferSize, 1, pFile);
			}
			fclose(pFile);
		}
	}
	else if ((err = fopen_s(&pFile, pFileName, pMode)) == 0)
	{
		fopen_s(&pFile, pFileName, pMode);
		{
			fread(pBuffer, bufferSize, 1, pFile);
		}
		fclose(pFile);
	}

		
}

void draw(const char *pState, int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (pState[y*width + x])		// [y * width + x] : 현재 배열 위치
			{
			case SPACE:
				printf("　");
				break;

			case WALL:
				printf("■");
				break;

			case TOWER:
				printf("♠");
				break;

			case PLAYER:
				if (gbDead)
				{
					printf("GG");
				}
				else
				{
					printf("웃");
				}
				break;

			case TARGET:		
					printf("☆");
				break;

			case SAVEPOINT:
					printf("ⓢ");
				break;

			case TARGETGOAL:
					printf("★");
				break;

			case SAVEPOINTGOAL:
					printf("⒮");
				break;

			default:
				break;
			}
		}
		printf("\n");
	}
}

void unitInit(char *pState, int width, int height, UNIT *pPlayer, UNIT *pTower)
{
	// 좌표값 입력
	unitPointInit(pState, width, height, pPlayer, PLAYER);
	pPlayer->setName("Player");
	pPlayer->setHp(30);
	
	unitPointInit(pState, width, height, pTower, TOWER);
	for (int  i = 0; i < TOWERCOUNT; i++)
	{
		pTower[i].setName("Tower");
		pTower[i].setHp(50);
		pTower[i].setDamage(10);
		pTower[i].setRange(2);
	}
}

void unitPointInit(char *pState, int width, int height, UNIT *pUnit, char unitType)
{
	if (unitType == PLAYER || unitType == SAVEPOINTGOAL)
	{
		for (int i = 0; i < width*height; i++)
		{
			if (pState[i] == PLAYER || pState[i] == SAVEPOINTGOAL)
			{
				pUnit->setPoint(i % width, i / width);
				i = width*height;
			}
		}
	}
	else if (unitType == TOWER)
	{
		int idx = 0;
		for (int i = 0; i < width*height; i++)
		{
			if (pState[i] == unitType)
			{
				pUnit[idx].setPoint(i % width, i / width);
				idx++;
				if (idx == TOWERCOUNT)
				{
					i = width*height;
				}
			}
		}
	}
}

void unitMove(char *pState, int width, int height, char cKey, UNIT *pUnit)
{
	int x = 0;
	int y = 0;

	// key의 값이 각 방향키의 AsciiCode값과 일치 and 맵을 넘어가는지 확인하여 둘 다 true일 경우 해당 좌표값을 변경
	// LEFT
	if (cKey == 75)
	{
		x = -1;
	}
	// RIGHT
	else if (cKey == 77)
	{
		 x = 1;
	}
	// UP
	else if (cKey == 72)
	{
		 y = -1;
	}
	// DOWN
	else if (cKey == 80)
	{
		 y = 1;
	}

	unitPointUpdate(pState, width, height, x, y, pUnit);
}

void unitPointUpdate(char *pState, int width, int height, int moveX, int moveY, UNIT *pUnit)
{
	int idx = pUnit->getPoint().y * width + pUnit->getPoint().x;
	int nIdx = (pUnit->getPoint().y + moveY) * width + (pUnit->getPoint().x + moveX);

	// 타겟으로 가려는 경우 트루
	if (pState[nIdx] == TARGET)
	{
		pState[nIdx] = TARGETGOAL;
		pState[idx] = SPACE;
		gbGoal = true;
	}
	// 세이브포인토로 가려는 경우 트루
	else if (pState[nIdx] == SAVEPOINT)
	{
		pState[nIdx] = SAVEPOINTGOAL;
		pState[idx] = SPACE;
		gbSave = true;
	}

	else if (pState[nIdx] != WALL && pState[nIdx] != TOWER)
	{
		if (pState[idx] == SAVEPOINTGOAL)
		{
			pState[nIdx] = PLAYER;
			pState[idx] = SAVEPOINT;
			gbSave = false;
		}
		else
		{
			pState[nIdx] = pState[idx];
			pState[idx] = SPACE;
		}

	}
}

void stageSave(FILE *pFile, char *pSaveFileName, char *pMode, char *pBuffer, int bufferSize)
{
	errno_t err;
	fopen_s(&pFile, pSaveFileName, pMode);
	{
		fwrite(pBuffer, bufferSize, 1, pFile);
			
		printf("세이브 되었습니다!\n");		
	}
	fclose(pFile);
}

// orz..