#include <stdio.h>

void IncreaseArray(int array[], int IncArray[], int nCount);
void ShowArray(int array[], int nCount);

void main()
{
	int array[4] = { 3, 4, 1, 7 };
	int IncArray[4] = {};

	int nCount = sizeof(array) / sizeof(int);


	IncreaseArray(array, IncArray, nCount);
	ShowArray(IncArray, nCount);
}


void IncreaseArray(int array[], int IncArray[], int nCount)
{
	// 0 번의 배열이랑  0 1 2 3 의 배열이랑 비교
	// 0번보다 작으면 변수 하나 만든거에다가 0번을 옮겨담고 비교한 배열을 0번에 대입
	// 담은 변수는 비교한 배열 자리에 대입해서 옮긴다.
	int temp = 0;

	for (int f = 0; f < nCount; f++)
	{
		for (int l = 0; l < nCount; l++)
		{
			if (array[f] < array[l])
			{
				temp = array[f];
				array[f] = array[l];
				array[l] = temp;
			}
		}
	}

	for (int i = 0; i < nCount; i++)
	{
		IncArray[i] = array[i];
	}

}

void ShowArray(int array[], int nCount)
{
	for (int i = 0; i < nCount; i++)
	{
		printf("result[%d] = %d\n", i, array[i]);
	}
}