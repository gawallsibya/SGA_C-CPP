/*
	// 과제 ]]

	p3 = sumPoint(p1, p2);

	p3 = p1.sum(p2);
*/

#include <stdio.h>

struct POINT
{
	float fX;
	float fY;

	void show()
	{
		printf("---show point---\n");
		printf("X = %.2f , Y = %.2f\n", fX, fY);
	}

	POINT sum(POINT *p)
	{
		return{ fX + p->fX, fY + p->fY };	// 된다. 결과 값을 포인트의 flaot flaot 형에 return으로 넘겨서 넣어준다.
	}
};

POINT sumPoint(POINT p1, POINT p2);

void main()
{
	POINT p1 = { 1.0f, 2.0f };
	POINT p2 = { 5.0f, 6.0f };
	POINT p3 = {};

	p3.fX = p1.fX + p2.fX;
	p3.fY = p1.fY + p2.fY;

	p3.show();

	p3 = sumPoint(&p1, &p2);
	p3.show();

	p3 = p1.sum(&p2);
	p3.show();
}

POINT sumPoint(POINT *p1, POINT *p2)
{
	return { p1->fX + p2->fX, p1->fY + p2->fY };
}