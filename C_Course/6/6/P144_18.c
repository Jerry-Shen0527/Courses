//#include<stdio.h>
//
//
//char buffer[200];
////#define CIPHER
//
//#ifdef CIPHER
//
//void print(char str[])
//{
//	printf("%s", str);
//}
//
//#else
//
//void print(char str[])
//{
//	int i = 0;
//	while (str[i] != 0)
//	{
//		if (str[i] < 'z' && str[i] >= 'a')
//		{
//			buffer[i] = str[i] + 1;
//		}
//		else if(str[i]=='z')
//		{
//			buffer[i] = 'a';
//		}
//		else
//		{
//			buffer[i] = str[i];
//		}
//		i++;
//	}
//	printf("%s", buffer);
//}
//
//
//#endif
//
//
//
//int main()
//{
//	print("C language is a fragile hammer!");
//}