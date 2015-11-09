/*
	Orc ĳ����
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

	int getHealth() const		{ return m_health;	 }	// const -> ���ؼ� ���� �ٲ��� ���ϰ� ��ȣ
	void setHealth(int health)	{ m_health = health; }
	
	int getRange() const		{ return m_range;	 }
	void setRange(int range)	{ m_range = range;	 }

	int getEnemyHealth() const				{ return m_enemyHealth;		   }
	void setEnemyHealth(int enemyHealth)	{ m_enemyHealth = enemyHealth; }

private:
	iState *pState = nullptr;	// ���� ����
	int m_health = 20;	// ü������
	int m_range = 20;	// �ӽ÷� ���� �ڽ��� �Ÿ�����
	int m_enemyHealth = 5;	// �ӽ÷� ���� �� ü�� 
};

#endif /*_ORC_H_*/