#include"line.hpp"
#include<iostream>
using namespace std;
int main()
{
	double x1, x2, x3, x4;
	cout << "Please put in the coordinates:";
	cin >> x1 >> x2 >> x3 >> x4;
	Line l(x1, x2, x3, x4);

	cout << "The original position: ";
	cout << '(' << l.get_a().get_x() << ',' << l.get_a().get_y() << "),(" << l.get_b().get_x() << ',' << l.get_b().get_y() << ')' << endl;
	l.move(1, 1);
	cout << "After moving (1,1): ";
	cout << '(' << l.get_a().get_x() << ',' << l.get_a().get_y() << "),(" << l.get_b().get_x() << ',' << l.get_b().get_y() << ')' << endl;
	cout <<"The length: "<< l.length()<<endl;
	return 0;
}