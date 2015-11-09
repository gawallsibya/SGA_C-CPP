/*
과제 ]]

#include <conio.h>
kbhit() , getch()

무한루프...
{
A, a 입력 -> "Attack~~~!"
S, s 입력 -> "Stop~~~~!"

Q, q 입력 -> ""
1 입력

x 키 입력 -> 프로그램 종료
기타 입력 -> 잘못된 키 입력
}
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	// 가위바위보
	// 스킬 단축키	:  가위(q) 바위 (w) 보 (e)
	// 아이템 단축키	:  HP회복(1) 무르기(2)

	// 컴퓨터의 패턴 - 랜덤을 안배웠으니 랜덤인척 하자
	// q w e의 아스키코드값 * 3 의 값 중 %3 을 해서 0 이면 가위 1이면 바위 2 이면 보

	char cKey = 0;			// 명령을 입력받는다
	char cOldKey = 0;		// 잘못된 입력을 받았을때의 백업용 변수
	int nMaxHp = 10;		// HP는 기본 10
	int nNowHp = nMaxHp;	// 현재 HP는 MAXHP
	int nAI = 0;			// 컴퓨터의 가위바위보 정보
	int nTurn = 0;			// 턴 수 - 패턴 만들때 올리자
	int nRand = 0;			// 랜덤돌릴 숫자를 담을 변수
	int nCombo = 0;			// 연승 할때마다 아이템 지급
	int nOldCombo = 0;
	int nItemCount = 0;		// 아이템 갯수
	int nResult = 0;		// 결과값을 가지고 처리  0 : 처음 , 1 : 승리 , 2 : 패배 , 3 : 무승부 , 4 : 아이템 사용 , 5 : 아이템 획득 , 9 : 예외
	int nWinCount = 0;		// 승리한 횟수 기록
	bool bSencer = false;	// 잘못된 값을 입력되면 true가 되여 결과처리를 하지않는다 -> 텍스트 및 정보가 보존된다
		
	// 출력순서 : 상태처리(처음에는 생략) -> 화면출력 -> 키 입력 -> 상태처리 -> 화면출력 -> 반복..
	// 이유는 입력 후 화면 변화를 바로 나타내려다가..

	while (true)
	{
		// 센서를 기본값으로 초기화해준다. 
		bSencer = false;
		if (cKey != 0)
		{
			// 대소문자 통일 및 예외시 백업된 키값을 돌려받음
			switch (cKey)
			{
			case 'q':
			case 'Q':
				cOldKey = cKey = 'q';
				break;

			case 'w':
			case 'W':
				cOldKey = cKey = 'w';
				break;

			case 'e':
			case 'E':
				cOldKey = cKey = 'e';
				break;

			case '1':
				cOldKey = cKey;
				break;

			default:
				cKey = cOldKey;
				bSencer = true;
				break;
			}

			// 불량키
			if (bSencer == false)
			{
				if (cOldKey != 0)
				{
					// 아직 랜덤을 안배웠으니 숫자를 섞어서 꼬아보자
					nRand = (cKey * 13) + (nTurn * 11);
					while (nRand > 1000)
					{
						nRand >>= 2;
					}
					// 0 ~ 2 뽑기
					nAI = nRand % 3;


					// 정보 변경 부분
					// 승리
					//			가위		   	  보				 바위		  가위			   보			바위	
					if ((cKey == 'q' && nAI == 2) || (cKey == 'w' && nAI == 0) || (cKey == 'e' && nAI == 1))
					{
						nCombo += 1;
						nWinCount += 1;

						nResult = 1;
					}

					// 패배
					//				 가위		  바위			  바위			보				보		    가위
					else if ((cKey == 'q' && nAI == 1) || (cKey == 'w' && nAI == 2) || (cKey == 'e' && nAI == 0))
					{
						nNowHp -= 1;

						if (nNowHp > 0)
						{
							nCombo = 0;

							nResult = 2;
						}
						else
						{
							nResult = 6;
						}
					}
					// 무승부
					//				 가위		  가위			  바위		   바위				보		      보
					else if ((cKey == 'q' && nAI == 0) || (cKey == 'w' && nAI == 1) || (cKey == 'e' && nAI == 2))
					{
						nResult = 3;
					}
					// HP회복 아이템 사용
					else if (cKey == '1')
					{
						if (nItemCount > 0 && nNowHp < nMaxHp)
						{
							nNowHp += 1;
							nItemCount -= 1;

							nResult = 4;
						}
					}

					if (nCombo >= 2 && nCombo != nOldCombo)
					{
						nItemCount += 1;
						nOldCombo = nCombo;

						nResult = 5;
					}
				}
			}
		}
		// 사용 설명서 
		printf("********** 가위 바위 보! **********\n");
		printf("* 조작 키                         *          ");
		printf("아 이 템\n");
		printf("* 가위 : q                        *          ");
		printf(" HP회복 : %d\n", nItemCount);
		printf("* 바위 : w                        *\n");
		printf("*   보 : e                        *          ");
		printf("승   리 : %d\n", nWinCount);
		printf("*                                 *\n");
		printf("* 아이템 단축키                   *\n");
		printf("* HP회복 : 1                      *          ");
		// HP 표시 및 출력 현재체력♥ , 잃은체력♡
		printf("HP ( %d/%d )\n", nNowHp, nMaxHp);
		printf("***********************************          ");
		for (int i = 0; i <= nMaxHp - 1; i++)
		{
			(nNowHp > 0) && (i < nNowHp) ? printf("♥") : printf("♡");
		}
		printf("\n\n");

		printf("가위 : q     바위 : w     보 : e\n\n");
		printf("<< Player >>     << Computer >>\n");

		if (cKey != 0)
		{
			switch (cKey)
			{
				// 가위
			case 'q':
				printf("     가위!     :     ");

				// AI 가위
				if (nAI == 0) { printf("가위!\n"); }
				// AI 바위
				if (nAI == 1) { printf("바위!\n"); }
				// AI 보
				if (nAI == 2) { printf("  보!\n"); }
				break;

				// 바위
			case 'w':
				printf("     바위!     :     ");

				// AI 가위
				if (nAI == 0) { printf("가위!\n"); }
				// AI 바위
				if (nAI == 1) { printf("바위!\n"); }
				// AI 보
				if (nAI == 2) { printf("  보!\n"); }
				break;

				// 보
			case 'e':
				printf("       보!     :     ");

				// AI 가위
				if (nAI == 0) { printf("가위!\n"); }
				// AI 바위
				if (nAI == 1) { printf("바위!\n"); }
				// AI 보
				if (nAI == 2) { printf("  보!\n"); }
				break;

				// 예외처리 - 지정된 키 외에 입력받은 키는 패스
			default:
				break;
			}

			switch (nResult)
			{
				// 처음
			case 0:
				break;
				// 승리 결과
			case 1:
				printf("\n\n                      < < < < < < 승    리 > > > > > >\n");
				break;

				// 패배 결과
			case 2:
				printf("\n\n                      < < < < < < 패    배 > > > > > >\n");
				break;

				// 무승부 결과
			case 3:
				printf("\n\n                      < < < < < < 무 승 부 > > > > > >\n");
				break;

				// 아이템 사용 결과
			case 4:
				printf("\n\n\n                      * * * * * * HP 회복 * * * * * *\n");
				break;

				// 아이템 획득 결과
			case 5:
				printf("\n\n                      < < < < < < 승    리 > > > > > >\n");
				printf("\n\n                    + + + + + + 아이템 획득! + + + + + +\n");
				break;

				// 게임오버
			case 6:
				printf("\n\n                      < < < < < < 패    배 > > > > > >\n");
				printf("\n\n                          ------ GAME OVER ------\n\n");
				printf("재 도전 하시겠습니까? ( Y / N )\n\n");
				break;

				// 예외처리 - 지정된 결과 외에는 패스
			default:
				break;
			}
		}

		// 사실상 여기부터 시작한다고 봐도 됨
		do
		{
			cKey = getch();

			// 게임 오버했을때는 화면 클리어 안하고 끝내거나 다시 시작하고싶어서 이렇게..
			// 재 도전시 모든 정보 초기화
			if (nResult == 6)
			{
				if (cKey == 'y' || cKey == 'Y')
				{
					cKey = 0;
					nMaxHp = 10;
					nNowHp = nMaxHp;
					nAI = 0;
					nTurn = 0;
					nRand = 0;
					nCombo = 0;
					nItemCount = 0;
					nResult = 0;
					nWinCount = 0;
				}
				// 재도전 안할거면 renTurn.. 하려다가 exit(0) 을 사용하기로
				else if (cKey == 'n' || cKey == 'N')
				{
					exit(0);
				}
				else
				{
					// ..이곳을 만들어야하나.. ?..뭔가 해야하나..?
				}
			}
		} while (nResult == 6);

		system("cls");

		nTurn += 1;
	}
}