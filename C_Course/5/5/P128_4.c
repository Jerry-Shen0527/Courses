//#include<stdio.h>
//#include<stdlib.h>
//
//#define N 20
//
//int a[N] = { INT_MAX };
//int b[10] = { INT_MAX };
//
//void insert(int num, int *arr, int index)
//{
//	if (index >= N)
//	{
//		printf("Index is out of bound!\n");
//		return;
//	}
//
//	for (int i = N - 1; i > index; i--)
//	{
//		arr[i] = arr[i - 1];
//	}
//	arr[index] = num;
//
//
//}
//
//void insert_seq(int num, int *arr)
//{
//	int index = 0;
//	while (arr[index] < num)index++;
//
//	insert(num, arr, index);
//	
//}
//
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		insert_seq(rand(), a);
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//
//	printf("After inserting:\n");
//
//	for (int i = 0; i < 10; i++)
//	{
//		b[i] = rand();
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		insert_seq(b[i], a);
//	}
//
//	for (int i = 0; i < 20; i++)
//	{
//		printf("a[%d]=%d\n", i, a[i]);
//	}
//	getchar();
//}