/*
���� ]
String class Ȱ��
compare Ȱ�� or find Ȱ��

c	: str[][10] = { "first, second, third" };
c++	: string[5] = ....;

�ټ����� �ܾ� �迭
___, ___, ___, ___, ___

�Է� : ___
�ش� �ܾ ����
*/

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string strs[5] = { "���ڳ���", "��Ż�ر�", "����ȣ", "ERROR", "���m�m�m" };
	string result;

	while (true)
	{
		// �迭 ���
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

		// �Է�
		cout << "�Է� : ";
		cin >> result;
		for (int i = 0; i < 5; i++)
		{
			if (!strs[i].compare(result))	// ������ �� �����
			{		
				strs[i] = "";
			}
		}
		system("cls");
	}
}
