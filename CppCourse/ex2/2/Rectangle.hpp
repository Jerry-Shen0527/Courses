#ifndef RECTANGLE
#define RECTANGLE
#include"../1/point.hpp"
#include<iostream>
using std::endl;
class Rectangle
{
public:
	Rectangle() = default;
	Rectangle(double x1, double y1, double x2, double y2) 
	{
		if (x1 >= x2 || y1 <= y2) 
		{ 
			std::cerr << "They are not the up-left and down-right coordinates!" << std::endl; 
			up_left.set_position(0, 1);
			down_right.set_position(1, 0);
		}
		else
		{
			up_left.set_position(x1, y1);
			down_right.set_position(x2, y2);
		}
	}
	void print_status() {
		std::cout << '(' << up_left.get_x() << ',' << up_left.get_y() << ')' << ',' << '(' << down_right.get_x() << ',' << up_left.get_y() << ')' << ',' <<
			'(' <<down_right.get_x() << ',' << down_right.get_y() << ')' << ',' <<
			'(' << up_left.get_x() << ',' << down_right.get_y() << ')' << endl;
	}
	double circular_length() const {return 2 * (down_right.get_x() - up_left.get_x() + up_left.get_y() - down_right.get_y());}
	double size() const { return (down_right.get_x() - up_left.get_x()) * (up_left.get_y() - down_right.get_y()); }
	void move(double x, double y) { down_right.set_position(down_right.get_x() + x, down_right.get_y() + y);
	up_left.set_position(up_left.get_x() + x, up_left.get_y() + y);
	}


	~Rectangle() = default;

private:

	Point up_left{ 0,1 };
	Point down_right{ 1,0 };
};

#endif