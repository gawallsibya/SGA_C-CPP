#include "Leg.h"
#include <iostream>

using std::cout;
using std::endl;

Leg::Leg()
{
	nPwrLeg = 3;
}

Leg::~Leg()
{
}

void Leg::show()
{
	cout << "Arm ] --- " << nCntLeg << "개의 다리로 걸을 수 있다." << endl;
}