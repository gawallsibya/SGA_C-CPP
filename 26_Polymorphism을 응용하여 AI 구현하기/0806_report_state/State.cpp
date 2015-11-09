#include "State.h"
#include "Orc.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// ���� ����
void StateIdle::enter(Orc *pOrc)
{
	cout << "IDLE STATE ���� .." << endl;
}
// ���� ������
void StateIdle::execute(Orc *pOrc)
{
	int nHealth = pOrc->getHealth();
	nHealth -= 1;
	pOrc->setHealth(nHealth);

	cout << "��ũ�� ��հŸ��ϴ�" << endl;
	cout << "HP = " << pOrc->getHealth() << endl;

		int nrange;
		cout << "������ �Ÿ� : ";
		cin >> nrange;
		pOrc->setRange(nrange);

	// ��ũ�� �ǰ��Ѱ�?
	if (pOrc->getHealth() < 3)
	{
		// ��������.
		pOrc->setHealth(3);
		pOrc->changeState(new StateSleep);
	}

	// ��ũ�� ������ �޳�?
	if (pOrc->getRange() <= 5)	// �ӽ÷� ������ �Ÿ��� 5m �̳����� ���� ����
	{
		// �ο��.
		pOrc->changeState(new StateBattle);
	}

}
// ���� ��Ż
void StateIdle::exit(Orc *pOrc)
{
	cout << "IDLE STATE ��Ż .." << endl;
}


//========= SLEEP ===========

// ���� ����
void StateSleep::enter(Orc *pOrc)
{
	cout << "SLEEP STATE ���� .." << endl;
}
// ���� ������
void StateSleep::execute(Orc *pOrc)
{
	int nHealth = pOrc->getHealth();
	nHealth += 2;
	pOrc->setHealth(nHealth);

	cout << "Z Z z z .." << endl;

	// ��ũ�� �ǰ��Ѱ�?
	if (pOrc->getHealth() > 20)
	{
		// ��ȸ�Ϸ�����.
		pOrc->setHealth(20);
		pOrc->changeState(new StateIdle);
	}

	cout << "HP = " << pOrc->getHealth() << endl;
}
// ���� ��Ż
void StateSleep::exit(Orc *pOrc)
{
	cout << "SLEEP STATE ��Ż .." << endl;
}


//========= BATTLE ===========

// ���� ����
void StateBattle::enter(Orc *pOrc)
{
	cout << "BATTLE STATE ���� .." << endl;
}
// ���� ������
void StateBattle::execute(Orc *pOrc)
{
	int nHealth = pOrc->getHealth();
	nHealth -= 2;
	// HP �� 0 �̸��̸� 0���� ó��
	if (nHealth < 0)
	{
		nHealth = 0;
	}
	pOrc->setHealth(nHealth);

	cout << "��ũ�� �ο�ϴ�." << endl;
	cout << "HP = " << pOrc->getHealth() << endl;
	// ��ũ�� �����ΰ�?
	if (pOrc->getHealth() < 3)
	{
		// ��������.
		pOrc->changeState(new StateRunaway);
	}
	// ���װԵ��־ �׾��°��� �켱 ����
	

	int nEnemyHealth = pOrc->getEnemyHealth();
	nEnemyHealth -= 2;
	if (nEnemyHealth < 0)
	{
		nEnemyHealth = 0;
	}
	pOrc->setEnemyHealth(nEnemyHealth);

	cout << "�� HP = " << pOrc->getEnemyHealth() << endl;
	// ��ũ�� �̰�°�?
	if (pOrc->getEnemyHealth() <= 0)
	{
		pOrc->setEnemyHealth(5);	// �ӽ÷� �� HP �ʱ�ȭ
		pOrc->changeState(new StateSleep);
	}


}
// ���� ��Ż
void StateBattle::exit(Orc *pOrc)
{
	cout << "BATTLE STATE ��Ż .." << endl;
}


//========= RUNAWAY ===========

// ���� ����
void StateRunaway::enter(Orc *pOrc)
{
	cout << "RUNAWAY STATE ���� .." << endl;
}
// ���� ������
void StateRunaway::execute(Orc *pOrc)
{
	cout << "��ũ�� �������ϴ�." << endl;
	cout << "HP = " << pOrc->getHealth() << endl;

	int nrange;
	cout << "������ �Ÿ� : ";
	cin >> nrange;
	pOrc->setRange(nrange);

	// ��ũ�� �����Ѱ�?
	if (pOrc->getRange() > 5)
	{
		// ��������.
		pOrc->changeState(new StateSleep);
	}
}
// ���� ��Ż
void StateRunaway::exit(Orc *pOrc)
{
	cout << "RUNAWAY STATE ��Ż .." << endl;
}