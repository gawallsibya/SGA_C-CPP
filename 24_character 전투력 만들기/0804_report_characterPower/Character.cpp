#include "Character.h"
#include <iostream>

using std::cout;
using std::endl;

Character::Character()
{
}

Character::~Character()
{
}

void Character::show()
{
	cout << "내 이름은 " << name << endl;
	Arm::show();
	Leg::show();
	Tail::show();

	cout << "내 전투력은 " << getPower() << endl;
}
