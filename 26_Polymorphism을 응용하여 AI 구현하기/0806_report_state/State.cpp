#include "State.h"
#include "Orc.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 상태 진입
void StateIdle::enter(Orc *pOrc)
{
	cout << "IDLE STATE 진입 .." << endl;
}
// 상태 진행중
void StateIdle::execute(Orc *pOrc)
{
	int nHealth = pOrc->getHealth();
	nHealth -= 1;
	pOrc->setHealth(nHealth);

	cout << "오크가 빈둥거립니다" << endl;
	cout << "HP = " << pOrc->getHealth() << endl;

		int nrange;
		cout << "적과의 거리 : ";
		cin >> nrange;
		pOrc->setRange(nrange);

	// 오크가 피곤한가?
	if (pOrc->getHealth() < 3)
	{
		// 쉬러간다.
		pOrc->setHealth(3);
		pOrc->changeState(new StateSleep);
	}

	// 오크가 위협을 받나?
	if (pOrc->getRange() <= 5)	// 임시로 적과의 거리가 5m 이내가될 경우로 설정
	{
		// 싸운다.
		pOrc->changeState(new StateBattle);
	}

}
// 상태 이탈
void StateIdle::exit(Orc *pOrc)
{
	cout << "IDLE STATE 이탈 .." << endl;
}


//========= SLEEP ===========

// 상태 진입
void StateSleep::enter(Orc *pOrc)
{
	cout << "SLEEP STATE 진입 .." << endl;
}
// 상태 진행중
void StateSleep::execute(Orc *pOrc)
{
	int nHealth = pOrc->getHealth();
	nHealth += 2;
	pOrc->setHealth(nHealth);

	cout << "Z Z z z .." << endl;

	// 오크가 피곤한가?
	if (pOrc->getHealth() > 20)
	{
		// 배회하러간다.
		pOrc->setHealth(20);
		pOrc->changeState(new StateIdle);
	}

	cout << "HP = " << pOrc->getHealth() << endl;
}
// 상태 이탈
void StateSleep::exit(Orc *pOrc)
{
	cout << "SLEEP STATE 이탈 .." << endl;
}


//========= BATTLE ===========

// 상태 진입
void StateBattle::enter(Orc *pOrc)
{
	cout << "BATTLE STATE 진입 .." << endl;
}
// 상태 진행중
void StateBattle::execute(Orc *pOrc)
{
	int nHealth = pOrc->getHealth();
	nHealth -= 2;
	// HP 가 0 미만이면 0으로 처리
	if (nHealth < 0)
	{
		nHealth = 0;
	}
	pOrc->setHealth(nHealth);

	cout << "오크가 싸웁니다." << endl;
	cout << "HP = " << pOrc->getHealth() << endl;
	// 오크가 딸피인가?
	if (pOrc->getHealth() < 3)
	{
		// 도망간다.
		pOrc->changeState(new StateRunaway);
	}
	// 안죽게되있어서 죽었는가는 우선 제외
	

	int nEnemyHealth = pOrc->getEnemyHealth();
	nEnemyHealth -= 2;
	if (nEnemyHealth < 0)
	{
		nEnemyHealth = 0;
	}
	pOrc->setEnemyHealth(nEnemyHealth);

	cout << "적 HP = " << pOrc->getEnemyHealth() << endl;
	// 오크가 이겼는가?
	if (pOrc->getEnemyHealth() <= 0)
	{
		pOrc->setEnemyHealth(5);	// 임시로 적 HP 초기화
		pOrc->changeState(new StateSleep);
	}


}
// 상태 이탈
void StateBattle::exit(Orc *pOrc)
{
	cout << "BATTLE STATE 이탈 .." << endl;
}


//========= RUNAWAY ===========

// 상태 진입
void StateRunaway::enter(Orc *pOrc)
{
	cout << "RUNAWAY STATE 진입 .." << endl;
}
// 상태 진행중
void StateRunaway::execute(Orc *pOrc)
{
	cout << "오크가 도망갑니다." << endl;
	cout << "HP = " << pOrc->getHealth() << endl;

	int nrange;
	cout << "적과의 거리 : ";
	cin >> nrange;
	pOrc->setRange(nrange);

	// 오크가 안전한가?
	if (pOrc->getRange() > 5)
	{
		// 쉬러간다.
		pOrc->changeState(new StateSleep);
	}
}
// 상태 이탈
void StateRunaway::exit(Orc *pOrc)
{
	cout << "RUNAWAY STATE 이탈 .." << endl;
}