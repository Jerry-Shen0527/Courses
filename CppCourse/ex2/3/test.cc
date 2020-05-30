#include"Rational.hpp"
#include<iostream>
using namespace std;
int main()
{
	Rational a(1, 3), b(1, 6), c(0, 1), d(0.618);
	cout << "a is 1/3,b is 1/6, c is 0, d is 0.618" << endl;
	cout << "Rational form of d(0.618) is " << d << endl;
	
	cout << "a+b= " << a + b << endl; 
	cout << "a-b= " << a - b << endl;
	cout << "a*b= " << a * b << endl;
	cout << "a/b= " << a / b << endl;

	cout << "a/c= " << a / c << endl;

}