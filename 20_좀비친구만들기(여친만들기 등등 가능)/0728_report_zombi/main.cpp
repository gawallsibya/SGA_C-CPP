/*
좀비 친구들

1. 좀비 친구 추가.
2. 좀비 친구 삭제.
x. 종료.

좀비 친구가 나타났다 -> 총 좀비수는 1마리

vector, new delete 활용
*/

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

int gnumber = 0;
struct Zombi	// 무의미.. 그냥 좀비라고 만들어줌
{
	string name = "양산형 좀비";
	int number = gnumber;
};


void command(char key, Zombi *pZombi);
void createZombi(Zombi *pZombi);
void deleteZombi(Zombi *pZombi);

vector<Zombi*> gvZombies;	// 벡터를 전역변수로 선언
void main()
{
	char key = NULL;
	Zombi *pZombi = nullptr;

	command(key, pZombi);	// 받은 키로 처리하는부분을 함수로 만들어 key값과 pzombi의 주소를 넘겨줌
}

void command(char key, Zombi *pZombi)
{
	while (true)
	{
		key = _getch();

		if (_kbhit())
		{
			key = _getch();
		}

		switch (key)
		{
		case '1':
			createZombi(pZombi);
			break;

		case '2':
			deleteZombi(pZombi);
			break;

		case 'x':
		case 'X':
			return;

		default:
			break;
		}
	}
	
}

void createZombi(Zombi *pZombi)
{
	pZombi = new Zombi;	// 받아온 주소의 값으로 동적 좀비 생성
	gnumber += 1;
	pZombi->number = gnumber;
	
	gvZombies.push_back(pZombi);	// 생성한 동적 좀비의 주소를 벡터에 넣어줌
	cout << gvZombies.back()->number << "번 " << "좀비가 생성되었습니다. ( 현재 " << gvZombies.size() << " 마리 )" << endl;
}

void deleteZombi(Zombi *pZombi)
{
	if (!gvZombies.empty())	// 값이 없지 않다면
	{
		cout << gvZombies.front()->number << "번 ";
		pZombi = gvZombies.front();				// 벡터의 첫번째의 값 (동적좀비)를 제거
		delete pZombi;
		gvZombies.erase(gvZombies.begin());		// 동적좀비를 가르키는 벡터공간도 제거

		 cout <<"좀비가 삭제되었습니다. ( 현재 " << gvZombies.size() << " 마리 )" << endl;
	}
	else
	{
		cout << "삭제할 좀비가 없습니다." << endl;
	}
}