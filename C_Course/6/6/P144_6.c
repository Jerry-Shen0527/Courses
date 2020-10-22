//#include<stdio.h>
//
//int count(char str[], int rule(char))
//{
//	int i = 0;
//	int result = 0;
//	while (str[i])
//	{
//		if (rule(str[i]))
//		{
//			++result;
//		}
//		++i;
//	}
//	return result;
//}
//
//
//int character(char c)
//{
//	return ((c <= 'z'&&c >= 'a') || (c <= 'Z'&&c >= 'A'));
//}
//int digit(char c)
//{
//	return (c <= '9'&&c >= '0');
//}
//
//int space(char c)
//{
//	return c == ' ';
//}
//
//int others(char c)
//{
//	return !character(c) && !digit(c) && !space(c);
//}
//
//int main()
//{
//	char str[200];
//
//	gets(str);
//
//	printf("character:%d\n", count(str, character));
//	printf("digit:%d\n", count(str, digit));
//	printf("others:%d\n", count(str, others));
//	printf("space:%d\n", count(str, space));
//
//}