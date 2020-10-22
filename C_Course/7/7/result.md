
```C
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

```


```C
#include<stdio.h>
#include<stdlib.h>

#define N 100

#define swap(a,b) {int temp=a;a=b;b=temp;}

int mat[4][4];

void transpose(int (*p)[4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			swap(p[i][j], p[j][i]);
		}

	}
}

int main()
{
	for (int i = 0; i < 16; i++)
	{
		scanf_s("%d", (*mat) + i);
	}

	transpose(mat);

	for (int i = 0; i < 16; i++)
	{
		printf("%4d", (*mat)[i]);
		if (i % 4 == 3)
		{
			printf("\n");
		}
	}

	system("pause");
}
```


```C
#include<stdio.h>
#include<stdlib.h>

char buffer[200];


void udf_strcpy(int n, char* source, char* destination)//无法检查是否超过了目标的长度空间限制，所以只能尽可能设大一点
{
	int overrun_flag = 0;
	int count = 0;
	while (source[count])
	{
		if (!destination[count])
		{
			overrun_flag = 1;
		}
		destination[n + count] = source[count];
		count++;
	}
	if (overrun_flag)
	{
		destination[count] = 0;
	}
}

int main()
{
	char str[] = "Why am I still doing this stupid job?";

	char str2[] = "Because you were too careless in Grade 1!";

	udf_strcpy(0, str2, buffer);

	udf_strcpy(0, str, buffer);

	printf("%s", buffer);
	system("pause");
}
```


```C
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

```


```C
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
```


```C
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
```

