#include"queue.hpp"
#include<iostream>
#include"queue.hpp"

using namespace std;

int main()
{
	Queue<int> a;
	cout << "空列：" << endl;
	cout << "所占空间长度：" << a.get_length() << endl;
	cout << "列长：" << a.get_size() << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		a.enqueue(i);
	}

	cout << "将0到9加入队列后：" << endl;
	cout << "所占空间长度：" << a.get_length()<<endl;
	cout << "列长：" << a.get_size()<<endl;

	auto b = a;
	b = b;

	cout << "拷贝并自赋值后的队列" << endl;
	cout << "所占空间长度：" << b.get_length() << endl;
	cout << "列长：" << b.get_size() << endl;

	cout << "将被拷贝的队列出队：" << endl;
	while (b.get_size()>0)
	{
		cout << b.dequeue()<<' ';
	}
	cout << endl;

	cout << "将原队列出队：" << endl;
	while (a.get_size() > 0)
	{
		cout << a.dequeue() << ' ';
	}
	cout << endl;
	
}