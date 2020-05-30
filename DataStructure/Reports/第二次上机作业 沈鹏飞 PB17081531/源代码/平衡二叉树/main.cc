#include"bsst.hpp"
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
int ssize = 30;
void print(int i) { cerr << i<<' '; }
int main()
{

	srand(time(NULL));
	BssTree tree;
	ofstream file("D:\\1.txt");
	for (int i = 0; i < 2; i++) {
		for (int i = 0; i < ssize / 2; i++)
		{
			int temp=rand() % ssize;
			if (tree.insert(temp))
			{
				file << "adding " << temp << endl;
				tree.print(file);
				file << "--------------------------" << endl;
			}
		}
		for (int i = 0; i < 3 * ssize / 2; i++)
		{
			int temp = rand() % ssize;
			if (tree.remove(temp))
			{
				file << "removing " << temp << endl;
				tree.print(file);
				file << "--------------------------" << endl;
			}
		}
	}
}
