#ifndef POINT
#define POINT
#include<cmath>
class Point
{
public:
	Point() :x(0), y(0) {}
	Point(double x, double y) :x(x), y(y) {}
	~Point() {}
	double length() const { return sqrt(x * x + y * y); }
	double distance(const Point& rhs) const { return sqrt((x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y)); }
	double get_x() const { return x; }
	double get_y() const { return y; }

	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }
	void move_to(double x, double y) { this->x = x; this->y = y; }


private:
	double x;
	double y;
};

#endif