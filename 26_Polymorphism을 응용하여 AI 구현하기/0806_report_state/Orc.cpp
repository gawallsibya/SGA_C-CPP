#include "Orc.h"
#include <iostream>

using std::cout;
using std::endl;

Orc::Orc()
{
	// ������¸� IDLE �� �⺻����
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
	// ����üũ
	if (pState == nullptr || pNewState == nullptr)
	{
		cout << "changeState ERROR" << endl;
		return;
	}

	// �������� ��Ȳ

	// ���� ���� ��Ż
	pState->exit(this);
	// ���� ���� ����
	delete pState;

	// ���ο� ���¸� ���� ���·� ����
	pState = pNewState;
	// ���ο� ���·� ����
	pState->enter(this);
}

void Orc::update()
{
	// ����üũ
	if (pState == nullptr)
	{
		cout << "update ERROR" << endl;
		return;
	}

	// �������� ��Ȳ
	pState->execute(this);
}