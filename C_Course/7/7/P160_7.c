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