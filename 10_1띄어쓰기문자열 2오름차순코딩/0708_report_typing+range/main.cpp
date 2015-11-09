/*

한글자씩 타이핑해서 틀린부분의 개수 세기.

예)
주어진 문장	] a rolling stone gathers no moss
타이핑		] a r_ll_ng s_one gathers no moss

기본	 ] 몇 글자가 틀렸습니다. :: ___

확장 ] 타이핑 완료까지 걸린시간 :: ___

참고 >> 띄어쓰기 포함한 문자열 입력
scanf("%[^\n]", string);

확장2 ] 틀린 부분 지적

*/


#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	char strA[] = "a rolling stone gathers no moss";	// 예시 문장
	char strB[255] = {};								// 입력 문장
	char strC[255] = {};								// 틀린 위치
	int nCount = 0;										// 오타 갯수
	int nLength = sizeof(strA) / sizeof(char);			// strA 의 배열 길이
	clock_t tTime = 0;									// 시작 시간
	char cSwitch = 0;									// enter or esc를 받을 변수
	float fResTime = 0;									// 걸린 시간

	while (cSwitch != 27)
	{
		nCount = 0;

		printf("시작하려면 enter, 종료하려면 esc\n");

		cSwitch = getch();

		if (cSwitch == 13)
		{
			tTime = clock();

			printf("주어진 문장	] ");
			printf("%s\n", strA);

			printf("타이핑		] ");
			fflush(stdin);
			scanf("%[^\n]", strB);

			// 종료시간과 시작시간을 뺀 후 1000으로 나눔 -> clock은 1초가 1000이기 때문에
			fResTime = (float)(clock() - tTime) / CLK_TCK;	// CLK_TCㅏ == 1000

			// 주어진 문장과 타이핑 결과의 배열을 비교 주어진문장의 길이만큼 돌면서 비교
			// strC 에 맞은위치는 ' '로 넘기고 틀린 위치에 '^' 를 넣어 표시
			// \0 이 되어 끝나도 ' '를 넣지 않게 조건을 추가
			for (int i = 0; i < nLength; i++)
			{
				if (strA[i] != strB[i] && strA[i] != '\0')
				{
					nCount += 1;
					strC[i] = '^';
				}
				else if (strA[i] == strB[i] && strA[i] != '\0')
				{
					strC[i] = ' ';
				}
			}
			printf("틀린 부분   	] %s\n\n", strC);
			printf("오타 횟수 ::%d\n\n", nCount);
			printf("타이핑 완료까지 걸린시간 :: %.2f 초\n\n", fResTime);

			system("pause");
			system("cls");
		}
		else
		{
			system("cls");
		}

	}
}