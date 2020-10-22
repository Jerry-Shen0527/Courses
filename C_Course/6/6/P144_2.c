//#include<stdio.h>
//
////教材上的要求并不合理，在此用比较简洁的方法来完成
//
//int max_divider(int a, int b)
//{
//	while (a != 0)
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//		a = a % b;
//	}
//	return b;
//}
//
//int min_mul(int a, int b)
//{
//	return a * b / max_divider(a, b);
//}
//
//int main()
//{
//	int x, y;
//	scanf_s("%d%d", &x, &y);
//
//	printf("%d\n", max_divider(x, y));
//	printf("%d\n", min_mul(x, y));
//
//}