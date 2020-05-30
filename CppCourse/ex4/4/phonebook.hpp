#ifndef PB
#define PB
#include<vector>
#include<iostream>
using namespace std;

struct item
{
	string name;
	string number;
};

class PhoneBook
{
public:
	PhoneBook(int number);

	void add(string line);
	void remove(int index);
	void read(istream&);
	void print(ostream&);

	item& find(int index);
	int find_name(string name);
	int find_number(string num);

	string operator[](string name);

private:
	size_t size;
	vector<item> data;
};



#endif // !PB