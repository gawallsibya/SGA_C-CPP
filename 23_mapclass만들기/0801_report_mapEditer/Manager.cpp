#include "Manager.h"
#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

Manager::Manager()
{
	key = 0;
	point = {};
	obj = {};
	fileName = "";
}

Manager::~Manager()
{
}

void Manager::init()
{
	system("cls");

	cout << "*********************************************" << endl;
	cout << "*         -- Console Map Editer --          *" << endl;
	cout << "* 1. 맵 새로 만들기                         *" << endl;
	cout << "* 2. 맵 타일 수정                           *" << endl;
	cout << "* 3. 맵 저장                                *" << endl;
	cout << "* 4. 맵 불러오기                            *" << endl;
	cout << "*********************************************" << endl;

	renderMap();
}

void Manager::run()
{
	while (true)
	{		
		switch (key)
		{
		case '1':
			init();										// 화면 초기화
			cout << "--- 맵 새로 만들기 ---" << endl;

			cout << "맵 크기 ( 가로, 세로 ) : ";			// 맵 크기를 받아서
			cin >> point.x >> point.y;
			createMap((int)point.x, (int)point.y);		// 만들어준다

			init();										// 화면 초기화
			break;

		case '2':
			init();										// 화면 초기화
			cout << "--- 맵 타일 수정 ---" << endl;

			cout << "원하는 좌표 ( 최대 " << getStageWidth() - 2 << ", " << getStageHeight() - 1 << " ) ";
			cin >> point.x >> point.y;					// 원하는 좌표를 받고

			if (point.x < 0 || point.y < 0 || point.x >= getStageWidth()-1 || point.y >= getStageHeight())
			{
				continue;								// 좌표값이 문제가 있으면 다시, 없으면 계속
			}	

			cout << "오브젝트 선택   1. 빈공간  2. 벽 " << endl;
			key = _getch();								// 뭐로 바꿀지 정한 후에
			switch (key)								// 번호에 해당하는 오브젝트로 바꿔주고
			{
			case '1': obj = OBJ_SPACE; break;
			case '2': obj = OBJ_WALL; break;
			default: break;
			}

			setTile((int)point.x, (int)point.y, obj);	// 오브젝트를 바꾼다

			init();										// 화면 초기화
			break;

		case '3':
			init();
			cout << "--- 맵 저장 ---" << endl;
			
			cout << "맵 이름 : ";
			cin >> fileName;
			fileName += ".txt";
			saveMap(fileName);
			init();
			cout << "저장되었습니다." << endl;
			break;

		case '4':
			init();
			cout << "--- 맵 불러오기 ---" << endl;

			cout << "맵 이름 : ";
			cin >> fileName;
			fileName += ".txt";
			loadMap(fileName);
			init();
			break;

		case 27:										// 누르면 메서드 나감 -> 종료
			return;

		default:
			break;
		}
		key = _getch();									// 키를 입력받는다
	}
}

void Manager::end()
{
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*         이용해 주셔서 감사합니다.         *" << endl;
	cout << "*********************************************" << endl;
}
