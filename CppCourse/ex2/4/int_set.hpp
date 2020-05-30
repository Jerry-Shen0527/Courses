#include"set.hpp"
using namespace set;
class IntSet:public Set<int>
{
public:
	IntSet() {}
	IntSet(std::initializer_list<int> list);
	

	void delete_number(int i) { int temp = find(i); if (temp != -1) pop(temp); }
	bool if_has(int i) { if (find(i) == -1) { return false; } return true; }
	virtual void push(const int number, int index = 0);

private:
};
