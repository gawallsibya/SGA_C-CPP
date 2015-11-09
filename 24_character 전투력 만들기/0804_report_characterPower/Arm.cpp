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
	cout << "Arm ] --- " << nCntArm << "개의 팔로 물건을 잡을 수 있다." << endl;
}