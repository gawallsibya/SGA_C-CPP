#ifndef _LEG_H_
#define _LEG_H_

/*
�ٸ�
*/

class Leg
{
public:
	Leg();
	~Leg();

	void show();
	void setLeg(int nCnt)	{ nCntLeg = nCnt; }
	int getLeg()			{ return nCntLeg; }
	int getLegPwr()			{ return nPwrLeg; }
private:
	int nCntLeg;	// ���� ����
	int nPwrLeg;
};
#endif /*_LEG_H_*/