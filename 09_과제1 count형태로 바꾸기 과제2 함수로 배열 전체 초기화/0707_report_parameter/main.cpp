#include <stdio.h>

// 3 함수 선언
void show(int nums[], int nCount);
void addArray(int *nums, int nCount, int nAddnum);

void main()
{
	int nums[] = { 7, 8, 4, 5, 6 };

	int nCount = sizeof(nums) / sizeof(int);

	// 1 함수의 필요성
	show(nums, nCount);

	addArray(nums, nCount , 3);
}

// 2 함수 디자인 ( 정의 )
void show(int nums[], int nCount)
{
	// 과제1 ] 5-> count 형태로 바꾸기
	for (int i = 0; i < nCount; i++)
	{
		printf("nums[%d] = %d\n", i, nums[i]);
	}
}

void addArray(int nums[], int nCount, int nAddNum)
{
	for (int i = 0; i < nCount; i++)
	{
		printf("Old nums[i] = %d + %d  ->  ", nums[i], nAddNum);
		nums[i] += nAddNum;
		printf("New nums[i] = %d\n", nums[i]);
	}
}

/*
과제2 ] addArray( 배열, 3 );
*/