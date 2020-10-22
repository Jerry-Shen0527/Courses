#ifndef COMMON_FUNC
#define COMMON_FUNC

#define SIZE 20



void udf_strcpy(int n, char* source, char* destination)//����ǰд���ĺ�������������һ�½�����
{
	int overrun_flag = 0;
	int count = 0;
	while (source[count])
	{
		if (destination[n + count] == 0)
		{
			overrun_flag = 1;
		}
		destination[n + count] = source[count];
		count++;
	}
	if (overrun_flag)
	{
		destination[n + count] = 0;
	}
}

int string_cmp(char* a, char* b)//��ʾ�ϸ���ڣ�����ǰд���Ĵ���
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

int find(char* s1, char* s2)//������ǰд���Ĵ���
{

	int result = 0;
	int index = 0;
	while (s1[result] != 0)
	{
		while (s1[result + index] == s2[index])
		{
			index++;
			if (s2[index] == 0)
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

#endif // !COMMON_FUNC
