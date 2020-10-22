//#include<stdio.h>
//#include<stdlib.h>
//
//void insertsort(int r[], int i, int x)
//{
//	while (i != 0 && r[i - 1] > x)
//	{
//		r[i] = r[i - 1];
//		i--;
//	}
//	r[i] = x;
//}
//
//int num[50];
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//
//	for (int i = 0; i < 50; i++)
//	{
//		num[i] = rand();
//	}
//
//	for (int i = 0; i < 50; i++)
//	{
//		insertsort(num, i, num[i]);
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%5d ", num[5 * i + j]);
//		}
//		printf("\n");
//	}
//
//	getchar();
//	getchar();
//
//}