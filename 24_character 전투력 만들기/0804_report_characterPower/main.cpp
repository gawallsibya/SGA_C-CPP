#include "Character.h"
#include <conio.h>

void main()
{
	Character minion;
	minion.setName("Poppy");

	minion.setArm(3);
	minion.setLeg(3);
	minion.setTail(9);

	minion.show();
	system("pause");
}