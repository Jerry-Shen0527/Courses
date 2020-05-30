#include"students.hpp"
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<Course> courses;
	vector<Student> students;

	courses.push_back(Course("C++",1,3));
	courses.push_back(Course("Data_Structure", 2, 3.5));
	courses.push_back(Course("Discretemath", 3, 3));
	courses.push_back(Course("Calculus", 4, 6));

	students.push_back(Student("Jerry", 1));
	students.push_back(Student("Mary", 2));
	students.push_back(Student("Lucy", 3));
	students.push_back(Student("Mike", 4));

	int temp;
	cout << "Student number: " << endl;
	while (cin>>temp)
	{
		if (temp == 0) break;
		for (auto& c : students)
		{
			if (c.get_number()==temp)
			{
				cout << "1.choose courses." << endl << "2.exit." << endl;
				while (cin>>temp)
				{
					
					if (temp == 2) break;
					else if (temp == 1)
					{
						for (auto& d : courses)
						{
							cout << "name: " << d.get_name() << " credit: " << d.get_credit() <<" course nember: "<< d.get_number() << endl;
						}

						cin >> temp;
						for (auto& d : courses)
						{
							if (temp == d.get_number()) c.choose(d);
						}
					}
					cout << "1.choose courses:" << endl << "2.exit" << endl;
				}
				temp = -1;
			}
		}
		cout << "Student number: " << endl;
	}
	
	cout << "The list of C++:" << endl;
	courses[0].print_list();
	cout << endl;
	cout<<"Jerry chose "<<students[0].credit()<<" credits of courses.";
}