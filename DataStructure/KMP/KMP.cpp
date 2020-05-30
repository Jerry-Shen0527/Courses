#include<iostream>
#define SIZE 100
using namespace std;

int index[SIZE];

void set_next(string& son);

int next(int i)
{
	return index[i];
}

bool compare(char a, char b)//为通配符定义新的比较函数
{
	if (a == '*' || b == '*' || a == b||abs(a-b)=='a'-'A')
		return true;
	return false;
}

int kmp_find(string& dad, string& son)
{
	set_next(son);
	int j = 0;
	for (int i = 0; i < dad.size();)
	{
		if (j == -1)
		{
			i++; j++;
		}
		if (compare(dad[i],son[j]))
		{
			i++; j++;
		}
		else
		{
			j = next(j);
		}
		if (j==son.size())
		{
			return i - son.size();
		}
	}
	return -1;//匹配失位则返回-1
}

void set_next(string& son)
{
	index[0] = -1;
	int i = 0, j = -1;
	while (i < son.size()-1)
	{
		if ((j == -1) || compare(son[i], son[j]))
		{
			i++; j++;
			if (!compare(son[i], son[j]))index[i] = j;
			else index[i] = j;

		}
		else
		{
			j = next(j);
		}
	}
}



int main()
{
	string a,b;
	cin >> a >> b;
	cout << kmp_find(a,b);
}