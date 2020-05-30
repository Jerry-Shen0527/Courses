#include"1/int_stack.hpp"
#include<iostream>

#define DEBUG

using namespace std;
int main()
{
	IntStack a;
	cout <<"空栈："<<"是否为空:"<< a.empty() << ' '<<"大小：" << a.get_size() << ' ' << endl;
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	cout << "压入0到9后:" << "是否为空:" << a.empty() << ' ' << "大小：" << a.get_size() << ' ' << endl;
	cout <<"pop一次："<< a.pop()<<endl;//pop测试
	cout << "pop一次后:" << "是否为空:" << a.empty() << ' ' << "大小：" << a.get_size() << ' ' << endl;

	IntStack b = a;//拷贝初始化
	auto c = b = a;//还是拷贝初始化，移动初始化没什么好办法测试了
	c = c;
	cout << "拷贝至新栈后输出(经历过自赋值，安全):";
	c.print();
	return 0;
}