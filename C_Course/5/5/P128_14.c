//可以用KMP算法，不过此处从简
#include<stdio.h>

int find(char * s1, char* s2)
{

	int result = 0;
	int index = 0;
	while (s1[result] != 0)
	{
		while (s1[result+index]==s2[index])
		{
			index++;
			if (s2[index]==0)
			{
				return result;
			}
			if (s1[result + index] == 0)
			{
				return -1;
			}
		}

		result++;
		index = 0;
	}

	return -1;
}

int main()
{
	char buf1[100];
	char buf2[100];
	while (1) {
		scanf("%s", buf1);
		scanf("%s", buf2);

		printf("%d\n", find(buf1,buf2));
	}
	getchar();
}