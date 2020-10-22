//#include<stdio.h>
//
//int max_divider(int i,int j)
//{
//	int r = i;
//	while (j%r != 0)
//	{
//		j = j % r;
//		r = r % j;
//		if (0==r)
//		{
//			return j;
//		}
//	}
//	return r;
//}
//
//int min_mul(int i, int j)
//{
//	return i * j / max_divider(i, j);
//}
//
//int main()
//{
//	int a, b;
//
//
//	printf("Put in 2 numbers:\n");
//	while (scanf_s("%d%d", &a, &b))
//	{
//		printf("The max divider is %d\n", max_divider(a, b));
//		printf("The min multiple is %d\n", min_mul(a, b));
//		printf("Put in 2 numbers:\n");
//	}
//
//
//
//
//	getchar(); getchar();
//}