/*
	virtual ���� �Լ�
	- ��ӹ��� Ŭ������ �Լ��� �켱 ���.
	= 0	 ���� ���� �Լ� (pure virtual function )
	- pvf �� ���ؼ� ��ӹ��� Ŭ������ �ݵ�� �����Ѵ�.
*/

#ifndef _STATE_H_
#define _STATE_H_

class Orc;

class iState
{
public:
	virtual ~iState(){}

public:
	// ���� ����
	virtual void enter(Orc *pOrc) = 0;	// = 0  PURE VIRTUAL.
	// ���� ������
	virtual void execute(Orc *pOrc) = 0;
	// ���� ��Ż
	virtual void exit(Orc *pOrc) = 0;
};

/*
	StateIdle
*/
class StateIdle : public iState
{
public:
	StateIdle(){}
	~StateIdle(){}

private:
	// ���� ����
	void enter(Orc *pOrc);
	// ���� ������
	void execute(Orc *pOrc);
	// ���� ��Ż
	void exit(Orc *pOrc);

};

/*
StateSleep
*/
class StateSleep : public iState
{
public:
	StateSleep(){}
	~StateSleep(){}

private:
	// ���� ����
	void enter(Orc *pOrc);
	// ���� ������
	void execute(Orc *pOrc);
	// ���� ��Ż
	void exit(Orc *pOrc);

};

/*
StateBattle
*/
class StateBattle : public iState
{
public:
	StateBattle(){}
	~StateBattle(){}

private:
	// ���� ����
	void enter(Orc *pOrc);
	// ���� ������
	void execute(Orc *pOrc);
	// ���� ��Ż
	void exit(Orc *pOrc);

};

/*
StateRunaway
*/
class StateRunaway : public iState
{
public:
	StateRunaway(){}
	~StateRunaway(){}

private:
	// ���� ����
	void enter(Orc *pOrc);
	// ���� ������
	void execute(Orc *pOrc);
	// ���� ��Ż
	void exit(Orc *pOrc);

};
#endif /*_STATE_H_*/