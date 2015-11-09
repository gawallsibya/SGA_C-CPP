/*
	virtual 가상 함수
	- 상속받은 클래스의 함수를 우선 사용.
	= 0	 순수 가상 함수 (pure virtual function )
	- pvf 에 대해서 상속받은 클래스는 반드시 정의한다.
*/

#ifndef _STATE_H_
#define _STATE_H_

class Orc;

class iState
{
public:
	virtual ~iState(){}

public:
	// 상태 진입
	virtual void enter(Orc *pOrc) = 0;	// = 0  PURE VIRTUAL.
	// 상태 진행중
	virtual void execute(Orc *pOrc) = 0;
	// 상태 이탈
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
	// 상태 진입
	void enter(Orc *pOrc);
	// 상태 진행중
	void execute(Orc *pOrc);
	// 상태 이탈
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
	// 상태 진입
	void enter(Orc *pOrc);
	// 상태 진행중
	void execute(Orc *pOrc);
	// 상태 이탈
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
	// 상태 진입
	void enter(Orc *pOrc);
	// 상태 진행중
	void execute(Orc *pOrc);
	// 상태 이탈
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
	// 상태 진입
	void enter(Orc *pOrc);
	// 상태 진행중
	void execute(Orc *pOrc);
	// 상태 이탈
	void exit(Orc *pOrc);

};
#endif /*_STATE_H_*/