#include<stdio.h>
#include<stdlib.h>

#define N 100

#define swap(a,b) {int temp=a;a=b;b=temp;}

int mat[4][4];

void transpose(int (*p)[4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			swap(p[i][j], p[j][i]);
		}

	}
}

int main()
{
	for (int i = 0; i < 16; i++)
	{
		scanf_s("%d", (*mat) + i);
	}

	transpose(mat);

	for (int i = 0; i < 16; i++)
	{
		printf("%4d", (*mat)[i]);
		if (i % 4 == 3)
		{
			printf("\n");
		}
	}

	system("pause");
}