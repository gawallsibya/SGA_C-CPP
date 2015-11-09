/*
���� ]

[[ �۸��̿� �߿��� ]]

pet ����ü ���� ]
- �̸� , ������ , ������

�� ))
ö�� 20�ϰ� �ؿܿ����� ������.
"�ٷ���" �� "�߷���" �� �������� �ñ��.

���̸� �Ϸ翡 �ѹ� �ش�.

���̸� ������ ������ 1�� ����.
���̸� �������� ������ 2�� ����.
�����԰� 0�� �Ǹ� .. ����..

20�ϰ� ��Ƽ��..

�Լ��� ]] & ���·� ����ü ����.
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

#define DDAY  20	// �ް��� �������� ������
enum PetList{DARONG, YARONG};	// ������ �迭�� �����Ҷ��� ���� ������� enum�� ������

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
	vector<Pet*> vPets;	// ���ͷ� ����ٰ� 

	// �ʱ�ȭ
	pPet = new Pet;
	initPet(pPet, "�ٷ���", 20);
	vPets.push_back(pPet);		// 0���� �ٷ���

	pPet = new Pet;
	initPet(pPet, "�߷���", 20);
	vPets.push_back(pPet);		// 1���� �߷���

	run(key, vPets);			

	end(vPets);
}

void run(char &key, vector<Pet*> &vrPets)
{
	while (true)
	{
		// 20�� ���� ������ �������� �Ϸ羿 ���ҵ�
		for (int day = DDAY; day != 0; day--)
		{
			cout << "1 : �ٷ��� �����ֱ�     2 : �߷��� �����ֱ�    esc : ����" << endl << endl;
			cout << "�ް� ���� ����.. D-Day : " << day << endl;

			switch (key)
			{
			case '1':
				plusLovePoint(vrPets.at(DARONG));	// �ٷ����� ������ +
				minusLovePoint(vrPets.at(YARONG));	// �߷����� ������ -
				break;

			case '2':
				plusLovePoint(vrPets.at(YARONG));	// �߷����� ������ +
				minusLovePoint(vrPets.at(DARONG));	// �ٷ����� ������ -
				break;

			case 27:	// esc�� ������ ���� ����
				return;

			default:
				break;
			}

			showStatus(vrPets.at(DARONG));	// �ٷ����� ���� ���
			showStatus(vrPets.at(YARONG));	// �߷����� ���� ���

			if (isGameOver(vrPets))	// ���ӿ����� ���
			{
				cout << endl << "�ް��� ������ ����� �׾����� ���Դϴ�.." << endl;
				cout << endl << "���� ����!" << endl;

				if (isRestart(key, vrPets))	// ����ŸƮ�� �ϸ� day�� �ʱ�ȭ ���ϸ� return
				{
					day = DDAY+1;	// �ʱ�ȭ �� ������ ���Ƽ� -- ��Ű�⶧���� +1�� ������
				}
				else
				{
					return;
				}
			}
			else
			{
				inputKey(key);	// �⺻������ ������ �ѹ� ������ Ű�� �ޱ� �����ϱ����� �̰����� Ű�� �Է¹���

				if (day != 1)
				{
					system("cls");
				}
			}
		}

		if (!isGameOver(vrPets))	// ���ӿ����� �ƴҰ��
		{
			cout << endl << "�ް�ö�� ������ �������ϴ�." << endl
				<< "�̹����� ����� ������ �� �ְԵǾ����ϴ�." << endl;
			cout << endl << "Ŭ����!" << endl;

			if (!isRestart(key, vrPets))	// ����ŸƮ�� ���ϸ� return
			{
				return;
			}
		}

	}

}


void plusLovePoint(Pet *&prPet)
{
	prPet->lovePoint += 1;	// ������ +1
}

void minusLovePoint(Pet *&prPet)
{
	prPet->lovePoint -= 2;	// ������ -2
}

void showStatus(Pet *&prPet)
{
	// �� ���� ���
	cout << prPet->name << "�� ������ : " << prPet->lovePoint << endl;
}

bool isGameOver(vector<Pet*> &vrPets)
{
	// ����� �������� 0�������� Ȯ��, 0���ϸ� ���ӿ���, true ��ȯ
	for (Pet *&pet : vrPets)
	{
		if (pet->lovePoint <= 0)
		{
			cout << endl << pet->name << "(��)�� ���� ���ĳ������ϴ�!!" << endl;
			return true;
		}
	}
	return false;
}

bool isRestart(char &key, vector<Pet*> &vrPets)
{
	while (true)
	{
		cout << endl << "�ٽ� �����Ͻðڽ��ϱ�? ( y / n )" << endl;
		inputKey(key);	// Ű���� �Է¹���

		switch (key)
		{
		case 'y':
		case 'Y':
			initPet(vrPets.at(DARONG), "�ٷ���", 20);	// �ٷ��� �� ���� �ʱ�ȭ
			initPet(vrPets.at(YARONG), "�߷���", 20);	// �Ʒ��� �� ���� �ʱ�ȭ
			system("cls");	// y�� ������ ȭ�� Ŭ���� ���ְ� true�� ��ȯ
			return true;

		case 'n':
		case 'N':
			return false;	// n�� ������ fasle ��ȯ

		default:
			cout << "�߸� �����̽��ϴ�." << endl;		// ����ó��
			
		}
	}
}

void inputKey(char &key)
{
	key = _getch();

	// �ý���Ű�ϰ�� ó��
	if (_kbhit())
	{
		key = _getch();
	}
}

void initPet(Pet *&prPet, string name, int lovePoint)
{
	// �ʱ�ȭ��ų �� ���� ����
	prPet->name = name;
	prPet->lovePoint = lovePoint;
}

void end(vector<Pet*> &vPets)
{
	// ������ ���鼭 �����ּҸ� �����޾� ����
	for (Pet *&pet : vPets)
	{
		delete pet;
	}

	// ���� ����
	vPets.~vector();

	// ���� ���� �ȳ��� ���
	cout << endl << "������ ����Ǿ����ϴ�." << endl << endl;
}