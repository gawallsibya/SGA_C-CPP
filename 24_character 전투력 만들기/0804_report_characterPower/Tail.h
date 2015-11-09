#ifndef _TAIL_H_
#define _TAIL_H_

/*
꼬리
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
	int nCntTail;	// 발의 개수
	int nPwrTail;
};

#endif /*_TAIL_H_*/
