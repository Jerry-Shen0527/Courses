#include<stdio.h>
#include<stdlib.h>

#define N 100

#define swap(a,b) {int temp=a;a=b;b=temp;}

int arr[N];

int string_cmp(char *a, char *b)//表示严格大于
{
	int index = 0;
	while (a[index] && b[index])
	{
		if (a[index] > b[index])
		{
			return 1;
		}
		index++;
	}
	if (a[index])
	{
		return 1;
	}
	return 0;
}

void bubble_sort(char *a[])
{
	for ( int  i = 4; i >= 0; i--)
	{
		int max = a[i];
		int index = i;

		for (int j = i - 1; j >= 0; j--)
		{
			if (string_cmp(a[j],max))
			{
				max = a[j];
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
}


char buffer[5][100];

int main()
{
	
	char *ptr_char[5];

	for (int i = 0; i < 5; i++)
	{
		gets_s(buffer[i],100);
	}

	for (int i = 0; i < 5; i++)
	{
		ptr_char[i] = buffer[i];
	}

	bubble_sort(ptr_char);

	for (int j = 0; j < 5; j++)
	{
		printf("%s\n", ptr_char[j]);
	}

	system("pause");

}
