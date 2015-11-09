/*
���� ]] Enemy �� �ʿ��� �̵��ϱ�

�����������
�����������
���ޡ�������	�� : enemy
�������T����
�����������
�������ڡ���	�� : destination
�����������
�����������

Enemy ����ü�� start ��ġ���� enemy ����
dest ��ġ�� �߰��� �ְ�,
���� �ð����� �������� �̵��ϱ�

_sleep( 1000 )  1000 = �� 1 ��
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

// 0���� �����, ��, Ÿ��, ��, Ÿ�� ���� ����
enum Object
{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_TOWER,
	OBJ_ENEMY,
	OBJ_TARGET
};

// ������ ������ ǥ���ϱ� ���� ����, ���ϻ���
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
	// �迭������ ���� ��ǥ�� �Ǿ��־� int���̾�� ������.. float���� �����غ�
	float x;
	float y;
};

// ���� ����, ���� ũ��
// main ���� ���� �;��µ� isSpaceWay�� �ʿ�� �ϴ� �ٶ��� UNIT ����ü ������ ������..��
static const int gStageWidth = 20;
static const int gStageHeight = 20;
// ���������� ���������� ������ ���������� ����
static Object stateMap[gStageWidth * gStageHeight] = {};

// isSpaceWay�� UNIT ����ü �������� �ݺ����ǰ� ������ �ʱ⶧���� UNIT�� �˰��ϱ� ���� �ۿ��ٰ� ����� UNIT���� ������
bool isSpaceWay(POINT *pPoint, Direction drcMark);
struct UNIT
{
	POINT m_point;		// ��ǥ��
	POINT m_wayPoint;	// ������ ��ǥ�� ��
	char m_name[12];	// �̸�
	float m_hp;			// �����
	float m_damage;		// ���ݷ�
	float m_range;		// ���ݹ���

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
		if (getRange() >= sqrt(pow(getWayPoint().x, 2) + pow(getWayPoint().y, 2)))
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
				printf("%s(��)�� %s���� %.1f�� ���ظ� ������!     ", getName(), pVictim->getName(), getDamage());
				// HP�� 0 ���ϸ� ����, �׾��ٰ� �˷���
				if (pVictim->getHp() <= 0)
				{
					pVictim->dead();
					printf("%sHP : %.1f\n", pVictim->getName(), pVictim->getHp());
					printf("%s(��)�� �Ҹ��Ͽ���!\n", pVictim->getName());
				}
				else
				{
					// ���� �����ִ� ����� HP�� ���
					printf("%sHP : %.1f\n", pVictim->getName(), pVictim->getHp());
				}
			}

		}
	}

	void move()
	{
		// �Ÿ���ǥ x, y ���� ������� �������� 0���� �����ؼ� ������ ���� ��������� Ȯ��, ������ ��ǥ�� �̵�
		// �������� 
		if (getWayPoint().x > 0 && getWayPoint().y == 0)
		{
			if (isSpaceWay(&getPoint(), DRC_LEFT))
			{
				setPoint(getPoint().x - 1.0f, getPoint().y);
			}
		}
		// ����������
		else if (getWayPoint().x < 0 && getWayPoint().y == 0)
		{
			if (isSpaceWay(&getPoint(), DRC_RIGHT))
			{
				setPoint(getPoint().x + 1.0f, getPoint().y);
			}
		}
		// ����
		else if (getWayPoint().x == 0 && getWayPoint().y > 0)
		{
			if (isSpaceWay(&getPoint(), DRC_UP))
			{
				setPoint(getPoint().x, getPoint().y - 1.0f);
			}
		}
		// �Ʒ���
		else if (getWayPoint().x == 0 && getWayPoint().y < 0)
		{
			if (isSpaceWay(&getPoint(), DRC_DOWN))
			{
				setPoint(getPoint().x, getPoint().y + 1.0f);
			}
		}
		// ���� ����
		else if (getWayPoint().x > 0 && getWayPoint().y > 0)
		{
			if (isSpaceWay(&getPoint(), DRC_LEFTUP))
			{
				setPoint(getPoint().x - 0.5f, getPoint().y - 0.5f);
			}
		}
		// ���� �Ʒ���
		else if (getWayPoint().x > 0 && getWayPoint().y < 0)
		{
			if (isSpaceWay(&getPoint(), DRC_LEFTDOWN))
			{
				setPoint(getPoint().x - 0.5f, getPoint().y + 0.5f);
			}
		}
		//������ ����
		else if (getWayPoint().x < 0 && getWayPoint().y > 0)
		{
			if (isSpaceWay(&getPoint(), DRC_RIGHTUP))
			{
				setPoint(getPoint().x + 0.5f, getPoint().y - 0.5f);
			}
		}
		// ������ �Ʒ���
		else if (getWayPoint().x < 0 && getWayPoint().y < 0)
		{
			if (isSpaceWay(&getPoint(), DRC_RIGHTDOWN))
			{
				setPoint(getPoint().x + 0.5f, getPoint().y + 0.5f);
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
	void setPoint(float _x, float _y)
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
	int nX = 1;				// X������ 1ĭ�� ������ �迭��ȣ
	int nY = gStageWidth;	// Y������ 1ĭ�� ������ �迭��ȣ
	int nArr = (int)(((int)pPoint->y * gStageWidth) + (int)pPoint->x);	//pPoint�� ���� ��ǥ���� �迭��ȣ

	// ������ ������ ������̰� �װ��迭�� ���� OBJ_SPACE �̸� true, �ƴϸ� false�� ��ȯ
	// ��������
	if (drcMark == DRC_LEFT && stateMap[nArr - nX] == OBJ_SPACE)
	{
		return true;
	}
	// ����������
	else if (drcMark == DRC_RIGHT && stateMap[nArr + nX] == OBJ_SPACE)
	{
		return true;
	}
	// ��������
	else if (drcMark == DRC_UP && stateMap[nArr - nY] == OBJ_SPACE)
	{
		return true;
	}
	// �Ʒ�������
	else if (drcMark == DRC_DOWN && stateMap[nArr + nY] == OBJ_SPACE)
	{
		return true;
	}
	// ���� ����
	else if (drcMark == DRC_LEFTUP && stateMap[(nArr - nX) - nY] == OBJ_SPACE)
	{
		return true;
	}
	// ���� �Ʒ���
	else if (drcMark == DRC_LEFTDOWN && stateMap[(nArr - nX) + nY] == OBJ_SPACE)
	{
		return true;
	}
	// ������ ����
	else if (drcMark == DRC_RIGHTUP && stateMap[(nArr + nX) - nY] == OBJ_SPACE)
	{
		return true;
	}
	// ������ �Ʒ���
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
	// ���� �� �ʱ�ȭ
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
	
	// ���� ����
	while (cKey != 27)	// esc�� ������ ����
	{
		// Object �迭 �ʱ�ȭ
		initObject(&tower, &enemy, &target);
		
		// tower�� ���� �ʾҴٸ� tower�� enemy�� �����϶�
		if (!tower.isDead())
		{
			tower.attack(&enemy);
		}
		
		// enemy�� �����ʾҴٸ� enemy�� target�� �����϶�
		// target���� �Ÿ��� ����, ��������
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


// �ݺ����� �������鼭 Object[]�� �ش��ϴ� Object�� �־���
void initObject(UNIT *tower, UNIT *enemy, UNIT *target)
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
			else if (tower != NULL && horz == tower->getPoint().x && vert == tower->getPoint().y)
			{
				stateMap[nArr] = OBJ_TOWER;
			}
			// ���ʹ��� ���
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

	case OBJ_TARGET:
		printf("��");
		break;
	default:
		printf("\n\ndrowingObject ���� ERROR!!\n\n");
		break;
	}
}