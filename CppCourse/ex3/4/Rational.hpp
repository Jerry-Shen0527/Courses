
#ifndef RATIONAL
#define RATIONAL
#include<iostream>
#define PRICISION 6

class Rational
{
	friend std::ostream& operator<<(std::ostream& os, Rational output);
	friend Rational operator+(Rational lhs, Rational rhs);
	friend Rational operator-(Rational lhs, Rational rhs);
	friend Rational operator*(Rational lhs, Rational rhs);
	friend Rational operator/(Rational lhs, Rational rhs);
	friend Rational pow(Rational lhs, Rational rhs);
	friend std::istream& operator>>(std::istream& is, Rational& input);

public:
	Rational() :numerator(0), denominator(1) {}
	Rational(int a, int b) :numerator(a), denominator(b) { reduction(); if (b == 0) { std::cerr << "the denomitor cannot be 0! it's set to 1" << std::endl; denominator = 1; } }
	Rational(double);//会有一定大小的截断误差，目前设为6位精度
	
	Rational operator=(const Rational& rhs);
	Rational operator-() const;

	operator double() { return double(numerator) / denominator; }
private:
	int numerator;
	int denominator;
	void reduction();

};

std::istream& operator>>(std::istream& is, Rational& input);
std::ostream& operator<<(std::ostream& os,Rational output);
Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);



#endif