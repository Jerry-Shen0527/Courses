//#include<stdio.h>
//#include<math.h>
//
//#define EPSILON 1e-9
//
//int main()
//{
//	double a, b, c;
//	printf("Enter a,b,c:");
//	scanf_s("%lf%lf%lf", &a, &b, &c);
//
//
//	if ((a + b > c) && (b + c > a) && (c + a > b))
//	{
//		if (fabs(a - b) < EPSILON || fabs(b - c) < EPSILON || fabs(c - a) < EPSILON)
//		{
//			if (fabs(a - b) < EPSILON&&fabs(b - c) < EPSILON&&fabs(c - a) < EPSILON)
//			{
//				printf("�ȱ������Σ�\n");
//			}
//			else
//			{
//				printf("���������Σ�\n");
//			}
//		}
//
//		if (fabs(a*a + b * b - c * c) < EPSILON || fabs(a*a - b * b - c * c) < EPSILON || fabs(-a * a + b * b - c * c) < EPSILON)
//		{
//			printf("ֱ�������Σ�\n");
//		}
//		double p = (a + b + c) / 2;
//		printf("The area of the triangle is %4f\n", sqrt(p*(p - a)*(p - b)*(p - c)));
//		getchar();
//		system("pause");
//		return 0;
//	}
//	else
//	{
//		printf("����������!\n");
//		getchar();
//		system("pause");
//		return 1;
//	}
//
//	getchar();
//	getchar();
//}