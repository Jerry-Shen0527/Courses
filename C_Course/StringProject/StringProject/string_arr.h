#ifndef STRARR
#define STRARR

#include<stdio.h>
#include<stdlib.h>
#include"common_func.h"

extern char buffer[SIZE][100] = { 0 };
int count = 1;

int find_pos()
{
	int storage = 1;
	while (buffer[storage][0] != 0)
	{
		storage++;
		if (storage > SIZE)
		{
			printf("No more buffer!\n");
			storage = 0;
			break;
		}
	}
	return storage;
}

int check_index(int index)
{
	if (index < 1 || index >= SIZE)
	{
		printf("Out of bound!");
		return 1;
	}
	else
	{
		return 0;
	}
}

int string_read()
{
	gets(buffer[find_pos()]);
}

int string_print(int index)//noexcept
{
	if (check_index(index))
		return 0;
	printf("%s\n", buffer[index]);
}

int string_len(int index)//3
{
	if (check_index(index))
		return 0;
	int count = 0;
	while (buffer[index][count]) count++;
	return count;
}


void string_insert(int index, int index2, int pos)
{
	if (check_index(index))
		return;
	if (check_index(index2))
		return;

	int storage = find_pos();

	udf_strcpy(0, buffer[index], buffer[storage]);
	udf_strcpy(pos, buffer[index2], buffer[storage]);

	string_print(storage);
	printf("Result saved at %d\n", storage);
}

void string_cat(int index, int index2)
{
	if (check_index(index)) return;
	if (check_index(index2)) return;
	string_insert(index, index2, string_len(index));
}


int string_compare(int index1, int index2)//再把以前的代码包裹一下用
{
	if (check_index(index1)) return 0;
	if (check_index(index2)) return 0;

	if (string_cmp(buffer[index1], buffer[index2]))
	{
		printf("%d is bigger than %d!\n", index1, index2);
	}
	else if (string_cmp(buffer[index2], buffer[index1]))
	{
		printf("%d is bigger than %d!\n", index2, index1);
	}
	else
	{
		printf("%d is the same to %d!\n", index2, index1);
	}
}

int string_cpy(int index, int index2)
{
	if (check_index(index2))return 0;
	if (check_index(index))	return 0;
	int storage = index2;
	udf_strcpy(0, buffer[index], buffer[storage]);
	printf("Result saved at %d\n", storage);
}

int string_sub(int index, int pos, int n)
{
	if (check_index(index))		return 0;

	int storage = find_pos();

	udf_strcpy(0, buffer[index] + pos, buffer[storage]);
	buffer[storage][n] = 0;//截断一下
	printf("Result saved at %d\n", storage);
	string_print(storage);

}


int string_find_sub(int index, int index2)
{
	if (check_index(index))		return 0;

	if (check_index(index2))
		return 0;

	return find(buffer[index], buffer[index2]);
}


void string_print_all()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (buffer[i][0])
		{
			printf("%d %s\n", i, buffer[i]);
		}
	}
	printf("\n");
}


#endif // !STRARR
