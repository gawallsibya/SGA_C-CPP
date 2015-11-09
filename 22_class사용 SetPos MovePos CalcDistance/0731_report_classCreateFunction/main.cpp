#include "Object.h"

void main()
{
	Object enemy;

	enemy.show();

	enemy.setPos(5.0f, 5.0f);
	enemy.show();

	enemy.movePos(5.0f, -5.0f);
	enemy.show();

	POINT other;
	other.fx = 5.0f;
	other.fy = 0.0f;

	enemy.calcDistance(other);
	enemy.showDistance();
}