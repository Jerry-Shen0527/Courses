#include<iostream>
#include<vector>
#include<cstdlib>
#define SIZE 6
using namespace std;

int a[SIZE][SIZE]={0};
vector<vector<int> > b{0};


int random_bool();
template<typename T>
ostream& print_stream(ostream &out,T a);
template<typename T>
void is_even(T);
int main()
{
		for(int i=0;i<SIZE;i++)
				for(int j=0;j<SIZE;j++)
						a[i][j]=random_bool();
		vector<int>temp(0);
		for(int i=0;i<SIZE;i++)
		{
				for(int j=0;j<SIZE;j++)
						temp.push_back(random_bool());
				b.push_back(temp);
				temp.clear();
		}

		cout<<"Array version:"<<endl;
		print_stream(cout,a);
		is_even(a);
		cout<<endl;

		cout<<"Vector version:"<<endl;
		print_stream(cout,b);
		is_even(b);

		return 0;
}

int random_bool()
{
		return random()%2;
}

template<typename T>
ostream& print_stream(ostream &out,T a)
{
		for(int i=0;i<SIZE;i++)
		{
				for(int j=0;j<SIZE;j++)
						out<<a[i][j]<<' ';
				cout<<endl;
		}
		return out;
}

template<typename T>
void is_even(T a)
{
		for(int i=0;i<SIZE;i++)
		{
				int num=0;
				for(int j=0;j<SIZE;j++)
						if(a[i][j]==1) num++;
				if(num%2==0) cout<<"There are even number of 1s in the "<<i+1<<"th line."<<endl;
				else cout<<"There are odd number of 1s in the "<<i+1<<"th line."<<endl;
		}
		for(int i=0;i<SIZE;i++)
		{
				int num=0;
				for(int j=0;j<SIZE;j++)
						if(a[j][i]==1) num++;
				if(num%2==0) cout<<"There are even number of 1s in the "<<i+1<<"th colomn."<<endl;
				else cout<<"There are odd number of 1s in the "<<i+1<<"th colomn."<<endl;
		}
}
