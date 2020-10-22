//#include<stdio.h>
//
////此代码用vs编译会出现神奇的错误，应该是因为scanf_s对内存泄漏的检查更加严格，放在Debian下编译可以通过
//
////The input should be:
////61 62ab3.56 -6.78
////3157.891012,0.123456789,50000,-60000,32768,4000
//
//int main()
//{
//	int a, b;
//	char c1, c2;
//	float d, e;
//	double f, g;
//	long m, n;
//	unsigned int p, q;
//
//	scanf("%d%d%c%c%f%f", &a,&b,&c1,&c2,&d,&e);
//	scanf("%lf,%lf,%ld,%ld,%u,%u",&f,&g,&m,&n,&p,&q);
//
//	printf("sizeof:%d,a=%d,b=%d\n", sizeof(int), a, b);
//	printf("sizeof:%d,c1=%c,c2=%c\n", sizeof(char), c1, c2);
//	printf("sizeof:%d,d=%-6.2f,e=%-6.2f\n", sizeof(float), d, e);
//	printf("sizeof:%d,f=%-15.6f,g=%-15.12f\n", sizeof(double),f ,g );
//	printf("sizeof:%d,m=%ld,n=%ld\n", sizeof(long),m ,n );
//	printf("sizeof:%d,p=%u,q=%u\n", sizeof(unsigned),p ,q );
//	
//}