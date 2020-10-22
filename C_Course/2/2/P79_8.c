#include<stdio.h>
#include<Windows.h>
#include<math.h>

const double PI = 3.1415926535;

int main()
{

	double r, h;

	printf("Put in the radius and the height of the cone:\n");
	scanf_s("%lf%lf", &r, &h);

	double l = sqrt(r*r + h * h);

	double C = 2 * PI*r;
	double S_b = PI * r*r;
	double S_s = PI * r*l;
	double V = 1.0 / 3 * S_b*h;

	printf("C=%.2f,S_bottom=%.2f,S_side=%.2f,Volume=%.2f\n",C,S_b,S_s,V);



	system("pause");
	return 0;
}