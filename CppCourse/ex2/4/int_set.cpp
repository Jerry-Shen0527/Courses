#include "int_set.hpp"

IntSet::IntSet(std::initializer_list<int> list) :IntSet()
{
	for (auto c = list.begin(); c != list.end(); c++)
	{
		push(*c);
	}
}


void IntSet::push(const int number, int index)
{
	if (number > 100 || number < 0)
	{
		std::cout << "out of size 0~100 when trying to push in " << number << "!" << std::endl;
		return;
	}
	else
	{
		Set::push(number);
	}
}
