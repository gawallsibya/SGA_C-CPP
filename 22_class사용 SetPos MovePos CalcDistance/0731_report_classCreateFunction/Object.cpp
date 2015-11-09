#include "Object.h"

#include <iostream>
#include <math.h>

using namespace std;

Object::Object()
{
	cout << "--------------constructor--------------" << endl;
}
Object::~Object()
{
	cout << "--------------destructor---------------" << endl;
}

void Object::show()
{
	cout << "--------------Object Class--------------" << endl;
	cout << "posX = " << m_pos.fx << " , " << "posY = " << m_pos.fy << endl;
}


void Object::setPos(float x, float y)
{
	m_pos.fx = x;
	m_pos.fy = y;
}

void Object::movePos(float x, float y)
{
	m_pos.fx += x;
	m_pos.fy += y;
}

void Object::calcDistance(POINT other)
{
	m_calc = sqrtf(powf(m_pos.fx - other.fx, 2) + powf(m_pos.fy - other.fy, 2));
}

void Object::showDistance()
{
	cout << "--------------Object Class--------------" << endl;
	cout << "두 좌표간의 거리 = " << m_calc << endl;
}