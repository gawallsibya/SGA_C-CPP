/*
���� ]]

#include <conio.h>
kbhit() , getch()

���ѷ���...
{
A, a �Է� -> "Attack~~~!"
S, s �Է� -> "Stop~~~~!"

Q, q �Է� -> ""
1 �Է�

x Ű �Է� -> ���α׷� ����
��Ÿ �Է� -> �߸��� Ű �Է�
}
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	// ����������
	// ��ų ����Ű	:  ����(q) ���� (w) �� (e)
	// ������ ����Ű	:  HPȸ��(1) ������(2)

	// ��ǻ���� ���� - ������ �ȹ������ ������ô ����
	// q w e�� �ƽ�Ű�ڵ尪 * 3 �� �� �� %3 �� �ؼ� 0 �̸� ���� 1�̸� ���� 2 �̸� ��

	char cKey = 0;			// ����� �Է¹޴´�
	char cOldKey = 0;		// �߸��� �Է��� �޾������� ����� ����
	int nMaxHp = 10;		// HP�� �⺻ 10
	int nNowHp = nMaxHp;	// ���� HP�� MAXHP
	int nAI = 0;			// ��ǻ���� ���������� ����
	int nTurn = 0;			// �� �� - ���� ���鶧 �ø���
	int nRand = 0;			// �������� ���ڸ� ���� ����
	int nCombo = 0;			// ���� �Ҷ����� ������ ����
	int nOldCombo = 0;
	int nItemCount = 0;		// ������ ����
	int nResult = 0;		// ������� ������ ó��  0 : ó�� , 1 : �¸� , 2 : �й� , 3 : ���º� , 4 : ������ ��� , 5 : ������ ȹ�� , 9 : ����
	int nWinCount = 0;		// �¸��� Ƚ�� ���
	bool bSencer = false;	// �߸��� ���� �ԷµǸ� true�� �ǿ� ���ó���� �����ʴ´� -> �ؽ�Ʈ �� ������ �����ȴ�
		
	// ��¼��� : ����ó��(ó������ ����) -> ȭ����� -> Ű �Է� -> ����ó�� -> ȭ����� -> �ݺ�..
	// ������ �Է� �� ȭ�� ��ȭ�� �ٷ� ��Ÿ�����ٰ�..

	while (true)
	{
		// ������ �⺻������ �ʱ�ȭ���ش�. 
		bSencer = false;
		if (cKey != 0)
		{
			// ��ҹ��� ���� �� ���ܽ� ����� Ű���� ��������
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

			// �ҷ�Ű
			if (bSencer == false)
			{
				if (cOldKey != 0)
				{
					// ���� ������ �ȹ������ ���ڸ� ��� ���ƺ���
					nRand = (cKey * 13) + (nTurn * 11);
					while (nRand > 1000)
					{
						nRand >>= 2;
					}
					// 0 ~ 2 �̱�
					nAI = nRand % 3;


					// ���� ���� �κ�
					// �¸�
					//			����		   	  ��				 ����		  ����			   ��			����	
					if ((cKey == 'q' && nAI == 2) || (cKey == 'w' && nAI == 0) || (cKey == 'e' && nAI == 1))
					{
						nCombo += 1;
						nWinCount += 1;

						nResult = 1;
					}

					// �й�
					//				 ����		  ����			  ����			��				��		    ����
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
					// ���º�
					//				 ����		  ����			  ����		   ����				��		      ��
					else if ((cKey == 'q' && nAI == 0) || (cKey == 'w' && nAI == 1) || (cKey == 'e' && nAI == 2))
					{
						nResult = 3;
					}
					// HPȸ�� ������ ���
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
		// ��� ���� 
		printf("********** ���� ���� ��! **********\n");
		printf("* ���� Ű                         *          ");
		printf("�� �� ��\n");
		printf("* ���� : q                        *          ");
		printf(" HPȸ�� : %d\n", nItemCount);
		printf("* ���� : w                        *\n");
		printf("*   �� : e                        *          ");
		printf("��   �� : %d\n", nWinCount);
		printf("*                                 *\n");
		printf("* ������ ����Ű                   *\n");
		printf("* HPȸ�� : 1                      *          ");
		// HP ǥ�� �� ��� ����ü�¢� , ����ü�¢�
		printf("HP ( %d/%d )\n", nNowHp, nMaxHp);
		printf("***********************************          ");
		for (int i = 0; i <= nMaxHp - 1; i++)
		{
			(nNowHp > 0) && (i < nNowHp) ? printf("��") : printf("��");
		}
		printf("\n\n");

		printf("���� : q     ���� : w     �� : e\n\n");
		printf("<< Player >>     << Computer >>\n");

		if (cKey != 0)
		{
			switch (cKey)
			{
				// ����
			case 'q':
				printf("     ����!     :     ");

				// AI ����
				if (nAI == 0) { printf("����!\n"); }
				// AI ����
				if (nAI == 1) { printf("����!\n"); }
				// AI ��
				if (nAI == 2) { printf("  ��!\n"); }
				break;

				// ����
			case 'w':
				printf("     ����!     :     ");

				// AI ����
				if (nAI == 0) { printf("����!\n"); }
				// AI ����
				if (nAI == 1) { printf("����!\n"); }
				// AI ��
				if (nAI == 2) { printf("  ��!\n"); }
				break;

				// ��
			case 'e':
				printf("       ��!     :     ");

				// AI ����
				if (nAI == 0) { printf("����!\n"); }
				// AI ����
				if (nAI == 1) { printf("����!\n"); }
				// AI ��
				if (nAI == 2) { printf("  ��!\n"); }
				break;

				// ����ó�� - ������ Ű �ܿ� �Է¹��� Ű�� �н�
			default:
				break;
			}

			switch (nResult)
			{
				// ó��
			case 0:
				break;
				// �¸� ���
			case 1:
				printf("\n\n                      < < < < < < ��    �� > > > > > >\n");
				break;

				// �й� ���
			case 2:
				printf("\n\n                      < < < < < < ��    �� > > > > > >\n");
				break;

				// ���º� ���
			case 3:
				printf("\n\n                      < < < < < < �� �� �� > > > > > >\n");
				break;

				// ������ ��� ���
			case 4:
				printf("\n\n\n                      * * * * * * HP ȸ�� * * * * * *\n");
				break;

				// ������ ȹ�� ���
			case 5:
				printf("\n\n                      < < < < < < ��    �� > > > > > >\n");
				printf("\n\n                    + + + + + + ������ ȹ��! + + + + + +\n");
				break;

				// ���ӿ���
			case 6:
				printf("\n\n                      < < < < < < ��    �� > > > > > >\n");
				printf("\n\n                          ------ GAME OVER ------\n\n");
				printf("�� ���� �Ͻðڽ��ϱ�? ( Y / N )\n\n");
				break;

				// ����ó�� - ������ ��� �ܿ��� �н�
			default:
				break;
			}
		}

		// ��ǻ� ������� �����Ѵٰ� ���� ��
		do
		{
			cKey = getch();

			// ���� ������������ ȭ�� Ŭ���� ���ϰ� �����ų� �ٽ� �����ϰ�; �̷���..
			// �� ������ ��� ���� �ʱ�ȭ
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
				// �絵�� ���ҰŸ� renTurn.. �Ϸ��ٰ� exit(0) �� ����ϱ��
				else if (cKey == 'n' || cKey == 'N')
				{
					exit(0);
				}
				else
				{
					// ..�̰��� �������ϳ�.. ?..���� �ؾ��ϳ�..?
				}
			}
		} while (nResult == 6);

		system("cls");

		nTurn += 1;
	}
}