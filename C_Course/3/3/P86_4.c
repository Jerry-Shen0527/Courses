//#include<stdio.h>
//#include<math.h>
//
//#define EPSILON 1e-9
//
//int equal(double x, double y)
//{
//	return fabs(x- y) < EPSILON;
//}
//
//double f(double x);
//
//int main()
//{
//
//	double x;
//	while(scanf_s("%lf", &x))
//		printf("x=%f,f(x)=%lf\n", x, f(x));
//
//	getchar();
//	getchar();
//}
//
//double f(double x)
//{
//	if (x < 0 && !equal(x, -3))
//	{
//		return x * x + x - 6;
//	}
//	else if (x >= 0 && x < 10 && !equal(x, 2) && !equal(x, 3))
//	{
//		return x * x - 5 * x + 6;
//	}
//	else
//	{
//		return x * x - x - 1;
//	}
//}