/*
���� ģ����

1. ���� ģ�� �߰�.
2. ���� ģ�� ����.
x. ����.

���� ģ���� ��Ÿ���� -> �� ������� 1����

vector, new delete Ȱ��
*/

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

int gnumber = 0;
struct Zombi	// ���ǹ�.. �׳� ������ �������
{
	string name = "����� ����";
	int number = gnumber;
};


void command(char key, Zombi *pZombi);
void createZombi(Zombi *pZombi);
void deleteZombi(Zombi *pZombi);

vector<Zombi*> gvZombies;	// ���͸� ���������� ����
void main()
{
	char key = NULL;
	Zombi *pZombi = nullptr;

	command(key, pZombi);	// ���� Ű�� ó���ϴºκ��� �Լ��� ����� key���� pzombi�� �ּҸ� �Ѱ���
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
	pZombi = new Zombi;	// �޾ƿ� �ּ��� ������ ���� ���� ����
	gnumber += 1;
	pZombi->number = gnumber;
	
	gvZombies.push_back(pZombi);	// ������ ���� ������ �ּҸ� ���Ϳ� �־���
	cout << gvZombies.back()->number << "�� " << "���� �����Ǿ����ϴ�. ( ���� " << gvZombies.size() << " ���� )" << endl;
}

void deleteZombi(Zombi *pZombi)
{
	if (!gvZombies.empty())	// ���� ���� �ʴٸ�
	{
		cout << gvZombies.front()->number << "�� ";
		pZombi = gvZombies.front();				// ������ ù��°�� �� (��������)�� ����
		delete pZombi;
		gvZombies.erase(gvZombies.begin());		// �������� ����Ű�� ���Ͱ����� ����

		 cout <<"���� �����Ǿ����ϴ�. ( ���� " << gvZombies.size() << " ���� )" << endl;
	}
	else
	{
		cout << "������ ���� �����ϴ�." << endl;
	}
}