#ifndef STUDENTS
#define STUDENTS


#include"courses.hpp"
class Student
{
public:
	Student(std::string na, int num) :name(na), number(num), courses{} {}
	~Student() {}

	const std::string& get_name() const { return name; }
	const int get_number() const { return number; }

	void choose(Course& course) { course.choose(*this); courses.insert(&course); }
	int credit() { int temp = 0; for (auto& c : courses)temp += c->get_credit(); return temp; }

private:
	std::string name;
	int number;
	std::set<Course*> courses;
};


#endif // !STUDENTS