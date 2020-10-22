//#include<stdio.h>
//
//double poly(double x, int n)
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (n == 1)
//	{
//		return x;
//	}
//	else
//	{
//		return ((2 * n - 1)*x *poly(x, n - 1) - (n - 1)*poly(x, n - 2) )/ n;
//	}
//}
//
//int main()
//{
//	printf("%lf",poly(4, 3));
//}