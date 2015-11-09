#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Arm.h"
#include "Leg.h"
#include "Tail.h"
#include <string>

using std::string;

/*
Ä³¸¯ÅÍ
*/

class Character : public Arm, public Leg, public Tail
{
public:
	Character();
	~Character();

	void setName(string str)	{ name = str; }
	string getName()			{ return name; }
	int getPower()		//	???????????????		
	{ 
		power = getArmPwr()*getArm() + getLegPwr()*getLeg() + getTailPwr()*getTail();
		return power;	
	}
	void show();
private:
	string name;
	int power;

};

#endif /*_CHARACTER_H_*/