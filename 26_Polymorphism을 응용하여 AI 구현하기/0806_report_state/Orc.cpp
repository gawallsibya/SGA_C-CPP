#include "Orc.h"
#include <iostream>

using std::cout;
using std::endl;

Orc::Orc()
{
	// 현재상태를 IDLE 로 기본설정
	pState = new StateIdle;
}


Orc::~Orc()
{
	if (pState)
	{
		delete pState;
		pState = nullptr;
	}
}

void Orc::changeState(iState *pNewState)
{
	// 오류체크
	if (pState == nullptr || pNewState == nullptr)
	{
		cout << "changeState ERROR" << endl;
		return;
	}

	// 정상적인 상황

	// 현재 상태 이탈
	pState->exit(this);
	// 현재 상태 삭제
	delete pState;

	// 새로운 상태를 현재 상태로 만듦
	pState = pNewState;
	// 새로운 상태로 진입
	pState->enter(this);
}

void Orc::update()
{
	// 오류체크
	if (pState == nullptr)
	{
		cout << "update ERROR" << endl;
		return;
	}

	// 정상적인 상황
	pState->execute(this);
}