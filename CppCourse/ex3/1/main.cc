#include"1/int_stack.hpp"
#include<iostream>

#define DEBUG

using namespace std;
int main()
{
	IntStack a;
	cout <<"��ջ��"<<"�Ƿ�Ϊ��:"<< a.empty() << ' '<<"��С��" << a.get_size() << ' ' << endl;
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	cout << "ѹ��0��9��:" << "�Ƿ�Ϊ��:" << a.empty() << ' ' << "��С��" << a.get_size() << ' ' << endl;
	cout <<"popһ�Σ�"<< a.pop()<<endl;//pop����
	cout << "popһ�κ�:" << "�Ƿ�Ϊ��:" << a.empty() << ' ' << "��С��" << a.get_size() << ' ' << endl;

	IntStack b = a;//������ʼ��
	auto c = b = a;//���ǿ�����ʼ�����ƶ���ʼ��ûʲô�ð취������
	c = c;
	cout << "��������ջ�����(�������Ը�ֵ����ȫ):";
	c.print();
	return 0;
}