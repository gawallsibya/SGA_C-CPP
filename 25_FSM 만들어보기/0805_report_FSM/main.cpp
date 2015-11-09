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

	// �⺻ == ���
	// �� �ν� == ����
	// �� �ν����� == ���
	// ü�� �����̻� ���� - �� �ν� == ����ô
	// ü�� ���� - �� �ν����� == �޽�
	// ü�� ȸ�� �Ϸ� - ���

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
			cout << "�׾" << endl;
		}
		else if (isAfum)
		{
			cout << "����" << endl;
		}

		if (isInsik)
		{
			cout << "�ν���" << endl;
			if (isJukugam)
			{
				cout << endl << "npc�� ����ô�Ѵ�." << endl;
			}
			else
			{
				cout << endl << "npc�� �����Ѵ�." << endl;
			}
		}
		else
		{
			cout << "�ν� ���ϴ���" << endl;
			if (isAfum)
			{
				cout << endl << "npc�� �޽��� ���Ѵ�." << endl;
			}
			else
			{
				cout << endl << "npc�� ����ִ�." << endl;
			}
		}
	

		cout << endl << "1 : �ν�   2 : �ν�����   3 : ����   4 : �׾   5 : ����" << endl;

		cin >> sanghwang;

		system("cls");
	}
}