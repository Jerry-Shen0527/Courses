#include"int_stack.hpp"
#include<iostream>
IntStack::~IntStack()
{
}
IntStack::IntStack(IntStack& new_stack)
{
	size = new_stack.size;
	element = new_stack.element;
}

IntStack::IntStack(IntStack&& rnew_stack) noexcept
{
#ifdef DEBUG
	cout << "Move construct function is called" << endl;
#endif // DEBUG

	size = rnew_stack.size;
	element = std::move(rnew_stack.element);//建议编译器用右值的vector拷贝
}

IntStack& IntStack::operator=(IntStack new_stack)
{
	std::swap(this->element, new_stack.element);//swap肯定对vector做了优化
	std::swap(this->size, new_stack.size);
	return *this;
}

void IntStack::push(int num)
{
	size++;
	element.push_back(num);
}

int IntStack::pop()
{
	if (size == 0) std::cerr << "Popping an empty stack!" << std::endl;
	size--;
	int temp = element[size];
	element.pop_back();
	return temp;
}

bool IntStack::empty()
{
	return !size;
}

size_t IntStack::get_size()
{
	return size;
}

