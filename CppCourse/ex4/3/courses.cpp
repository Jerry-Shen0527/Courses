#include"students.hpp"
#include"courses.hpp"
void Course::print_list()
{
	for (auto& c : students) std::cout << c->get_name() << ' ';
}