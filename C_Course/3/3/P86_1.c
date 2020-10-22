//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	double a, b, c, twoa, term1, term2, disc;
//	printf("Enter a,b,c:");
//	scanf_s("%lf%lf%lf", &a, &b, &c);
//	if (a==0)
//	{
//		if (0==b)
//		{
//			printf("No answer!\n");
//		}
//		else
//		{
//			printf("The single root is %f\n", -c / b);
//		}
//	}
//	else
//	{
//		disc = b * b - 4 * a*c;
//		twoa = 2 * a;
//		term1 = -b / twoa;
//		term2 = sqrt(fabs(disc)) / twoa;
//		if (disc<0)
//		{
//			printf("complex roots/n real part= %f imag part=%f\n", term1, term2);
//		}
//		else
//		{
//			double temp;
//			temp = a > 0 ? term1 + term2 : term1 - term2;
//
//			printf("real roots/n The bigger one is %f, The smaller one is %f\n", temp, c / (a*temp));
//		}
//	}
//	getchar();
//	getchar();
//}