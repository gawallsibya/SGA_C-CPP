/*
과제 ]

[[ 멍멍이와 야옹이 ]]

pet 구조체 정의 ]
- 이름 , 몸무게 , 애정도

예 ))
철수 20일간 해외여행을 떠난다.
"다롱이" 와 "야롱이" 를 순자한테 맡긴다.

먹이를 하루에 한번 준다.

먹이를 먹으면 애정도 1씩 증가.
먹이를 못먹으면 애정도 2씩 감소.
몸무게가 0이 되면 .. 가출..

20일간 버티기..

함수는 ]] & 형태로 구조체 전달.
*/

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

struct Pet
{
	string name;
	int lovePoint;
};

#define DDAY  20	// 휴가일 보기좋게 만들어둠
enum PetList{DARONG, YARONG};	// 벡터의 배열을 관리할때를 위해 순차대로 enum을 만들어둠

void run(char &key, vector<Pet*>&vprPets);
void plusLovePoint(Pet *&prPet);
void minusLovePoint(Pet *&prPet);
void showStatus(Pet *&prPet);
bool isGameOver(vector<Pet*> &vrPets);
bool isRestart(char &key, vector<Pet*> &vrPets);
void inputKey(char &key);
void initPet(Pet *&prPet, string name, int lovePoint);
void end(vector<Pet*> &vPets);

void main()
{
	char key = NULL;
	Pet *pPet = nullptr;
	vector<Pet*> vPets;	// 벡터로 담아줄거 

	// 초기화
	pPet = new Pet;
	initPet(pPet, "다롱이", 20);
	vPets.push_back(pPet);		// 0번은 다롱이

	pPet = new Pet;
	initPet(pPet, "야롱이", 20);
	vPets.push_back(pPet);		// 1번은 야롱이

	run(key, vPets);			

	end(vPets);
}

void run(char &key, vector<Pet*> &vrPets)
{
	while (true)
	{
		// 20일 기준 루프가 돌때마다 하루씩 감소됨
		for (int day = DDAY; day != 0; day--)
		{
			cout << "1 : 다롱이 먹이주기     2 : 야롱이 먹이주기    esc : 종료" << endl << endl;
			cout << "휴가 복귀 까지.. D-Day : " << day << endl;

			switch (key)
			{
			case '1':
				plusLovePoint(vrPets.at(DARONG));	// 다롱이의 애정도 +
				minusLovePoint(vrPets.at(YARONG));	// 야롱이의 애정도 -
				break;

			case '2':
				plusLovePoint(vrPets.at(YARONG));	// 야롱이의 애정도 +
				minusLovePoint(vrPets.at(DARONG));	// 다롱이의 애정도 -
				break;

			case 27:	// esc를 누르면 루프 종료
				return;

			default:
				break;
			}

			showStatus(vrPets.at(DARONG));	// 다롱이의 정보 출력
			showStatus(vrPets.at(YARONG));	// 야롱이의 정보 출력

			if (isGameOver(vrPets))	// 게임오버일 경우
			{
				cout << endl << "휴가가 끝나면 당신은 죽어있을 것입니다.." << endl;
				cout << endl << "게임 오버!" << endl;

				if (isRestart(key, vrPets))	// 리스타트를 하면 day값 초기화 안하면 return
				{
					day = DDAY+1;	// 초기화 후 루프를 돌아서 -- 시키기때문에 +1을 더해줌
				}
				else
				{
					return;
				}
			}
			else
			{
				inputKey(key);	// 기본적으로 루프를 한번 돌고나서 키를 받기 시작하기위해 이곳에서 키를 입력받음

				if (day != 1)
				{
					system("cls");
				}
			}
		}

		if (!isGameOver(vrPets))	// 게임오버가 아닐경우
		{
			cout << endl << "휴가철이 무사히 끝났습니다." << endl
				<< "이번에도 목숨을 연명할 수 있게되었습니다." << endl;
			cout << endl << "클리어!" << endl;

			if (!isRestart(key, vrPets))	// 리스타트를 안하면 return
			{
				return;
			}
		}

	}

}


void plusLovePoint(Pet *&prPet)
{
	prPet->lovePoint += 1;	// 애정도 +1
}

void minusLovePoint(Pet *&prPet)
{
	prPet->lovePoint -= 2;	// 애정도 -2
}

void showStatus(Pet *&prPet)
{
	// 펫 정보 출력
	cout << prPet->name << "의 애정도 : " << prPet->lovePoint << endl;
}

bool isGameOver(vector<Pet*> &vrPets)
{
	// 펫들의 애정도가 0이하인지 확인, 0이하면 게임오버, true 반환
	for (Pet *&pet : vrPets)
	{
		if (pet->lovePoint <= 0)
		{
			cout << endl << pet->name << "(이)가 집을 뛰쳐나갔습니다!!" << endl;
			return true;
		}
	}
	return false;
}

bool isRestart(char &key, vector<Pet*> &vrPets)
{
	while (true)
	{
		cout << endl << "다시 시작하시겠습니까? ( y / n )" << endl;
		inputKey(key);	// 키값을 입력받음

		switch (key)
		{
		case 'y':
		case 'Y':
			initPet(vrPets.at(DARONG), "다롱이", 20);	// 다롱이 펫 정보 초기화
			initPet(vrPets.at(YARONG), "야롱이", 20);	// 아롱이 펫 정보 초기화
			system("cls");	// y를 누르면 화면 클리어 해주고 true를 반환
			return true;

		case 'n':
		case 'N':
			return false;	// n을 누르면 fasle 반환

		default:
			cout << "잘못 누르셨습니다." << endl;		// 예외처리
			
		}
	}
}

void inputKey(char &key)
{
	key = _getch();

	// 시스템키일경우 처리
	if (_kbhit())
	{
		key = _getch();
	}
}

void initPet(Pet *&prPet, string name, int lovePoint)
{
	// 초기화시킬 펫 정보 대입
	prPet->name = name;
	prPet->lovePoint = lovePoint;
}

void end(vector<Pet*> &vPets)
{
	// 루프를 돌면서 동적주소를 참조받아 제거
	for (Pet *&pet : vPets)
	{
		delete pet;
	}

	// 벡터 삭제
	vPets.~vector();

	// 게임 종료 안내말 출력
	cout << endl << "게임이 종료되었습니다." << endl << endl;
}