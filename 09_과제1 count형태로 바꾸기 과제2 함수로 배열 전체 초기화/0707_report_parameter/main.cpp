#include <stdio.h>

// 3 �Լ� ����
void show(int nums[], int nCount);
void addArray(int *nums, int nCount, int nAddnum);

void main()
{
	int nums[] = { 7, 8, 4, 5, 6 };

	int nCount = sizeof(nums) / sizeof(int);

	// 1 �Լ��� �ʿ伺
	show(nums, nCount);

	addArray(nums, nCount , 3);
}

// 2 �Լ� ������ ( ���� )
void show(int nums[], int nCount)
{
	// ����1 ] 5-> count ���·� �ٲٱ�
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
����2 ] addArray( �迭, 3 );
*/