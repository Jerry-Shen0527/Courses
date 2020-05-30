#include"Rational.hpp"

extern Rational pow(Rational lhs, Rational rhs)
{
	return Rational(std::pow(double(lhs.numerator) / lhs.denominator, double(rhs.numerator) / rhs.denominator));
}

int find_co(int a, int b)
{
	while (true)
	{
		a %= b;
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
	}
}

Rational::Rational(double in)
{
	numerator = (int)(in * std::pow(10, PRICISION));
	denominator = std::pow(10,PRICISION);
	reduction();
}

Rational Rational::operator=(const Rational& rhs)
{
	numerator = rhs.numerator;
	denominator = rhs.denominator;
	return *this;
}

Rational Rational::operator-() const
{
	return 0 - *this;
}

void Rational::reduction()
{
	int temp = find_co(numerator, denominator);
	numerator /= temp;
	denominator /= temp;
	if (denominator<0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}

std::istream& operator>>(std::istream& is, Rational& input)
{
	double temp;
	is >> temp;
	input = temp;
	return is;
}

std::ostream& operator<<(std::ostream& os, Rational output)
{
	if (output.denominator == 1)
	{
		os << output.numerator;
		return os;
	}
	os << output.numerator << '/' << output.denominator;
	return os;
}

Rational operator+(Rational lhs, Rational rhs)
{
	Rational temp;
	temp.numerator = lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator;
	temp.denominator = lhs.denominator * rhs.denominator;
	temp.reduction();
	return temp;
}

Rational operator-(Rational lhs, Rational rhs)
{
	Rational temp;
	temp.numerator = lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator;
	temp.denominator = lhs.denominator * rhs.denominator;
	temp.reduction();
	return temp;
}

Rational operator*(Rational lhs, Rational rhs)
{
	Rational temp;
	temp.denominator = lhs.denominator * rhs.denominator;
	temp.numerator = lhs.numerator * rhs.numerator;
	temp.reduction();
	return temp;
}

Rational operator/(Rational lhs, Rational rhs)
{
	Rational temp;
	if (rhs.numerator == 0) { std::cerr << "cannot be devided by 0! Replacing the answer with 0! " << std::endl; return Rational(); }
	temp.denominator = lhs.denominator * rhs.numerator;
	temp.numerator = lhs.numerator * rhs.denominator;
	temp.reduction();
	return temp;
}




