/*
과제 ] 나의 곡 리스트 만들기

1. APINK	Mr.Chu
2. AOA		단발머리
3. GirlsDay	Darling
...

-------------------
1번 곡 추가 ( 맨 뒤에 )
2번 곡 삭제 ( 원하는 부분 )
3번 곡 삽입 ( 곡과 곡 사이에 )
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
static music s_musicList[255] = {};	// 최대 음악 저장 255까지 가능
static char s_title[30] = {};		// 입력받을때 함수에 넘겨줘서 입력을 받으면 포인터로 받아서 입력받아서 배열의 크기와 상관없이 마구 입력되길래 
									// 안전하게 전역으로 사용..
static char s_musician[30] = {};	// 이하동문
static music *s_startMusicList = s_musicList;	// 재생시 시작시킬부분 
void main()
{
	char btn = NULL;

	// 샘플 뮤직 리스트
	addMusic("Touch my body", "씨스타");
	addMusic("명수네 떡볶이(Feat.김예림, UL)", "박명수");
	addMusic("Darling", "걸스데이(Girl`s Day)");
	addMusic("한여름밤의 꿀", "산이(San E), 레이나");

	while (btn != 27)
	{
		// 안내문
		printf("1번 곡 추가(맨 뒤에)\n");
		printf("2번 곡 삭제(원하는 부분)\n");
		printf("3번 곡 삽입(곡과 곡 사이에)\n\n");
		
		// 음악리스트를 출력
		showMusicList();

		if (_kbhit())
		{
			btn = _getch();
		}

		btn = _getch();

		// 1, 2, 3 번 등의 버튼에 따른 해당 기능 수행
		selectButton(btn);		

		system("cls");
	}
}

void addMusic(char *pTitle, char *pMusician)
{
	// 제목 , 음악가 정보 셋팅
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
		printf("%d. 제목 : %s\n", pTemp->getKey(), pTemp->getTitle());
		printf("   음악가 : %s\n", pTemp->getMusician());
	}
}

void selectButton(char btn)
{
	switch (btn)
	{
	case '1':
		inTitle();						// 제목 입력받기
		inMusician();					// 음악가 입력받기
		addMusic(s_title, s_musician);	// 음악 넣기
		break; 

	case '2':
		inTitle();		// 제목 입력받기
		deleteMusic();	// 음악 삭제
		break;

	case '3':
		turnChangeMusic();		// 음악 순서 변경
		break;

	default:
		break;
	}
}

void deleteMusic()
{
	music *pTemp = findMusic();
	// 예외처리
	if (pTemp == nullptr)
	{
		printf("삭제하려는 음악이 없습니다.\n");
		return;
	}
	// key 값을 지운곳부터 -1 씩 시킴
	for (music *pTemp2 = pTemp; pTemp2 != nullptr; pTemp2 = pTemp2->getNext())
	{
		pTemp2->setKey(pTemp2->getKey() - 1);
	}

	// 머리 꼬리 연결
	pTemp->getPrev()->setNext(pTemp->getNext());
	pTemp->getNext()->setPrev(pTemp->getPrev());

	// 지운 배열 초기화..?
	pTemp->setTitle("");
	pTemp->setMusician("");
	pTemp->setKey(NULL);
	pTemp->setNext(nullptr);
	pTemp->setPrev(nullptr);

}

void turnChangeMusic()
{
	int select = NULL, target = NULL;
	printf("음악 선택\n");
	fflush(stdin);
	scanf("%d", &select);					// 번호 입력받기
	printf("바꿀 음악 선택\n");
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
		//strcmp는 앞인자와 뒤인자를 비교하여 >0 일경우 앞 > 뒤 , ==0 일경우 앞 == 뒤 , <0 일경우 앞 < 뒤  
		if (strcmp(pTemp->getTitle(), s_title) == 0)
		{
			return pTemp;
		}
	}
	return nullptr;
}

void inTitle()
{
	printf("제목 : ");
	fflush(stdin);
	scanf("%s", s_title);
}

void inMusician()
{
	printf("음악가 : ");
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