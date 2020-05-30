#include"point.hpp"
class Line
{
public:
	
	Line(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) :a(x1, y1), b(x2, y2) {}

	void move(double x, double y) {
		a.move_to(a.get_x() + x, a.get_y() + y); b.move_to(b.get_x() + x, b.get_y() + y);
	}

	double length() const { return a.distance(b); }

	const Point& get_a() const { return a; }
	const Point& get_b() const { return b; }

private:
	Point a;
	Point b;
};
