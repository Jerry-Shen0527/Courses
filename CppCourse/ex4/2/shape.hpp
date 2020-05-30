#include<cmath>
class Shape
{
public:

	virtual double area() { return 0; }
	virtual double perimeter() { return 0; }
	virtual void scale(double factor) {}

private:
};

class Circle:public Shape
{
public:
	Circle(double r = 0) :radius(r) {}

	double area() override;
	double perimeter() override;
	void scale(double factor) override;

private:
	double radius;

};

class Triangle :public Shape
{
public:

	Triangle(int x = 0, int y = 0, int z = 0) :a(x), b(y), c(z) {}

	double area() override;
	double perimeter() override;

private:
	int scale(int factor) {}
	int a, b, c;
};

class Rectangle :public Shape
{
public:
	Rectangle(double w = 0, double h = 0) :width(w), height(h) {  }

	double area() override;
	double perimeter() override;
	void scale(double factor) override;

private:
	double width,height;

};


#define PI 3.1415926535

double Circle::area()
{
	return PI * radius * radius;
}

double Circle::perimeter()
{
	return 2 * PI * radius;
}

void Circle::scale(double factor)
{
	radius *= factor;
}

double Triangle::area()
{
	double p = (a + b + c) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter()
{
	return a + b + c;
}

double Rectangle::area()
{
	return width * height;
}

double Rectangle::perimeter()
{
	return 2 * (width + height);
}

void Rectangle::scale(double factor)
{
	width *= factor;
	height *= factor;
}
