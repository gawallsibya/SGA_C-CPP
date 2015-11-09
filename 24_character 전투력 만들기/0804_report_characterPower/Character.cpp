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
	cout << "�� �̸��� " << name << endl;
	Arm::show();
	Leg::show();
	Tail::show();

	cout << "�� �������� " << getPower() << endl;
}
