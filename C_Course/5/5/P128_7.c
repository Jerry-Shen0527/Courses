//#include<stdio.h>
//
//#define N 200
//
//char buffer[N];
//
//char* udf_strcat(char* s1, char* s2)
//{
//	int	index = 0;
//	while (s1[index] != 0 && index < N)
//	{
//		buffer[index] = s1[index];
//		index++;
//	}
//
//	int i = 0;
//
//	while( s2[i] != 0 && index + i < N)
//	{
//		buffer[index + i] = s2[i];
//		i++;
//	}
//
//	buffer[index + i + 1] = 0;
//	return buffer;
//}
//
//int main()
//{
//	char s1[] = "Hjiofjewiwoello ";
//	char s2[] = "World!";
//
//	printf("%s", udf_strcat(s1, s2));
//
//	getchar();
//
//}