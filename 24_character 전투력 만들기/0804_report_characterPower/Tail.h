#ifndef _TAIL_H_
#define _TAIL_H_

/*
����
*/

class Tail
{
public:
	Tail();
	~Tail();

	void show();
	void setTail(int nCnt)	{ nCntTail = nCnt; }
	int getTail()			{ return nCntTail; }
	int getTailPwr()		{ return nPwrTail; }
private:
	int nCntTail;	// ���� ����
	int nPwrTail;
};

#endif /*_TAIL_H_*/
