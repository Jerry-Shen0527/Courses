#include"queue.hpp"
#include<iostream>
#include"queue.hpp"

using namespace std;

int main()
{
	Queue<int> a;
	cout << "���У�" << endl;
	cout << "��ռ�ռ䳤�ȣ�" << a.get_length() << endl;
	cout << "�г���" << a.get_size() << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		a.enqueue(i);
	}

	cout << "��0��9������к�" << endl;
	cout << "��ռ�ռ䳤�ȣ�" << a.get_length()<<endl;
	cout << "�г���" << a.get_size()<<endl;

	auto b = a;
	b = b;

	cout << "�������Ը�ֵ��Ķ���" << endl;
	cout << "��ռ�ռ䳤�ȣ�" << b.get_length() << endl;
	cout << "�г���" << b.get_size() << endl;

	cout << "���������Ķ��г��ӣ�" << endl;
	while (b.get_size()>0)
	{
		cout << b.dequeue()<<' ';
	}
	cout << endl;

	cout << "��ԭ���г��ӣ�" << endl;
	while (a.get_size() > 0)
	{
		cout << a.dequeue() << ' ';
	}
	cout << endl;
	
}