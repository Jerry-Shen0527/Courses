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
	for (int i = 0; i < 9; i++)//����Ϊ�˱����鷳�����־�Ҳ������������ˣ�ʵ��������ʹ����ȫ������������ϵͳ
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
	cout << "���������ͣ��������һ����СΪ20�ĵ绰�����м���һ������֪Ԫ�أ������������ų�ȡĳԪ�ز����"<<endl;
	cout << pb["Jerry"]<<endl;

	ifstream in("D:\\1.txt");
	PhoneBook newpb(50);
	newpb.read(in);

	cout << "���������ͣ��洢�����¶�ȡ�õ��Ľ��" << endl;
	cout << newpb["Jerry"] << endl;
	newpb.remove(newpb.find_name("Jerry"));
	cout << "ɾ��ָ��Ԫ�غ�ĵĽ����" << endl;
	cout << newpb["Jerry"] << endl;
	in.close();


}