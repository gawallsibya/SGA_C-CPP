#include "Tail.h"
#include <iostream>

using std::cout;
using std::endl;

Tail::Tail()
{
	nPwrTail = 1;
}


Tail::~Tail()
{
}

void Tail::show()
{
	cout << "Tail ] --- " << nCntTail << "���� ������ ��� �� �ִ�." << endl;
}