#ifndef INT_STACK
#define INT_STACK

#define DEBUG
#include<vector>
using std::vector;

#ifdef DEBUG
#include<iostream>
using namespace std;
#endif // DEBUG


class IntStack
{
public:
	IntStack() :size(0), element(0) {}
	~IntStack();


	IntStack(IntStack&);
	IntStack(IntStack&&) noexcept;
	IntStack& operator=(IntStack);

	void push(int num);
	int pop();
	bool empty();
	size_t get_size();

#ifdef DEBUG
	void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << element[i];
		}
	}
#endif // DEBUG


private:

	vector<int> element; //ʹ��vector������ջ���������⡣����C++����ߵĽ���Ӧ�ö�ʹ�ñ�׼�⣬�Ͳ����Լ�д˳��ջ�ˣ�Ҳ�Ͳ�ʵ��ջ���������Ĳ�����
	size_t size;

};




#endif