#include"phonebook.hpp"
#include<sstream>

PhoneBook::PhoneBook(int number) : size(number) {}

void PhoneBook::add(string line)
{
	istringstream temp(line);
	item new_item;
	temp >> new_item.name >> new_item.number;
	data.push_back(new_item);

}

void PhoneBook::remove(int index)
{
	if (index <= data.size() && index > 0)
		data.erase(data.begin() + index);
}

void PhoneBook::read(istream& in)
{
	string temp;

	item tempi;
	while (getline(in,temp))
	{
		istringstream temps(temp);
		temps >> tempi.name >> tempi.number;
		data.push_back(tempi);
	}
}

void PhoneBook::print(ostream&out)
{
	for (auto& c : data)
	{
		out << c.name << ' ' << c.number << endl;
	}
}

item& PhoneBook::find(int index)
{
	return data[index-1];
}

int PhoneBook::find_name(string name)
{
	int index = data.size() - 1;
	while (index >= 0 && data[index].name != name)
		index--;
	return index;
}

int PhoneBook::find_number(string num)
{
	int index = data.size() - 1;
	while (index >= 0 && data[index].number != num)
		index--;
	return index;
}

string PhoneBook::operator[](string name)
{
	int temp = 0;
	if((temp=find_name(name))>=0)
	return data[temp].number;
	else
	{
		return name + " not found.";
	}
}


