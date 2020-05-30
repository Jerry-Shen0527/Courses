#include"Rational.hpp"
#include<iostream>
using namespace std;
int main()
{
	Rational r1;
	Rational r2(1, 2);
	Rational r3(-2, 3);
	Rational r4(1.5);
	cin >> r1;
	cout << r2 << endl;
	cout << -r1 << endl;
	cout << r1 + r3 << endl;
	r4 = r1 / r2;
	double d;
	d = r4;
	cout << d;


}