#include "Arm.h"
#include <iostream>

using std::cout;
using std::endl;

Arm::Arm()
{
	nPwrArm = 5;
}

Arm::~Arm()
{
}

void Arm::show()
{
	cout << "Arm ] --- " << nCntArm << "���� �ȷ� ������ ���� �� �ִ�." << endl;
}