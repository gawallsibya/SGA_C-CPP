/*
과제 ]] 월드컵 우승... 인정할 수 없다..

1라운드 [] [] [] []   [] [] [] []		// 8개	char *pQuaterFinal[8] = ???
2라운드   []   []	   []    []			// 4개	char *pSemiFinal[4] = ???
3라운드     []             []			// 2개	char *pFinal[2] = ???
4라운드            []					// 1개	char *pWinner = ???
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main()
{
	// 배열을 포인터에 할당하는거로
	char *pQuaterFinal[8] = {};		// 8강
	char *pSemiFinal[4] = {};		// 4강
	char *pFinal[2] = {};			// 2강
	char *pWinner = 0;				// 우승

	char pNation[8][20] = {};		// 출전 나라들 8국가
	int nRandom = 0;				//	0 or 1 1/2확률

	srand(time(NULL));

	while (true)
	{
		// 여덟 나라 입력받기
		for (int i = 0; i < 8; i++)
		{
			fflush(stdin);
			printf("%d. ", i+1);
			scanf("%s", pNation[i]);
			// 입력받은 나라를 8강에 담아준다
			pQuaterFinal[i] = pNation[i];
		}
		getch();

		// 8강
		// 12 34 56 78 팀으로 붙여서 둘중 하나만 올린다.
		// i, j 두개 선언해서 i+=1, j+=2 로 매 루프마다 올려준다
		printf("\n4강 진출 : ");
		for (int i = 0, j = 0; i < 4; i+=1, j+=2)
		{
			nRandom = rand() % 2;
			// 0이면 전자, 1이면 후자가 진출
			nRandom == 0 ? pSemiFinal[i] = pQuaterFinal[j] : pSemiFinal[i] = pQuaterFinal[j + 1];

			printf("%s ", pSemiFinal[i]);
		}
		printf("\n");
		getch();

		// 4강
		//  8강과 같은방식
		printf("\n결승 진출 : ");
		for (int i = 0, j = 0; i < 2; i += 1, j += 2)
		{
			nRandom = rand() % 2;
			// 0이면 전자, 1이면 후자가 진출
			nRandom == 0 ? pFinal[i] = pSemiFinal[j] : pFinal[i] = pSemiFinal[j + 1];

			printf("%s ", pFinal[i]);
		}
		printf("\n");
		getch();

		// 2강
		// 반복할 필요없으니 그냥 처리
		nRandom = rand() % 2;
		nRandom == 0 ? pWinner = pFinal[0] : pWinner = pFinal[1];
		
		// 우승
		printf("\n우승 : %s\n\n", pWinner);

		system("pause");
		system("cls");

	}
}