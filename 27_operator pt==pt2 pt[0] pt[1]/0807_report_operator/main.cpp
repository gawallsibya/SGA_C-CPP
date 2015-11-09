#include <iostream>

using std::cout;
using std::endl;

typedef class point
{
public:
	point(float x, float y)	{ fX = x; fY = y; }
	~point(){}

public:
	void show();

	bool operator==(point &pt);
	float operator[](int index);
	void operator!();

private:
	float fX;
	float fY;

}POINT;

void point::show()
{
	cout << "fX = " << fX << "  fY = " << fY << endl;
}

bool point::operator==(point &pt)
{
	if (fX == pt.fX &&	fY == pt.fY)
	{
		return true;
	}
	return false;
}

float point::operator[](int index)
{
	// index가 2 이상이면 -1 리턴
	if ((sizeof(this) / sizeof(float)) < index)
	{
		cout << "operator[](int index) ERROR" << endl;
		return -1;
	}
	else
	{
		return (&(this->fX))[index];	// 뻘짓 해봄
	}
}

void point::operator!()
{
	fX *= -1.0f;
	fY *= -1.0f;
}

// 과제]
// 1. 멤버 변수가 서로 같은가 비교
//bool bFlag = (pt == pt2);

// 2. 멤버 변수를 가져오기
//float fX = pt[0];
//float fY = pt[1];
//pt[2];	<- 이건 안되게...

// 3. 부호 바꾸기 ( 양수 <-> 음수 )
// !pt

void main()
{
	POINT pt(1.2f, 7.8f);
	POINT pt2(5.5f, 6.6f);


	// 1.
	bool bFlag = (pt == pt2);

	cout << "bFlag = " << bFlag << endl;

	// 2.
	float fX = pt[0];
	float fY = pt[1];

	cout << "fX = " << fX << "  fY = " << fY << endl;

	// 3. 
	!pt;

	pt.show();

	system("pause");

}