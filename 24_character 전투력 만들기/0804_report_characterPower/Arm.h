#ifndef _ARM_H_
#define _ARM_H_

/*
��
*/

class Arm
{
public:
	Arm();
	~Arm();

	void show();
	void setArm(int nCnt)	{ nCntArm = nCnt; }
	int getArm()			{ return nCntArm; }
	int getArmPwr()			{ return nPwrArm; }
private:
	int nCntArm;	// ���� ����
	int nPwrArm;
};

#endif /*_ARM_H_*/