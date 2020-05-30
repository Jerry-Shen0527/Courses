#include"point.hpp"
#include<iostream>
using std::cout;
using std::endl;
int main()
{
	Point a(3, 4), b(1, 7);
	cout << "The distance of (3,4) to (0,0) is " << a.length() << endl;
	cout << "a.x:" << a.get_x() << " " << "a.y:" << a.get_y() << endl;
	cout << "The distance between a and b is " << a.distance(b) << endl;
	a.set_x(5);
	a.set_y(3);
	cout << "The new position of a is " << '(' << a.get_x() << '.' << a.get_y() << ')' << endl;
	return 0;
}