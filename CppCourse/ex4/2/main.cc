#include"shape.hpp"
#include<iostream>
using namespace std;

int main()
{
	Shape* ptr = nullptr;
	Rectangle rect(3,5);
	Triangle tri(3,4,5);
	Circle cir(4);

	ptr = &rect;
	cout << "The perimeter of the rectangle is " << ptr->perimeter()<<endl;
	cout << "The area of the rectangle is " << ptr->area()<<endl;
	ptr->scale(2);
	cout << "After scaling: "<<endl;
	cout << "The perimeter of the rectangle is " << ptr->perimeter() << endl;
	cout << "The area of the rectangle is " << ptr->area() << endl<<endl;

	ptr = &tri;
	cout << "The perimeter of the triangle is " << ptr->perimeter() << endl;
	cout << "The area of the triangle is " << ptr->area() << endl;
	ptr->scale(2);
	cout << "After scaling: " << endl;
	cout << "The perimeter of the triangle is " << ptr->perimeter() << endl;
	cout << "The area of the triangle is " << ptr->area() << endl << endl;

	ptr = &cir;
	cout << "The perimeter of the circle is " << ptr->perimeter() << endl;
	cout << "The area of the circle is " << ptr->area() << endl;
	ptr->scale(2);
	cout << "After scaling: " << endl;
	cout << "The perimeter of the circle is " << ptr->perimeter() << endl;
	cout << "The area of the circle is " << ptr->area() << endl;
}