/*
���� ] ���� �� ����Ʈ �����

1. APINK	Mr.Chu
2. AOA		�ܹ߸Ӹ�
3. GirlsDay	Darling
...

-------------------
1�� �� �߰� ( �� �ڿ� )
2�� �� ���� ( ���ϴ� �κ� )
3�� �� ���� ( ��� �� ���̿� )
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct music
{
	char m_title[30];
	char m_musician[30];
	int m_key;
	music *m_pNext;
	music *m_pPrev;

	char *getTitle()
	{
		return m_title;
	}

	void setTitle(char *pTitle)
	{
		strncpy(m_title, pTitle, 30);
	}

	char *getMusician()
	{
		return m_musician;
	}

	void setMusician(char *pMusician)
	{
		strncpy(m_musician, pMusician, 30);
	}
	
	int getKey()
	{
		return m_key;
	}

	void setKey(int key)
	{
		m_key = key;
	}

	music *getNext()
	{
		return m_pNext;
	}
	
	void setNext(music *pNext)
	{
		m_pNext = pNext;
	}

	music *getPrev()
	{
		return m_pPrev;
	}

	void setPrev(music *pPrev)
	{
		m_pPrev = pPrev;
	}

}MUSIC;

void addMusic(char *pTitle, char *pMusician);
void showMusicList();
void selectButton(char btn);
music *findMusic();
void deleteMusic();
void inTitle();
void inMusician();
void turnChangeMusic();
music *findfirstMusic();
static music s_musicList[255] = {};	// �ִ� ���� ���� 255���� ����
static char s_title[30] = {};		// �Է¹����� �Լ��� �Ѱ��༭ �Է��� ������ �����ͷ� �޾Ƽ� �Է¹޾Ƽ� �迭�� ũ��� ������� ���� �ԷµǱ淡 
									// �����ϰ� �������� ���..
static char s_musician[30] = {};	// ���ϵ���
static music *s_startMusicList = s_musicList;	// ����� ���۽�ų�κ� 
void main()
{
	char btn = NULL;

	// ���� ���� ����Ʈ
	addMusic("Touch my body", "����Ÿ");
	addMusic("����� ������(Feat.�迹��, UL)", "�ڸ��");
	addMusic("Darling", "�ɽ�����(Girl`s Day)");
	addMusic("�ѿ������� ��", "����(San E), ���̳�");

	while (btn != 27)
	{
		// �ȳ���
		printf("1�� �� �߰�(�� �ڿ�)\n");
		printf("2�� �� ����(���ϴ� �κ�)\n");
		printf("3�� �� ����(��� �� ���̿�)\n\n");
		
		// ���Ǹ���Ʈ�� ���
		showMusicList();

		if (_kbhit())
		{
			btn = _getch();
		}

		btn = _getch();

		// 1, 2, 3 �� ���� ��ư�� ���� �ش� ��� ����
		selectButton(btn);		

		system("cls");
	}
}

void addMusic(char *pTitle, char *pMusician)
{
	// ���� , ���ǰ� ���� ����
	bool b = true;
	int i = 0;
	while (b)
	{
		if (s_musicList[i].getKey() == NULL)
		{
			s_musicList[i].setTitle(pTitle);
			s_musicList[i].setMusician(pMusician);
			s_musicList[i].setKey(NULL);
			s_musicList[i].setNext(nullptr);
			s_musicList[i].setPrev(nullptr);
			b = false;
		}
		else
		{
			i += 1;
		}
	}
	
	b = true;
	music *pTemp = s_musicList;
	while (b)
	{
		if (pTemp->getNext() == nullptr)
		{
			s_musicList[i].setNext(pTemp->getNext());
			s_musicList[i].setKey(pTemp->getKey() + 1);
			
			if (i != 0)
			{
				s_musicList[i].setPrev(pTemp);
				pTemp->setNext(&s_musicList[i]);
			}
			b = false;
		}
		else
		{
			pTemp = pTemp->getNext();
		}
	}

}

void showMusicList()
{
	for (music *pTemp = findfirstMusic(); pTemp != nullptr; pTemp = pTemp->getNext())
	{

		printf("-------------------------------\n");
		printf("%d. ���� : %s\n", pTemp->getKey(), pTemp->getTitle());
		printf("   ���ǰ� : %s\n", pTemp->getMusician());
	}
}

void selectButton(char btn)
{
	switch (btn)
	{
	case '1':
		inTitle();						// ���� �Է¹ޱ�
		inMusician();					// ���ǰ� �Է¹ޱ�
		addMusic(s_title, s_musician);	// ���� �ֱ�
		break; 

	case '2':
		inTitle();		// ���� �Է¹ޱ�
		deleteMusic();	// ���� ����
		break;

	case '3':
		turnChangeMusic();		// ���� ���� ����
		break;

	default:
		break;
	}
}

void deleteMusic()
{
	music *pTemp = findMusic();
	// ����ó��
	if (pTemp == nullptr)
	{
		printf("�����Ϸ��� ������ �����ϴ�.\n");
		return;
	}
	// key ���� ��������� -1 �� ��Ŵ
	for (music *pTemp2 = pTemp; pTemp2 != nullptr; pTemp2 = pTemp2->getNext())
	{
		pTemp2->setKey(pTemp2->getKey() - 1);
	}

	// �Ӹ� ���� ����
	pTemp->getPrev()->setNext(pTemp->getNext());
	pTemp->getNext()->setPrev(pTemp->getPrev());

	// ���� �迭 �ʱ�ȭ..?
	pTemp->setTitle("");
	pTemp->setMusician("");
	pTemp->setKey(NULL);
	pTemp->setNext(nullptr);
	pTemp->setPrev(nullptr);

}

void turnChangeMusic()
{
	int select = NULL, target = NULL;
	printf("���� ����\n");
	fflush(stdin);
	scanf("%d", &select);					// ��ȣ �Է¹ޱ�
	printf("�ٲ� ���� ����\n");
	fflush(stdin);
	scanf("%d", &target);

	music *pSelect = nullptr, *pTarget = nullptr;
	music *pTemNext = nullptr, *pTemPrev = nullptr;
	int ntemp = NULL;
	for (music *pTemp = findfirstMusic(); pTemp != nullptr; pTemp = pTemp->getNext())
	{
		if (pTemp->getKey() == select)
		{
			pSelect = pTemp;
			pTemNext = pSelect->getNext();
			pTemPrev = pSelect->getPrev();
		}
		else if (pTemp->getKey() == target)
		{
			pTarget = pTemp;
		}
		
	}
	
	pSelect->setNext(pTarget->getNext());
	pSelect->setPrev(pTarget->getPrev());
	if (pTarget->getNext() != nullptr)
	{
		pTarget->getNext()->setPrev(pSelect);
	}
	if (pTarget->getPrev() != nullptr)
	{
		pTarget->getPrev()->setNext(pSelect);
	}
	

	pTarget->setNext(pTemNext);
	pTarget->setPrev(pTemPrev);

	if (pTemPrev->getNext() != nullptr)
	{
		pTemPrev->setNext(pTarget);
	}
	else if (pTemNext->getPrev() != nullptr)
	{
		pTemNext->setPrev(pTarget);
	}
	

	ntemp = pSelect->getKey();
	pSelect->setKey(pTarget->getKey());
	pTarget->setKey(ntemp);

	system("pause");
}

music *findMusic()
{
	for (music *pTemp = findfirstMusic(); pTemp != nullptr; pTemp = pTemp->getNext())
	{
		//strcmp�� �����ڿ� �����ڸ� ���Ͽ� >0 �ϰ�� �� > �� , ==0 �ϰ�� �� == �� , <0 �ϰ�� �� < ��  
		if (strcmp(pTemp->getTitle(), s_title) == 0)
		{
			return pTemp;
		}
	}
	return nullptr;
}

void inTitle()
{
	printf("���� : ");
	fflush(stdin);
	scanf("%s", s_title);
}

void inMusician()
{
	printf("���ǰ� : ");
	fflush(stdin);
	scanf("%s", s_musician);
}

music *findfirstMusic()
{
	int i = 0;
	bool b = true;
	while (b)
	{
		if (s_musicList[i].getKey() == 1)
		{
			b = false;
		}
		else
		{
			i += 1;
		}
	}
	return &s_musicList[i];
}

// Fail..