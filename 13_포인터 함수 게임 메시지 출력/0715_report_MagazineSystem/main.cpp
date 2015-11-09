/*
과제 ]]
탄창 시스템.. (Magazine System)
1. rifle	30
2. pistol	7
3. knife	infinite
4. grenade	2

r. reload

발사 버튼.. SPACEBAR

현재 선택한 무기의 총알이 소모

함수 포인터 활용
tip ] 탄알 은 static or 배열 활용
*/

// ..함수포인터 억지로 쓰려고하고 이래저래 지저분하게 되다보니 주석 달 여유가 ㅈㅈ

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void uiText();
void fire(char **pWeapon());
void reload(char **pWeapon());
void setWeapon(char **ppWeapon());
void keySave();
void keyLoad();

// 이것들 내부 보면 내부 변수가 static으로 되어있어 데이터가 보존된다.
char **rifle();			// max 30
char **pistol();		// max 7
char **knife();			// max NULL
char **grenade();		// max 2

static char key = NULL;
static char oldkey = key;
static char** (*pfWeapon)();
static bool bReload = false;
static bool bFire = false;
static int effectCount = 0;

void main()
{

	pfWeapon = rifle;	

	while (true)
	{
		switch (key)
		{
		case '1':
			setWeapon(rifle);
			break;

		case '2':
			setWeapon(pistol);
			break;

		case '3':
			setWeapon(knife);
			break;

		case '4':
			setWeapon(grenade);
			break;

		case ' ':
			fire(pfWeapon);

			oldkey = key;
			break;

		case 'r':
		case 'R':
			oldkey = key;
			reload(pfWeapon);
			break;

		case NULL:
			break;

		default:
			keyLoad();
			continue;
		}

		if (pfWeapon()[0] != 0)
		{
			bReload = false;
		}

		uiText();


		fflush(stdin);
		key = getch();

		system("cls");
	}
}

// [0] : 현재 탄알 갯수 , [1] : 최대 탄알 갯수, [2] 무기 이름, [3] 효과음
char **rifle()
{
	static char *rifleInfo[10] = { { (char*)30 }, { (char*)30 }, { "rifle" }, { "다!" } };
	return rifleInfo;
}

char **pistol()
{
	static char *pistolInfo[10] = { { (char*)7 }, { (char*)7 }, { "pistol" }, { "탕!" } };
	return pistolInfo;
}

char ** knife()
{
	static char *knifeInfo[10] = { { "infinite" }, { "infinite" }, { "knife" }, { "휙!" } };
	return knifeInfo;
}

char **grenade()
{
	static char *grenadeInfo[10] = { { (char*)2 }, { (char*)2 }, { "grenade" }, { "콰앙!" } };
	return grenadeInfo;
}

void uiText()
{
	printf("무기를 선택해 주세요.\n");
	printf("1. rifle  2. pistol  3. knife  4. grenade\n\n\n");
	printf("%s(을)를 장착 하였습니다!\n\n", pfWeapon()[2]);
	printf("                %s\n", pfWeapon()[2]);

	if (pfWeapon()[1] != "infinite")
	{
		printf("                             %d / %d\n\n", pfWeapon()[0], pfWeapon()[1]);
	}
	else
	{
		printf("                             %s / %s\n\n\n", pfWeapon()[0], pfWeapon()[1]);
	}

	if (bReload == true)
	{
		printf("                              ReLoad!!!!!!!!!!!!!!!!!\n\n");
	}
	else if (bFire == true)
	{
		effectCount += 1;
		printf("                    ");
		for (int i = 0; i < effectCount; i++)
		{
			
			printf("%s ", pfWeapon()[3]);
			if ((i+1) % 10 == 0)
			{
				printf("\n                    ");
			}
		}
		bFire = false;
	}

}

void setWeapon(char **ppWeapon())
{
	pfWeapon = ppWeapon;

	keySave();
	effectCount = 0;
}

void fire(char **pWeapon())
{
	if (pWeapon()[0] > 0 && pWeapon()[1] != "infinite")
	{
		pWeapon()[0] -= 1;
		bFire = true;
	}
	else if (pWeapon()[1] == "infinite")
	{
		bFire = true;
	}
	else
	{
		bReload = true;
	}

}

void reload(char **pWeapon())
{

	pWeapon()[0] = pWeapon()[1];
}


void keySave()
{
	oldkey = key;
}

void keyLoad()
{
	key = oldkey;
}