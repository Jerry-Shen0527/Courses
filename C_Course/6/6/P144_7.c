//#include<stdio.h>
//#include<stdlib.h>
//
//int score[10][5] = { {1,2,3,4,5} };
//
//double buffer10[10];
//double buffer5[5];
//
//
//void ave_stu()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		double result = 0;
//
//		for (int j = 0; j < 5; j++)
//		{
//			result += score[i][j];
//		}
//		buffer10[i] = result / 5;
//	}
//}
//
//void ave_course()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		double result = 0;
//
//		for (int j = 0; j < 10; j++)
//		{
//			result += score[j][i];
//		}
//		buffer5[i] = result / 10;
//	}
//}
//
//void get_top(int *stu, int* course)
//{
//	int temp_score = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			if (score[i][j]>temp_score)
//			{
//				temp_score = score[i][j];
//				*stu = i;
//				*course = j;
//			}
//		}
//	}
//}
//
//double square_diff()
//{
//	double temp = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		temp += buffer10[i] * buffer10[i];
//	}
//
//	double temp2 = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		temp2 += buffer10[i];
//	}
//	temp2 /= 10;
//	temp2 *= temp2;
//	return (temp / 10) - temp2;
//
//}
//
//
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			score[j][i] = rand() % 100;
//			printf("%5d", score[j][i]);
//		}
//		printf("\n");
//	}
//
//	ave_stu();
//	ave_course();
//	int i, j;
//	get_top(&i, &j);
//
//	printf("The average on student is:\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%5.1lf", buffer10[i]);
//	}
//	printf("\n");
//
//
//	printf("The average on course is:\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%5.1lf", buffer5[i]);
//	}
//	printf("\n");
//
//	printf("The square difference on student is %10.1lf :\n",square_diff());
//
//	printf("\n");
//
//	printf("The highest score is at student %d on course %d", i, j);
//}