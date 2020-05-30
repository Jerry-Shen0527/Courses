#include<iostream>
#include"int_set.hpp"
using namespace std;
int main()
{
	IntSet a{ 1,2,3,4,5,6,7,8,9 }, b{ 2,3,5,7,11,13,17,19 };
	cout << "IntSet a is { 1,2,3,4,5,6,7,8,9 }, b is { 2,3,5,7,11,13,17,19 }" << endl;
	cout << "The union set is " << union_set(a, b) << endl;
	cout << "The inter set is " << inter_set(a, b) << endl;
	
	int temp = 0;
	cout << "Put in an iterger, is it in the Set b? " << endl;
	cin >> temp;
	if (b.if_has(temp)) cout << "Yes!" << endl;
	else cout << "No......" << endl;

	cout << "Put in an iterger, it will be pushed into b if possible. " << endl;
	cin >> temp;
	b.push(temp);

	cout << "The size of b now is " << b.size() << endl;
	
	cout << "Put in an iterger, it will be deleted from b if possible. " << endl;
	cin >> temp;
	b.delete_number(temp);

	cout << "Finally, b is " << b;

}