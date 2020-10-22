#include<math.h>

#include<stdio.h>
#include<stdlib.h>

#define DIVIDE 1000000


double integrate(double func(double), double inf_bound, double sup_bound)
{
	double result = 0;
	double part = (sup_bound - inf_bound) / DIVIDE;

	for (int i = 0; i < DIVIDE; i++)
	{
		result += func(inf_bound + i * part)*part;
	}
	return result;
}

int main()
{
	printf("%lf", integrate(exp, 0, 2));
	system("pause");
}