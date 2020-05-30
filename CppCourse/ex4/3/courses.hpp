#ifndef COURSES
#define COURSES

#include<string>
#include<set>
#include<iostream>

class Student;
class Course
{
public:
	Course(std::string na = "", int num = 0, unsigned cre = 0) :name(na), number(num), credit(cre), students{} {}
	~Course() {}

	const std::string& get_name() const { return name; }
	const int get_number() const { return number; }
	const unsigned get_credit() const { return credit; }

	void choose(Student& stu) { students.insert(&stu); }
	void print_list();

private:
	std::string name;
	int number;
	unsigned credit;
	
	std::set<Student*> students;
};

#endif // !COURSES