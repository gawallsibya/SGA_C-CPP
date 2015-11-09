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
	cout << "* 1. �� ���� �����                         *" << endl;
	cout << "* 2. �� Ÿ�� ����                           *" << endl;
	cout << "* 3. �� ����                                *" << endl;
	cout << "* 4. �� �ҷ�����                            *" << endl;
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
			init();										// ȭ�� �ʱ�ȭ
			cout << "--- �� ���� ����� ---" << endl;

			cout << "�� ũ�� ( ����, ���� ) : ";			// �� ũ�⸦ �޾Ƽ�
			cin >> point.x >> point.y;
			createMap((int)point.x, (int)point.y);		// ������ش�

			init();										// ȭ�� �ʱ�ȭ
			break;

		case '2':
			init();										// ȭ�� �ʱ�ȭ
			cout << "--- �� Ÿ�� ���� ---" << endl;

			cout << "���ϴ� ��ǥ ( �ִ� " << getStageWidth() - 2 << ", " << getStageHeight() - 1 << " ) ";
			cin >> point.x >> point.y;					// ���ϴ� ��ǥ�� �ް�

			if (point.x < 0 || point.y < 0 || point.x >= getStageWidth()-1 || point.y >= getStageHeight())
			{
				continue;								// ��ǥ���� ������ ������ �ٽ�, ������ ���
			}	

			cout << "������Ʈ ����   1. �����  2. �� " << endl;
			key = _getch();								// ���� �ٲ��� ���� �Ŀ�
			switch (key)								// ��ȣ�� �ش��ϴ� ������Ʈ�� �ٲ��ְ�
			{
			case '1': obj = OBJ_SPACE; break;
			case '2': obj = OBJ_WALL; break;
			default: break;
			}

			setTile((int)point.x, (int)point.y, obj);	// ������Ʈ�� �ٲ۴�

			init();										// ȭ�� �ʱ�ȭ
			break;

		case '3':
			init();
			cout << "--- �� ���� ---" << endl;
			
			cout << "�� �̸� : ";
			cin >> fileName;
			fileName += ".txt";
			saveMap(fileName);
			init();
			cout << "����Ǿ����ϴ�." << endl;
			break;

		case '4':
			init();
			cout << "--- �� �ҷ����� ---" << endl;

			cout << "�� �̸� : ";
			cin >> fileName;
			fileName += ".txt";
			loadMap(fileName);
			init();
			break;

		case 27:										// ������ �޼��� ���� -> ����
			return;

		default:
			break;
		}
		key = _getch();									// Ű�� �Է¹޴´�
	}
}

void Manager::end()
{
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*         �̿��� �ּż� �����մϴ�.         *" << endl;
	cout << "*********************************************" << endl;
}
