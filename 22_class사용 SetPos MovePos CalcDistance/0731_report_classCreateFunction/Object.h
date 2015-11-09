#ifndef _OBJECT_H_
#define _OBJECT_H_

typedef struct Point
{
	float fx = 0.0f;
	float fy = 0.0f;

}POINT, *LPPOINT;

class Object
{
public:
	Object();
	~Object();

	void show();

	void setPos( float x, float y );
	void movePos( float x, float y );
	void calcDistance(POINT other);
	void showDistance();

private:
	POINT m_pos;
	float m_calc;
};

#endif /*_OBJECT_H_*/