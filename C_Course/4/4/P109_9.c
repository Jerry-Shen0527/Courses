#include<stdio.h>
#include<math.h>

#define N 500

int max[N+1];//在堆上创建初始化为0

void sieve(int *arr)
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < sqrt(N)+1; i++)//上限只要小于Sqrt[N]就可以
	{
		if (0 == arr[i])
		{
			for (int j = 2; i*j < N+1; j++)
			{
				arr[i*j] = 1;
			}
		}
	}
}

int main()
{

	sieve(max);

	int counter = 10;


	int result = 0;
	for (int i = N; counter&& i > 0  ; i--)
	{
		if (max[i] == 0)
		{
			printf("%d\n", i);
			result += i;
			counter--;
		}
	}

	printf("The sum is %d\n", result);

	if (counter)
	{
		printf("There are not 10 primes in within %d!\n",N);
	}


	getchar();
}