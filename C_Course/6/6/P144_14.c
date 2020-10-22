//#include<stdio.h>
//#include<math.h>
//
//char buffer[200];
//
//double my_atof(char str[])
//{
//	int result = 0;
//	int i = 0;
//	int minus_flag = 0;
//	int point_flag = 0;
//	double expo = 0;
//
//	while (str[i]!=0)
//	{
//		if (str[i]=='-')
//		{
//			minus_flag = 1;
//		}
//
//
//		if (str[i] == 'e' || str[i] == 'E')//if的上下文不能改
//		{
//			expo += my_atof(str + i + 1);//递归调用
//			break;
//		}
//		if (point_flag)
//		{
//			--expo;
//		}
//		if (str[i]<='9'&&str[i]>='0')
//		{
//			result *= 10;
//			result += str[i] - '0';
//		}
//		else if (str[i] == '.')
//		{
//			point_flag = 1;
//		}
//		
//		i++;
//	}
//
//	if (minus_flag)
//	{
//		result = -result;
//	}
//	return result * pow(10, expo);
//}
//
//int main()
//{
//	gets(buffer);
//
//	printf("%lf", my_atof(buffer));
//
//}