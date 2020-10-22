//#include<stdio.h>
//#include<math.h>
//
//#define ERROR 1E-8
//
//
//
//double my_sin(double x)
//{	
//	double temp = x;
//
//	double result = x;
//
//	double i = 1;
//
//	while (fabs(temp) > ERROR)
//	{
//		temp *= -(x * x);
//		i++;
//		temp /= i;
//		i++;
//		temp /= i;
//		result += temp;
//	}
//
//	return result;
//}
//
//int main()
//{
//	double temp = 0;
//
//	double x = 0;
//	printf("Put in x:\n");
//	while (scanf_s("%lf", &x))
//	{
//		printf("sin(x)=%.9g\n", my_sin(x));
//		printf("The error is %.9g\n", my_sin(x) - sin(x));
//	}
//	getchar(); getchar();
//}