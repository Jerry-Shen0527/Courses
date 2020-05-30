#include"phonebook.hpp"
#include<fstream>
#include<sstream>
#include<ctime>

int main()
{
	ofstream out("D:\\1.txt");
	PhoneBook pb(100);
	char buffer[20];
	ostringstream temp;
	for (int i = 0; i < 9; i++)//这里为了避免麻烦，名字就也用随机数代替了，实际如果真的使用完全可以设置输入系统
	{
		temp.str("");
		temp << rand() << ' ' << rand();
		pb.add(temp.str());
	}
	
	pb.add("Jerry 1234567");
	for (int i = 0; i < 10; i++)
	{
		temp.str("");
		temp << rand() << ' ' << rand();
		pb.add(temp.str());
	}
	pb.print(out);
	out.close();
	cout << "输出结果解释：随机建立一个大小为20的电话本，中间有一项是已知元素，从中用中括号抽取某元素并输出"<<endl;
	cout << pb["Jerry"]<<endl;

	ifstream in("D:\\1.txt");
	PhoneBook newpb(50);
	newpb.read(in);

	cout << "输出结果解释：存储后重新读取得到的结果" << endl;
	cout << newpb["Jerry"] << endl;
	newpb.remove(newpb.find_name("Jerry"));
	cout << "删除指定元素后的的结果：" << endl;
	cout << newpb["Jerry"] << endl;
	in.close();


}