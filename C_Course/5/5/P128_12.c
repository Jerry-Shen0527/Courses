//#include<stdio.h>
//
//int a[5][5];
//int b[5][3] = { {3,0,16},{17,-6,9},{0,23,-4},{9,7,0},{4,13,11} };
//
//int buffer[10][10];
//
//int * matrix_mul(int A[][5], int B[][3], int A_row, int B_row, int B_col)
//{
//	for (int i = 0; i < A_row; i++)
//	{
//		for (int j = 0; j < B_col; j++)
//		{
//			for (int k = 0; k < B_row; k++)
//			{
//				buffer[i][j] += A[i][k] * B[k][j];
//			}
//		}
//	}
//	return buffer;//发生了一次类型的转换，直接传递了二维数组的起始地址，因此只需要解一次引用就能得到最终的结果
//}
//
//int main()
//{
//	for (int i = 0; i < 5*5; i++)
//	{
//		a[0][i] = i + 1;
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%5d", b[i][j]);
//		}
//		printf("\n");
//	}
//
//
//	int* temp = matrix_mul(a, b, 5, 5, 3);
//
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%4d", buffer[i][j]);
//		}
//		printf("\n");
//	}
//	//printf("%d", temp[1]);
//	getchar();
//}