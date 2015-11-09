#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

enum state
{
	DEFAULT,
	INSIK,
	ANINSIK,
	AFUM,
	JUKUGAM,
	NAUM
};

void main()
{
	int sanghwang = DEFAULT;
	bool isJukugam = false;
	bool isAfum = false;
	bool isInsik = false;

	// 기본 == 대기
	// 적 인식 == 도주
	// 적 인식해제 == 대기
	// 체력 절반이상 달음 - 적 인식 == 죽은척
	// 체력 달음 - 적 인식해제 == 휴식
	// 체력 회복 완료 - 대기

	while (true)
	{
		switch (sanghwang)
		{
		case INSIK:
			isInsik = true;			
			break;

		case ANINSIK:
			isInsik = false;
			break;

		case AFUM:
			isAfum = true;
			break;

		case JUKUGAM:
			isJukugam = true;
			isAfum = true;
			break;

		case NAUM:
			isJukugam = false;
			isAfum = false;
			break;

		default:
			break;
		}
		if (isJukugam)
		{
			cout << "죽어감" << endl;
		}
		else if (isAfum)
		{
			cout << "아픔" << endl;
		}

		if (isInsik)
		{
			cout << "인식중" << endl;
			if (isJukugam)
			{
				cout << endl << "npc가 죽은척한다." << endl;
			}
			else
			{
				cout << endl << "npc가 도주한다." << endl;
			}
		}
		else
		{
			cout << "인식 안하는중" << endl;
			if (isAfum)
			{
				cout << endl << "npc가 휴식을 취한다." << endl;
			}
			else
			{
				cout << endl << "npc가 놀고있다." << endl;
			}
		}
	

		cout << endl << "1 : 인식   2 : 인식해제   3 : 아픔   4 : 죽어감   5 : 나음" << endl;

		cin >> sanghwang;

		system("cls");
	}
}