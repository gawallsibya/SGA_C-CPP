/*
	Orc 캐릭터
*/

#ifndef _ORC_H_
#define _ORC_H_

#include "State.h"

class iGameObj
{
public:
	virtual ~iGameObj(){}
};

class Orc : public iGameObj
{
public:
	Orc();
	~Orc();

public:	// interface
	void update();
	void changeState(iState *pNewState);

	int getHealth() const		{ return m_health;	 }	// const -> 겟해서 값을 바꾸지 못하게 보호
	void setHealth(int health)	{ m_health = health; }
	
	int getRange() const		{ return m_range;	 }
	void setRange(int range)	{ m_range = range;	 }

	int getEnemyHealth() const				{ return m_enemyHealth;		   }
	void setEnemyHealth(int enemyHealth)	{ m_enemyHealth = enemyHealth; }

private:
	iState *pState = nullptr;	// 현재 상태
	int m_health = 20;	// 체력지수
	int m_range = 20;	// 임시로 적과 자신의 거리지정
	int m_enemyHealth = 5;	// 임시로 만든 적 체력 
};

#endif /*_ORC_H_*/