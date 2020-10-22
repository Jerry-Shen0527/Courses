#include<stdio.h>
#include<stdlib.h>

#define N 100

#define swap(a,b) {int temp=a;a=b;b=temp;}

int arr[N];



void bubble_sort(int * a)
{
	for ( int  i = 0; i < N; i++)
	{
		int max = a[i];
		int index = i;
		for (int j = i+1; j < N; j++)
		{
			if (a[j] > max)
			{
				max = a[j];
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % N;
	}

	bubble_sort(arr);

	for (int i = 0; i < N; i++)
	{
		printf("%4d", arr[i]);
		if (i % 10 == 9)
		{
			printf("\n");
		}
	}

	system("pause");
}
