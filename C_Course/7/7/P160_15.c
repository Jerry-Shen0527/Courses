#include<stdio.h>
#include<stdlib.h>

#define N 3

int people[N];

int main()
{
	int count = N;
	int now = 0;
	int alivecount = 0;

	while (count > 1)
	{
		

		if (people[now] == 0)
		{
			
			if (alivecount % 3 == 2)
			{
				people[now] = 1;
				count--;
			}
			alivecount++;
		}
		now = (now + 1) % N;
	}

	for (int i = 0; i < N; i++)
	{
		if (people[i]==0)
		{
			printf("%d", i + 1);
		}
	}

	system("pause");
}