#include<stdio.h>
#include<math.h>
#include<Windows.h>


int main()
{
	double a = 0, b = 0, c = 0;
	printf("Please put in the length of a triangle\n");
	scanf_s("%lf%lf%lf", &a, &b, &c);
		
	if ((a + b > c) &&( b + c > a) &&( c + a > b))
	{
		double p = (a + b + c) / 2;
		printf("The area of the triangle is %4f\n", sqrt(p*(p - a)*(p - b)*(p - c)));
		getchar();
		system("pause");
		return 0;
	}
	else
	{
		printf("This is not a triangle!\n");
		getchar();
		system("pause");
		return 1;
	}
}
