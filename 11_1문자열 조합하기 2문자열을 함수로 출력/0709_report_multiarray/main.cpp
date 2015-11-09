/*
문자열 조합하기

str1 누가 = "홍길동" " 고길동" " 어우동"
str2 무엇을 해서 = " "
str3 어떻게 됐다 = " 잘 됐다" "부자가 됬다"

랜덤하게 조합하기.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show(char str[20]);

void main()
{
	// 음.. 그냥 출력할때 마다 0~4를 랜덤으로 다시 받으면서 다음거 출력 반복하면 끝..
	// 헷갈리지 않게 5개라고 만들어줌
	char str1[5][20] = { "노트북이", "여친이", "거울에 보인 사람이", "귀신이", "중학생이" };
	char str2[5][20] = { "번개를 맞아서", "번지점프를 해서", "차원의 문을 열어서", "지박령이 되어서", "중2병이 돋아서" };
	char str3[5][20] = { "폭발했다.", "각성했다.", "진화! 하였다.", "백수가 되었다.", "결계를 펼쳤다." };

	srand(time(NULL));

	while (true)
	{
		int num = rand()%5;
		show(str1[num]);

		num = rand() % 5;
		show(str2[num]);

		num = rand() % 5;
		show(str3[num]);

		printf("\n");
		system("pause");
		system("cls");
	}
}

void show(char str[20])
{
	printf("%s ", str);
}