#include"Rectangle.hpp"
#include<iostream>
using std::cout;
using std::endl;
int main()
{
	Rectangle a;
	cout << "The default status is ";
	a.print_status();
	Rectangle b(1, 3, 7, -5);
	cout << "Another rectangle B is ";
	b.print_status();
	cout << "The circular length of B is " << b.circular_length() << endl;
	cout << "The size of B is " << b.size() << endl;
	b.move(1, 3);
	cout << "After moving, B is ";
	b.print_status();
}