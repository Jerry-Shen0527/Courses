//#include<stdio.h>
//
////�̲��ϵ�Ҫ�󲢲������ڴ��ñȽϼ��ķ��������
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