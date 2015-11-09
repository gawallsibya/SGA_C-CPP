/*
과제 ]
String class 활용
compare 활용 or find 활용

c	: str[][10] = { "first, second, third" };
c++	: string[5] = ....;

다섯개의 단어 배열
___, ___, ___, ___, ___

입력 : ___
해당 단어를 삭제
*/

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string strs[5] = { "관자놀이", "멘탈붕괴", "나로호", "ERROR", "헤헿헿헿" };
	string result;

	while (true)
	{
		// 배열 출력
		for (int i = 0; i < 5; i++)
		{
			cout << strs[i];
			if (i == 4)
			{
				cout << endl;
			}
			else
			{
				cout << "   ";
			}
		}

		// 입력
		cout << "입력 : ";
		cin >> result;
		for (int i = 0; i < 5; i++)
		{
			if (!strs[i].compare(result))	// 맞으면 값 지우기
			{		
				strs[i] = "";
			}
		}
		system("cls");
	}
}
