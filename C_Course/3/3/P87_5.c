#include<stdio.h>
#include<math.h>

char f(int x);

int main()
{
	int x;
	while (scanf_s("%d", &x))
		printf("%c\n", f(x));

	getchar();
	getchar();
}

char f(int x)
{
	if (x < 0)
	{
		printf("This is not a proper score!\n");
		return 0;
	}
	if (x==100)
	{
		return 'A';
	}
	switch (x / 10)
	{
	case 9:
		return 'A';
	case 8:
		return 'B';
	case 7:
		return 'C';
	case	 6:
		return 'D';
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		return 'E';
	default:
		printf("This is not a proper score!\n");
		return 0;
		break;
	}
}