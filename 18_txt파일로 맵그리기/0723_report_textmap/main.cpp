/*
�޸������� �׸� �� �̹��� �ҷ��ͼ� ȭ�� ���

Ÿ�ϸ� �ҷ����� ( ũ��� ���� ���� )

���� ]	Ư�����ڴ� 2byte�̰�
�� ���� ������ null ���� ������ ���

Ȯ�� ] ĳ���Ͱ� �̵�, ���̺�����Ʈ�� �����ҽ� ����Ǿ� �ε�� ���̺�����Ʈ���� ����
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

// 0���� �����, ��, Ÿ��, ��, Ÿ�� ���� ����

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
	POINT m_point;		// ��ǥ��
	POINT m_wayPoint;	// ������ ��ǥ�� ��
	char m_name[12];	// �̸�
	int m_hp;			// �����
	int m_damage;		// ���ݷ�
	int m_range;		// ���ݹ���

	// ������ ��ǥ�� ���� ����ؼ� �������ش�.
	void setWayPoint(POINT *_pPoint)
	{
		m_wayPoint = { m_point.x - _pPoint->x, m_point.y - _pPoint->y };
	}

	// ���ݹ��� �ȿ� ���� true �ȿ��� false�� ��ȯ
	bool isinRange(POINT *_pPoint)
	{
		setWayPoint(_pPoint);
		//			(x��ǥ�� ��)2���� + (y��ǥ ��)2���� �� ��Ʈ�� ���� ��
		if (getRange() >= sqrt(pow((float)getWayPoint().x, 2) + pow((float)getWayPoint().y, 2)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// ��� ������ ���ݹ��� �ȿ� ������ ����
	void attack(UNIT *pVictim)
	{
		// ���� ������ �ֳ� �Ǵ�
		if (isinRange(&pVictim->getPoint()))
		{
			// ����� ���������� Ȯ�� (���Ű� �ȵǼ� �׾����� ���θ� ���°ŷ� �����)
			if (!pVictim->isDead())
			{
				// ���ݷ� ��ŭ HP ����
				pVictim->setHp(pVictim->getHp() - getDamage());
				printf("%s(��)�� %s���� %d�� ���ظ� ������!     ", getName(), pVictim->getName(), getDamage());
				// HP�� 0 ���ϸ� ����, �׾��ٰ� �˷���
				if (pVictim->getHp() <= 0)
				{
					pVictim->dead();
					printf("%sHP : %d\n", pVictim->getName(), pVictim->getHp());
					printf("%s(��)�� �Ҹ��Ͽ���!\n", pVictim->getName());
				}
				else
				{
					// ���� �����ִ� ����� HP�� ���
					printf("%sHP : %d\n\n", pVictim->getName(), pVictim->getHp());
				}
			}
		}
	}

	// ���Ű� �ȵ� ��� ������ �ʱ�ȭ�ϴ°ŷ� �����
	void dead()
	{
		m_point = {};
		m_wayPoint = {};
		for (int x : m_name)	// �迭�̶� �ϳ��ϳ� ��������� �ؼ� �迭 for�� ����
		{
			x = NULL;
		}
		m_hp = NULL;
		m_damage = NULL;
		m_range = NULL;
	}

	// �׾����� hp�� ���� �Ǵ��Ͽ� �׾����� true, ���׾����� false�� ��ȯ
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

	// ���� set��¼���� ���� �޾ƿͼ� ���Խ�����, get��¼���� ���� ���Ͻ��Ѽ� ����� �� �ְ���	(�䳻�� ���Ŵ� �ǹ̴� ����..)
	void setPoint(int _x, int _y)
	{
		m_point.x = _x;
		m_point.y = _y;
	}

	void setName(char _pName[])
	{
		// ��Ư�� �迭�� ũ�⸦ ���ؾ��ؼ� �޾ƿ� ���ڿ��迭 ��ŭ NULL���� ���ö����� ����
		// NULL���� ���Ӵٰ� �ٷ� ������ ������ ���ڰ� �ȵ��� do while�� �����
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
	char state[gStageWidth * gStageHeight] = {};	// ���� * ���� ��ŭ �迭�Ҵ�
	char cKey = NULL;

	// ���� �о����
	stageOpen(pFile, "mstage1.txt", "lmstage1.txt", "r", state, sizeof(state));
	// ���� �ʱ�ȭ
	unitInit(state, gStageWidth, gStageHeight, &player, tower);

	while (cKey != 27)
	{
		unitPointInit(state, gStageWidth, gStageHeight, &player, PLAYER);

		// Ÿ���� ���ݼ���
		for (int i = 0; i < TOWERCOUNT; i++)
		{
			tower[i].attack(&player);
		}

		// �÷��̾ �׾����� Ȯ��
		if (player.isDead())
		{
			gbDead = true;
		}

		// ȭ��׸���
		draw(state, gStageWidth, gStageHeight);

		if (gbDead)
		{
			printf("�ٽ� �Ͻðڽ��ϱ�? ( y / n )\n");
			fflush(stdin);
			scanf("%c", &cKey);
			if (cKey == 'y' || cKey == 'Y')
			{
				system("cls");
				// ���� �ʱ�ȭ
				stageOpen(pFile, "mstage1.txt", "lmstage1.txt", "r", state, sizeof(state));
				unitInit(state, gStageWidth, gStageHeight, &player, tower);
				gbDead = false;
				// �ٽý���
				continue;
			}
			else if (cKey == 'n' || cKey == 'N')
			{
				// ����
				break;
			}
		}

		if (gbSave)
		{
			stageSave(pFile, "lmstage1.txt", "w", state, sizeof(state));
		}

		if (gbGoal)
		{
			printf("����!!\n");
			printf("�ٽ� �Ͻðڽ��ϱ�? ( y / n )\n");
			fflush(stdin);
			scanf("%c", &cKey);
			if (cKey == 'y' || cKey == 'Y')
			{
				system("cls");
				// ���� �ʱ�ȭ
				stageOpen(pFile, "mstage1.txt", "lmstage1.txt", "r", state, sizeof(state));
				unitInit(state, gStageWidth, gStageHeight, &player, tower);
				gbGoal = false;
				// �ٽý���
				continue;
			}
			else if (cKey == 'n' || cKey == 'N')
			{
				// ����
				break;
			}
		}

		// �Է¹��� Ű���� key������ ����
		cKey = _getch();
		if (_kbhit())
		{
			cKey = _getch();
			system("cls");

			// ���� ���� �� �� ���� ������Ʈ
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
		printf("1. �ҷ�����\n2. ó������\n");
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
			switch (pState[y*width + x])		// [y * width + x] : ���� �迭 ��ġ
			{
			case SPACE:
				printf("��");
				break;

			case WALL:
				printf("��");
				break;

			case TOWER:
				printf("��");
				break;

			case PLAYER:
				if (gbDead)
				{
					printf("GG");
				}
				else
				{
					printf("��");
				}
				break;

			case TARGET:		
					printf("��");
				break;

			case SAVEPOINT:
					printf("��");
				break;

			case TARGETGOAL:
					printf("��");
				break;

			case SAVEPOINTGOAL:
					printf("��");
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
	// ��ǥ�� �Է�
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

	// key�� ���� �� ����Ű�� AsciiCode���� ��ġ and ���� �Ѿ���� Ȯ���Ͽ� �� �� true�� ��� �ش� ��ǥ���� ����
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

	// Ÿ������ ������ ��� Ʈ��
	if (pState[nIdx] == TARGET)
	{
		pState[nIdx] = TARGETGOAL;
		pState[idx] = SPACE;
		gbGoal = true;
	}
	// ���̺�������� ������ ��� Ʈ��
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
			
		printf("���̺� �Ǿ����ϴ�!\n");		
	}
	fclose(pFile);
}

// orz..