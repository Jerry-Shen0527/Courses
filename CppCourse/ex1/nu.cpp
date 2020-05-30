#include <iostream>
#include <sstream>
#include <fstream>
#include<string>
using namespace std;

int main(int argc,char** argv)
{

	ifstream in("sun.txt");
	ofstream out("sun_with_nu.txt");
	
	string temp;
	
	int nu=0;
	int max_count=0;
	while(getline(in,temp))
	{
		out<<++nu<<' '<<temp<<endl;

		if(temp.size()>max_count)
			max_count=temp.size();
	}
	cout<<"The longest sentence have the length of "<<max_count<<" characters."<<endl;
	return 0;

}
