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

	vector<int> element; //使用vector不会有栈容量的问题。按照C++设计者的建议应该多使用标准库，就不再自己写顺序栈了，也就不实现栈容量翻倍的操作了
	size_t size;

};




#endif